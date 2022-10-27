
#pragma once

#include <string>
#include "special_skill.h"
#include "../Pokemons/pokemon.hpp"
#include <iostream>

class gear_up: public special_skill{

public:

    gear_up(std::string name, int timesOfUse, Type_of_skill typeOfSkill, int duration);

    auto useSkill(pokemon &Pokemon) -> void override;

    auto setValuesBeforUse(pokemon &Pokemon) -> void;


};




