/*
CSCI235 Fall 2023
Project 6 - Stew of the Day 
November 2023
implemen 4 new buff or action functions heal mendmetal strike throwtomato
Character.cpp defines the constructors and private and public function implementation of the Character class
*/
#include "Character.hpp"
/**
 * 
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default enum value: NONE. 
    Default Vitality, Max Armor, and Level: 0.
*/

/** BUFF ACTIONS */
/**
    @pre: This function is called to execute the Action BUFF_Heal
    @post: Increases the character's vitality by 2
*/
void Character::heal(){
    //Character->setVitality(Character->getVitality()) += 2;
    //setVitality(getVitality()) += 2;
    vitality_ += 2;
}


/* @pre: This function is called to execute the Action BUFF_MendMetal
  @post: Increases the character's armor by 2

*/
void Character::mendMetal(){
    //Character->setArmor(Character->getArmor()) += 2;
    //setArmor(getArmor()) += 2;
    armor_ += 2;
}


/** ATTACK ACTIONS */

/**
  @pre: This function is called to execute the Action ATT_Strike
  @param: A pointer to a character target
  @post: Deals 2 points of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they lose 1 vitality point.
*/ 
void Character::strike(Character * Target){
    if (Target->getArmor() >= 2){
        Target->setArmor(Target->getArmor() -2);
    }
    else if (Target->getArmor() == 1){
        Target->setArmor(Target->getArmor() -1);
        Target->setVitality(Target->getVitality() -1);
    }
    else{
        if (Target->getVitality() <= 2){
            Target->setVitality(0);
        }
        else
        Target->setVitality(Target->getVitality() -2);
    }
    return;
}


/**
 @pre: This function is called to  execute the Action ATT_ThrowTomato
  @param: A pointer to a character target
  @post: Deals 1 point of damage to the target character. 
  
  If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they don't lose any vitality points. Your character gains 1 vitality point (as laughter is the best medicine).
*/ 
void Character::throwTomato(Character * Target){
    if(Target->getArmor() > 0){
        Target->setArmor(Target->getArmor() -1);
    }
    else{
        Target->setVitality(Target->getVitality() -1);
    } 
    vitality_ += 1;
    //setVitality(getVitality()) += 1;

    return;
}

/*IMPORTANT NOTE: As you proceed to Task 2, you will realize that the Tavern class will need to obtain data or modify a Character's actions and buffs. As it will be necessary to access or modify the Character's data structures, you should consider implementing a number of additional public functions for the Character class as you see fit.*/

Character::Character(): name_{"NAMELESS"},race_{NONE},vitality_{0},armor_{0},level_{0},enemy_{false}
{}

/**
Parameterized constructor.
    @param      : The name of the character (a string in UPPERCASE)
    @param      : The race of the character (a string)
    @param      : The character's vitality (a non-negative integer) , with default value 0
    @param      : The character's max armor level (a non-negative integer), with default value 0
    @param      : The character's level (a non-negative integer), with default value 0
    @param      : A flag indicating whether the character is an enemy, with default value false
    @post       : The private members are set to the values of the corresponding parameters. 
                Hint: Notice the default arguments in the parameterized constructor.
                If the given parameters are invalid, the default values are used instead.
*/
Character::Character(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy) : Character()
{
    setName(name); // checks valid name
    setRace(race); // checks valid race
    (vitality >= 0) ? vitality_ = vitality: vitality_ = 0;
    (armor >= 0) ? armor_ = armor: armor_ = 0;
    (level >= 0) ? level_ = level: level_ = 0;
    enemy_ = enemy; 
}

 /**
    @param  : the name of the Character
    @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed. For example, attempting to create a character named "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
    : If the given parameter does not have any valid alphabetical characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string& name)
{   std::string nameUpper = "";
    for(int i = 0; i<name.size();i++)
    {   if(std::isalpha(name[i]))
        {            nameUpper+= toupper(name[i]);        }
    }
    if(nameUpper != "")
    {        name_ = nameUpper;    }
    else
    {        name_ = "NAMELESS";    }
}


/**
    @return : the name of the Character
*/
std::string Character::getName() const   {    return name_;}


/**
    @param  : the race of the Character (a string)
    @post   : sets the Character's race to the value of the parameter. Valid races: [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
            : If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string& race)
{    if(race == "HUMAN")
    {        race_ = HUMAN;    }
    else if(race == "ELF")
    {        race_ = ELF;    }
    else if(race == "DWARF")
    {        race_ = DWARF;    }
    else if(race == "LIZARD")
    {        race_ = LIZARD;    }
    else if(race == "UNDEAD")
    {        race_ = UNDEAD;    }
    else
    {        race_ = NONE;    }
}


/**
    @return : the race of the Character (a string)
*/
std::string Character::getRace() const
{   if (race_ == Race::HUMAN)
    {        return "HUMAN";    }
    else if (race_ == Race::ELF)
    {        return "ELF";    }
    else if (race_ == Race::DWARF)
    {        return "DWARF";    }
    else if (race_ == Race::LIZARD)
    {        return "LIZARD";    }
    else if (race_ == Race::UNDEAD)
    {        return "UNDEAD";    }
    else
    {        return "NONE";    }
}


/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
void Character::setVitality(const int& vitality)
{
    if (vitality >= 0)
    {        vitality_ = vitality;    }
}


/**
    @return : the value stored in vitality_
*/
int Character::getVitality() const  {    return vitality_;}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
void Character::setArmor(const int& armor)
{   if (armor >= 0)
    {        armor_ = armor;    }
}


/**
    @return : the value stored in armor_
*/
int Character::getArmor() const   {    return armor_;}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/
void Character::setLevel(const int& level)
{
    if (level >= 0)
    {        level_ = level;    }
}


/**
    @return : the value stored in level_
*/
int Character::getLevel() const  {    return level_;}

/**
    @post   : sets the enemy flag to true
*/
void Character::setEnemy()   {    enemy_ = true;}

/**
    @return true if the character is an enemy, false otherwise

Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
*/
bool Character::isEnemy() const {    return enemy_;}



/**
        @param     	: A reference to the right hand side of the == operator.
        @return     : Returns true if the right hand side character is "equal", false otherwise. 									
                     Two characters are equal if they have the same name, same race, same level 									
                     and are either both an enemy or not.

        Note: By this definition, only some of the character's attributes must be equal for two characters to be deemed "equal".

        Example: In order for character1 to be == to character2 we only need:
        - The same name
        - The same race
         - The same level
        - They must either be both an enemy or not
*/
bool Character::operator==(const Character& rhs) const
{
    return(name_ == rhs.getName() && getRace() == rhs.getRace() && level_ == rhs.getLevel() && enemy_ == rhs.isEnemy());
}

/**
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
*/
bool Character::operator!=(const Character& rhs) const
{
    return(!(*this == rhs));
}

/**
 @post     : displays Character data in the form:
"[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
*/
void Character::display() const
{
    std::cout<<name_<<" is a Level "<<level_<<" "<<getRace()<<
    ". \nVitality: "<<vitality_<<
    "\nMax Armor: "<<armor_<<" \n"<<
    (enemy_ ? "They are an enemy.\n" : "They are not an enemy.\n");
}


