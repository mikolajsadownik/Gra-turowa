#include <iostream>
#include <vector>
#include <ctime>
#include "Pokemons/pokemon.hpp"
#include "Skills/special_skill.h"
#include "Skills/healing_water.hpp"
#include "Skills/fire_tornado.hpp"
#include "game.hpp"
int main() {






    std::srand(std::time(NULL));
     game Game = game();
   Game.intro();


//
    //auto p1 = Game.randomPokemon();
    // auto p2 = Game.randomPokemon();
  //p1.showStats();
  //p2.showStats();

  //p1.specialSkill->useSkill(p1);


  //std::cout << p1.specialSkill->getName();

  //p1.specialSkill->useSkill(p2);
//   p1.showStats();
//   p2.showStats();
//   auto dwa = p1.compablility(p2);
//   std::cout << dwa << '\n';
//   p1.attack(p2);
//    std::cout << p2.getCurrentHealth();
//   auto p2 = Game.randomPokemon();
//   auto p3 = Game.randomPokemon();
//p1.showStats();
//p2.showStats();
    return 0;
}
