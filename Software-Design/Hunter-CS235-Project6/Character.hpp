/*
CSCI235 Summer 2023
Project 6 - Stew of the Day 
November 2023
Character.hpp declares the Character class along with its private and public members
New buff struct that takes name and int turn number and Action enum for 4 new actions a character can take
buff stack structure to store buffs for any character like main character or enemy, queue structure for an action queue to store MAIN CHAR (only) actions
add 4 new functions for buff and attack actions
*/
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>
 

enum Action {BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato};
struct Buff 
{   std::string name_;
    int turns_; //the number of turns this Buff will last for  
};

enum Race
{    NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character
{     private:
        //The name of the character (a string in UPPERCASE)
        std::string name_;
        // The race of the character (an enum)
        Race race_;
        // The character's vitality (a non-negative integer)
        int vitality_;
        // The character's max armor level (a non-negative integer)
        int armor_;
        // The character's level (a non-negative integer)
        int level_;
        // A flag indicating whether the character is an enemy
        bool enemy_; 

        
 
    public:
    std::queue<int> action_queue_;
    std::stack<Buff> buff_stack_; //a stack of Buff objects the character can use during their turn
 
// a queue of integers to store actions a character wants to take during their turn (as integers that correspond to the enum Action)
 //a vector of Action objects to store actions a character wants to take during their turn

void heal();
void mendMetal();
void strike(Character * Target);
void throwTomato(Character * Target);


        /**
            Default constructor.
            Default-initializes all private members. 
            Default character name: "NAMELESS". 
            Booleans are default-initialized to False. 
            Default enum value: NONE. 
            Default Vitality, Max Armor, and Level: 0.
        */
        Character();

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
        */
        Character(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);

        virtual ~Character() = default;

        /**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed.
        */
        void setName(const std::string& name);


        /**
            @return : the name of the Character
        */
        std::string getName() const;


        /**
            @param  : the race of the Character (a string)
            @post   : sets the Character's race to the value of the parameter
                    : If the given race was invalid, set race_ to NONE.
        */
        void setRace(const std::string& race);


        /**
            @return : the race of the Character (a string)
        */
        std::string getRace() const;


        /**
            @param  : an integer vitality
            @pre    : vitality >= 0 : Characters cannot have negative health
            @post   : sets the vitality private member to the value of the parameter
        */
        void setVitality(const int& vitality);


        /**
            @return : the value stored in vitality_
        */
        int getVitality() const;

        /**
            @param  : an integer armor level
            @pre    : armor >= 0 : Characters cannot have negative armor
            @post   : sets the armor private member to the value of the parameter\
        */
        void setArmor(const int& armor);

        /**
            @return : the value stored in armor_
        */
        int getArmor() const;

        /**
            @param  : an integer level
            @pre    : level >= 0 : Characters cannot have a negative
            @post   : sets the level private member to the value of the parameter
        */
        void setLevel(const int& level);


        /**
            @return : the value stored in level_
        */
        int getLevel() const;

        /**
            @post   : sets the enemy flag to true
        */
        void setEnemy();

        /**
            @return true if the character is an enemy, false otherwise

        Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
        */
        bool isEnemy() const;


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
        bool operator==(const Character& rhs) const;

        /*
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
        */
        bool operator!=(const Character& rhs) const;

        /**
         @post     : displays Character data in the form:
        "[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
        */
        virtual void display() const;
};

#endif