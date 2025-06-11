/*
CSCI235 Fall 2023
KeunSub Lee
Project 6 - Tavern Class 
June 20 2023
Taven.cpp declares the Tavern class along with its private and public members
bool lhs rhs comparison functions for lvl and hp for sorting characters in create combat queue,
create turn based combat for the main character and enemies:
create and set main character, create combat queue of enemies from a csv file that can be sorted by asc/dec level or HP, enemy turn function that randomly chooses an action for the enemy and prints actions, create action queue for main character using action selection function that gets input from player and pushes to action queue, turn resolution function that applies buffs and actions of main character and prints actions, and combat function that calls action selection, turn resolution and enemry turn and ends when main character dies or all enemies are defeated
*/
#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}  {}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
Tavern::Tavern(const std::string& filename)
{ std::ifstream fin(filename);
  std::string line;
  std::getline(fin, line);
  std::string name, race, string_vitality, string_armor, string_level, string_enemy;
  int vitality, armor, level;
  bool enemy;
  
  while(std::getline(fin, line))
  {
    std::istringstream iss(line);
    std::getline(iss, name, ',');
    std::getline(iss, race, ',');

    std::getline(iss, string_vitality, ',');
    std::istringstream(string_vitality) >> vitality;

    std::getline(iss, string_armor, ',');
    std::istringstream(string_armor) >> armor;

    std::getline(iss, string_level, ',');
    std::istringstream(string_level) >> level;

    std::getline(iss, string_enemy, ',');
    std::istringstream(string_enemy) >> enemy;
    Character* character = new Character(name, race, vitality, armor, level, enemy);
    enterTavern(character);
  }
}

/**
  @param: a Character pointer 
  @post: sets the Tavern's main character to the pointer that is given
*/
  void Tavern::setMainCharacter(Character* mainchar){
    main_character_ = mainchar;
  }

  //  @return: a pointer to the main character in the Tavern, nullptr if there is no main character
Character* Tavern::getMainCharacter()     const     {
    // if (main_character_ == nullptr){     //not needed
    //   return nullptr;
    // }
    // else
    return main_character_;
  }
  /**
  @param: two Character pointers
  @return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(Character* char_a, Character* char_b)  {
    return char_a->getLevel() < char_b->getLevel();
  }
  /**
  @param: two Character pointers
  @return: true if the lhs Character's level is greater than the rhs Character's level
*/
bool Tavern::levelIsGreater(Character* char_a, Character* char_b) {
    return char_a->getLevel() > char_b->getLevel();
  }
  /**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is less than the rhs Character's vitality*/
bool Tavern::vitalityIsLess(Character* char_a, Character* char_b) {
    return char_a->getVitality() < char_b->getVitality();
  }
  /**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(Character* char_a, Character* char_b)  {
    return char_a->getVitality() > char_b->getVitality();
  }
  /**
  @post   : returns a pointer to the Character at the front of the Combat Queue. 
          : If there are no characters in the queue, return nullptr
*/
Character * Tavern::getTarget() {   //get * target in queue structure for combat
    if (combat_queue_.size() == 0){
      return nullptr;
    }
    else
    return combat_queue_.front();
  }


/**
  @pre  : The combat queue should be emptied before the characters are added to the queue
  @param  : A string reference to a sorting filter with a default value of "NONE"
  @post   : With default filter "NONE": add every character marked as an enemy to the combat queue
    : With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
    : With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
    : With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
    : With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
void Tavern::createCombatQueue(const std::string & queuestring ) {
    // pop all in queue before add 
    while (!combat_queue_.empty()) {
        combat_queue_.pop();
    }
  std::vector <Character*> enemies = toVector(); //vector for sorting
    // for (int i = 0; i < item_count_; i++) {
    //       enemies.push_back(items_[i])  ; } 
    if (queuestring == "LVLASC") {  //sort vector according to input filter level ascending order
        std::sort(enemies.begin(), enemies.end(), [this](Character * lhs, Character * rhs)
        { return levelIsLess(lhs, rhs);}  ) ;    //lambda function using levelIsLess
        }
    else if (queuestring == "LVLDES") {//sort vector according to input filter level desc
        std::sort(enemies.begin(), enemies.end(), [this](Character * lhs, Character * rhs){
          return levelIsGreater(lhs, rhs); } );   }
    else if (queuestring == "HPASC") { //sort vector according to input filter hp ascending
        std::sort(enemies.begin(), enemies.end(), [this](Character * lhs, Character * rhs){
          return vitalityIsLess(lhs, rhs);});   }
    else if (queuestring == "HPDES") { //sort vector according to input filter hp desc
        std::sort(enemies.begin(), enemies.end(), [this](Character * lhs, Character * rhs){
          return vitalityIsGreater(lhs, rhs) ; } ) ;    }

    //push sorted vector items into combat queue
    for (int i=0; i<enemies.size(); i++){
      if (enemies[i] != nullptr && enemies[i] ->isEnemy())
      {combat_queue_.push(enemies[i]);}
    }
}

/**
  @post : Prints the details of each character in the combat queue in the following form:
         (ENEMY)[ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue()  {
  std::queue<Character*> tempqueue = combat_queue_; //copy queue to print without popping original
  while (!tempqueue.empty()){ 
    Character* enemy = tempqueue.front();
      std::cout<<"(ENEMY) "   
      <<enemy->getName()
      <<": LEVEL "<<enemy->getLevel()
      <<" "<<enemy->getRace()
      <<". \nVITALITY: "<<enemy->getVitality()
      <<" \nARMOR: "<<enemy->getArmor()
      <<std::endl<<std::endl;
      tempqueue.pop();
      }
}

 /**
        @param  : A pointer to the enemy
        @post   : Do all of the following:
                : 1. If the enemy's buff stack is not empty, apply buff once and decrement the
                  turns. Any time a Buff's turns_ goes to zero, it is removed
                  from the stack. Print out the results of the action as described below.
                : 2. Pick a random Action 
                    (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
                : If the selected action is a buff, apply once immediately and add it to the 
                  enemy's buff stack, performing the necessary turns update. 
                  Print out the results of the action as described below.
                : If the selected action is an attack, execute it against the main character.
                  Print out the results of the action as described below. 
                : More details:
                
                : After applying each action, print out the results of the action as follows:
                : [ENEMY NAME] used [ACTION NAME]!
                : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
                : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/
void Tavern::enemyTurn (Character * enemy) {
  std::cout<<"ENEMY TURN\n";
    if (!enemy->buff_stack_.empty()){ //handle buffs before actions

      if (enemy->buff_stack_.top().name_=="BUFF_Heal"){   //get top of buff stack name
      enemy->heal();                                //apply buff, -- turns
      enemy->buff_stack_.top().turns_--;            
      
        if (enemy->buff_stack_.top().turns_ == 0){    //buff expires, pop from stack
        enemy->buff_stack_.pop();}
        enemyactionprint(1); }                        //print action heal

      else if (enemy->buff_stack_.top().name_=="BUFF_MendMetal"){
      enemy->mendMetal(); 
      enemy->buff_stack_.top().turns_--;

        if (enemy->buff_stack_.top().turns_ == 0){
        enemy->buff_stack_.pop();}
        enemyactionprint(2); 
      }
    }  
                
 /*: 2. Pick a random Action 
        (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
    : If the selected action is a buff, apply once immediately and add it to the 
      enemy's buff stack, performing the necessary turns update. 
      Print out the results of the action as described below.
    : If the selected action is an attack, execute it against the main character.
      Print out the results of the action as described below. 
    : More details:*/
    //srand(time(NULL));  no seeding
  int action = rand() % 4 + 1;  //random # 1-4
  if (action == 1){             //1==heal. apply/do action, make buff struct item, push to stack, print action
    enemy->heal();
    Buff buffheal = {"BUFF_Heal", 2};
    enemy->buff_stack_.push(buffheal); 
    enemyactionprint(1);
  }

  else if (action ==2 ){
    enemy->mendMetal();
    Buff buffmend = {"BUFF_MendMetal", 1};
    enemy->buff_stack_.push(buffmend); 
    enemyactionprint(2);
  }

  else if (action == 3){    //3==strike, do action to main char, print action
    enemy->strike(getMainCharacter());
    enemyactionprint(3);
  }

  else if (action == 4){
    enemy->throwTomato(getMainCharacter());
    enemyactionprint(4);
  }
}

/* : After applying each action, print out the results of the action as follows:
    : [ENEMY NAME] used [ACTION NAME]!
    : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
    : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/
void Tavern::enemyactionprint(const int a){
  std::string act = "";    //# corresponds to action for different print statements
  if      (a ==1){act= "Heal";}
  else if (a ==2){act= "MendMetal";}
  else if (a ==3){act= "Strike";}
  else if (a ==4){act= "ThrowTomato";}
  Character * enemy = combat_queue_.front();
  //try main character NAME
  std::cout<<enemy->getName()<<" used "<<act<<"!\n";
  std::cout<<"(ENEMY) "<<enemy->getName()<<": LEVEL "<<enemy->getLevel()<<" "<<enemy->getRace()
  <<". \nVITALITY: "<<enemy->getVitality()<<" \nARMOR: "<<enemy->getArmor()<<std::endl;
  std::cout<<"\n(YOU) "<<main_character_->getName()<<": LEVEL "<<main_character_->getLevel()<<" "<<getMainCharacter()->getRace()<<". \nVITALITY: "<<main_character_->getVitality()<<" \nARMOR: "<<main_character_->getArmor()<<std::endl<<"END OF ENEMY TURN\n\n";
}

 
    // (ENEMY)[ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

/** 
        @post : If there are no enemies in the combat queue, do nothing.
              : Otherwise do all of the following
              :     - The action queue must be emptied before the new actions are added.
              :     - Print out the start of turn and details of the target enemy in the form:
                      : YOUR TURN\n
                      : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 
    
              :     - Repeat the following process thrice (i.e. read three actions from input): 
              :           - Print the actions that are available to the main character, and read 
                            a non-negative number from input, corresponding to an action. 
                            Printing the available options should be of the following form. 
                            You may consider writing a helper function for this.
                            :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n

              :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                          keep prompting for a non-negative number that is within range, by
                          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n".
              :           - When a valid action is read, 
                          it is added to the main character's action queue.    
*/ //std::queue<int> action_queue_;

  void Tavern::actionSelection() {
    if (combat_queue_.size() == 0){
      return;
    }
    else{
      std::cout<<"YOUR TURN\n"
      <<"(ENEMY) "<<combat_queue_.front()->getName()
      <<": LEVEL "<<combat_queue_.front()->getLevel()
      <<" "<<combat_queue_.front()->getRace()<<". \nVITALITY: "
      <<combat_queue_.front()->getVitality()<<" \nARMOR: "
      <<combat_queue_.front()->getArmor()<<"\n\n";
      
      for (int i = 0; i < 3; i++){    //three times
            add_action();
      }
    }
  }

void Tavern::add_action(){    //input action to action queue
      std::cout<<"Choose an action(1-4):\n"
      <<"1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n";
      int action;
      std::cin>>action;
  /*              
:   - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
      keep prompting for a non-negative number that is within range, by
      printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n".
      - When a valid action is read, it is added to the main character's action queue.*/
  while (action < 1 || action > 4){
        std::cout<<"Invalid input. Please enter a number between 1 and 4 inclusive.\n"<<std::endl;
        std::cin>>action;  
      }   //std::queue<int> action_queue_ 

     Character *main = getMainCharacter();
      if (action == 1){
        main ->action_queue_.push(0);
      }
      else if (action == 2){
        main ->action_queue_.push(1);
      }
      else if (action == 3){
        main ->action_queue_.push(2);
      }
      else if (action == 4){
        main ->action_queue_.push(3);
}
}

/* After applying each action, print out the results of the action as follows:
  : [MAINCHARACTER NAME] used [ACTION NAME]!
  : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n

  : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

    Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]*/             
void Tavern::actionprint(){   //helper for printing main char actions
  std::string act="";
  Character *main = getMainCharacter();
  if      (main ->action_queue_.front() == ATT_Strike){act= "Strike";}
  else if (main ->action_queue_.front() == ATT_ThrowTomato){act= "ThrowTomato";}
  else if (main ->buff_stack_.top().name_ == "BUFF_Heal"){act= "Heal";}
  else if (main ->buff_stack_.top().name_ == "BUFF_MendMetal"){act= "MendMetal";}
  // if      (a ==1){act= "Heal";}
  // else if (a ==2){act= "MendMetal";}
  // else if (a ==3){act= "Strike";}
  // else if (a ==4){act= "ThrowTomato";}

  std::cout<<main ->getName()<<" used "<< act <<"!\n";

  std::cout<<"(YOU) "<<main ->getName()<<": LEVEL "<<main ->getLevel()<<" "<<main ->getRace()<<". \nVITALITY: "<<main ->getVitality()<<" \nARMOR: "<<main ->getArmor()<<"\n\n";

  std::cout<<"(ENEMY) "<<combat_queue_.front()->getName()<<": LEVEL "<<combat_queue_.front()->getLevel()<<" "<<combat_queue_.front()->getRace()<<". \nVITALITY: "<<combat_queue_.front()->getVitality()<<" \nARMOR: "<<combat_queue_.front()->getArmor()<<"\n";

}
  /**
        @post : If there are no actions in the main character's action queue, 
                or there are no enemies in the combat queue, do nothing.
                
                Otherwise do all of the following:            
                1. If the Buff stack is not empty, apply the buff once and decrement the turns.
                   Any time a Buff's turns_ goes to zero, it is removed
                   from the stack. Print out the results of the action as described below.
                2. While there are actions on the action queue:
                - take the next action off the queue
                - if the next action is  a buff, apply once and push it onto the buff stack after 
                  decrementing the turns. 
                  BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
                  for 2 turns in total. Print out the results of the action as described below.
                - if the next action is an attack, execute it against the enemy at the front of
                  the combat queue. Print out the results of the action as described below. 
                 - if after this action there are no more enemies to fight, clear the action
                   queue and return.
                3. Print "END OF YOUR TURN\n" 
          
            : More details:
        
            : After applying each action, print out the results of the action as follows:
            : [MAINCHARACTER NAME] used [ACTION NAME]!
            : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
            : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

             Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
             
            
            :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
                "[CHARACTER NAME] DEFEATED\n" 
                and remove the enemy from the combat queue AND let them exit the tavern. 
                Then carry out the remaining actions, if any, against the next enemy on the
                combat queue.
          
*/
  void Tavern::turnResolution() {
    Character *main = getMainCharacter();

    if (main ->action_queue_.empty() || combat_queue_.empty()){ //no actions or enemies = exit
      return; }
      
      else{
      if (main ->buff_stack_.size() > 0) {

        if(main ->buff_stack_.top().turns_<= 0){  //check buff has turns left, pop from stack
          main ->buff_stack_.pop();}

        else if(main ->buff_stack_.top().turns_>0){ //valid buff, apply, --turns
        if (main ->buff_stack_.top().name_ == "BUFF_Heal") {    //check name, apply buff, --turns, print
            main->heal();
            main->buff_stack_.top().turns_--;
            actionprint();
        }
        else if (main ->buff_stack_.top().name_ == "BUFF_MendMetal") {
            main->mendMetal ();
            main->buff_stack_.top().turns_--;
            actionprint();
        } }     
        }
      
    
      while (!main->action_queue_.empty()){ 
        if (main ->action_queue_.front() == 0){
          main ->heal();
          Buff buffheal = {"BUFF_Heal", 2};
          main ->buff_stack_.push(buffheal); 
          actionprint();
          main ->action_queue_.pop();
           }

        else if (main ->action_queue_.front() == 1){ 
          main ->mendMetal();
          Buff buffmend = {"BUFF_MendMetal", 1};
          main ->buff_stack_.push(buffmend); 
          actionprint();
          main ->action_queue_.pop();
           }

        else if (main ->action_queue_.front() ==  2){
          main ->strike(combat_queue_.front());
          actionprint();
          main ->action_queue_.pop();

          if (combat_queue_.front()->getVitality() <= 0){
            std::cout<<combat_queue_.front()->getName()<<" DEFEATED\n";
            exitTavern(combat_queue_.front());
            combat_queue_.pop();
          }}

        else if (main ->action_queue_.front() ==  3){
          main ->throwTomato(combat_queue_.front());
          actionprint();
          main ->action_queue_.pop();

          if (combat_queue_.front()->getVitality() <= 0){
            std::cout<<combat_queue_.front()->getName()<<" DEFEATED\n";
            exitTavern(combat_queue_.front());
            combat_queue_.pop();
          }}
 

          if (combat_queue_.size() == 0){ 
            std::queue<int> empty_queue;
            std::swap(main ->action_queue_, empty_queue); 
            return;
          }
    }
    }
    std::cout<<"\nEND OF YOUR TURN\n\n"; 
}



    /**
      @post : While the main character's vitality is > 0, and there are still enemies 
                in the combat queue, do the following:
            :     - Call actionSelection()
                  - Call turnResolution()
                  - Call enemyTurn() with a pointer to the first enemy on combat queue.

            : If the main character's vitality has fallen to 0, print "YOU HAVE PERISHED."
            : If there are no more enemies in the combat queue, print "NO MORE ENEMIES."
*/
void Tavern::combat() {
   
    if (main_character_ !=nullptr){
    do  {
    actionSelection();
    turnResolution();

  if (!combat_queue_.empty()){
      enemyTurn (combat_queue_.front());
    }
  ////
    }
    while (main_character_->getVitality() > 0 && combat_queue_.size() > 0);
      }

    if(combat_queue_.empty()) {
      std::cout<<"NO MORE ENEMIES."<<std::endl; return; }

    if (main_character_->getVitality() <= 0){
      std::cout<<"YOU HAVE PERISHED."<<std::endl;  return;
    }
    
}
 

/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}
/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {      return level_sum_;    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/**  @return:  The integer enemy count of the Tavern    **/
    int Tavern::getEnemyCount()    {      return num_enemies_;    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}


/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {    items_[i]->display();  }
}


/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {      items_[i]->display();    }
  }
}


/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}
