
#pragma once

#include <string>
#include <vector>
#include "Pokemons/pokemon.hpp"

class enemy {

public:
  std::string enemyName;
  std::vector<pokemon> enemyPokemons;
    enemy(std::string &enemyName,std::vector<pokemon> &enemyPokemons);

};



