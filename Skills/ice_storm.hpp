//
// Created by mikol on 13.06.2022.
//

#pragma once
#include "special_skill.h"
#include "../Pokemons/pokemon.hpp"

class ice_storm: public special_skill{

    public:

    ice_storm(std::string name,int timesOfUse,Type_of_skill typeOfSkill, int duration);

    ice_storm(ice_storm const& other);

    auto useSkill(pokemon &Pokemon) -> void override;

    auto setValuesBeforUse(pokemon &Pokemon) -> void override;
};



