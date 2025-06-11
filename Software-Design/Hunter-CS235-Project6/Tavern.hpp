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

#ifndef TAVERN_
#define TAVERN_

#include "ArrayBag.hpp"
#include "Character.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>

class Tavern : public ArrayBag<Character*>{
  private:
    int level_sum_; // An integer sum of the levels of all the characters currently in the tavern
    int num_enemies_; //number of enemies currently in the Tavern
        /**
    @post: all characters leave the tavern
    */
    void emptyTavern();
    Character *main_character_;
    std::queue<Character*> combat_queue_;


  public:
      /** Default Constructor **/
    Tavern(); 
    /**
    @param: a reference to the string name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
    */
    Tavern(const std::string& filename);
    void setMainCharacter(Character* mainchar);
    Character* getMainCharacter() const;
    static bool levelIsLess(Character* char_a, Character* char_b)  ;
    static bool levelIsGreater(Character* char_a, Character* char_b)  ;
    static bool vitalityIsLess(Character* char_a, Character* char_b)  ;
    static bool vitalityIsGreater(Character* char_a, Character* char_b)  ;
    Character * getTarget() ;
    void createCombatQueue(const std::string & queuestring = "NONE") ;  //creates using enemies in the Tavern
    void printCombatQueue(); //prints current combat queue
    void enemyTurn (Character * enemy) ;
    void enemyactionprint(const int a); 
    void actionSelection() ;           
    void add_action(); //helper for actionSelection
    void actionprint(); 
    void turnResolution() ;             
    void combat() ;

    /** 
        @param:   A reference to a Character entering the Tavern
        @return:  returns true if a Character was successfully added to items_, false otherwise
        @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
    **/
    bool enterTavern(Character* a_character);

    /** @param:   A reference to a Character leaving the Tavern  
        @return:  returns true if a character was successfully removed from items_, false otherwise
        @post:    removes the character from the Tavern and updates the level sum  and the enemy if the character is an enemy.
    **/
    bool exitTavern(Character* a_character);

    /** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int getLevelSum();

    /** 
        @return:  The average level of all the characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, 
                  and returns the integer value.
    **/
    int calculateAvgLevel();

    /** 
    @return:  The integer enemy count of the Tavern
    **/
    int getEnemyCount();

    /** 
        @return:  The percentage (double) of all the enemy characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, 
                 and returns the double value.
    **/
    double calculateEnemyPercentage();

    /** @param:   A string reference to a race 
        @return:  An integer tally of the number of characters in the Tavern of the given race
    **/
    int tallyRace(const std::string &race);

    /**
      @post:    Outputs a report of the characters currently in the tavern in the form:
      "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n"
      Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal

      Example output: 
      Humans: 3
      Elves: 5
      Dwarves: 8
      Lizards: 6
      Undead: 0

      The average level is: 7
      46.67% are enemies.
    */
    void tavernReport();


    /**  @post: For every character in the tavern, displays each character's 
    information */
    void displayCharacters();

    /**
        @param: a string reference to a race
        @post: For every character in the tavern of the given race, displays each character's information    */
    void displayRace(const std::string &race);


};
#endif
