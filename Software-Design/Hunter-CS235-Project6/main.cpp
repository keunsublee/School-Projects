#include <iostream>
#include "Tavern.hpp"

int main() {
    Tavern myTavern;
    myTavern = Tavern("enemies.csv");

//  const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
    Character main {"J","HUMAN", 20, 10, 1, false};
    myTavern.enterTavern(&main);
    myTavern.setMainCharacter(&main);
    myTavern.createCombatQueue("LVLASC");
    myTavern.combat();
    
    std::cout << "\n";

    // Tavern tavern;
// Character c1("MAINCHARACTER", "HUMAN", 1, 1, 1, false);
// Character c2("FIRSTENEMY", "ELF", 50, 50, 1, true);

// tavern.enterTavern(&c1);
// tavern.enterTavern(&c2);
// tavern.setMainCharacter(&c1);

// tavern.combat(); // combat should terminate after printing "NO MORE ENEMIES"

// tavern.createCombatQueue("NONE");

// // Call the combat function
// tavern.combat();

// c1.setVitality(100);
// c1.setArmor(100);
// tavern.exitTavern(&c2);
// Character c3("SECONDENEMY", "DWARF", 2, 2, 2, true);
// Character c4("THIRDENEMY", "LIZARD", 4, 2, 3, true);

// tavern.enterTavern(&c3);
// tavern.enterTavern(&c4);
// tavern.createCombatQueue();

// // Call the combat function again
// tavern.combat();
 
    return 0;
}
