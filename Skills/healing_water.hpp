#pragma once

#include <iostream>
#include "special_skill.h"
//#include "../Pokemons/pokemon.hpp"



class healing_water :public special_skill{

public:
    healing_water(healing_water const& other);

    healing_water(std::string name,int timesOfUse,Type_of_skill typeOfSkill, int duration);

    auto useSkill(pokemon &Pokemon) -> void override;

    auto setValuesBeforUse(pokemon &Pokemon) -> void override;

};



