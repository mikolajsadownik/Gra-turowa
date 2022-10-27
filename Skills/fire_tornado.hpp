#pragma once


#include "special_skill.h"
#include "../Pokemons/pokemon.hpp"

class fire_tornado: public special_skill{

    public:

        fire_tornado(std::string name,int timesOfUse,Type_of_skill typeOfSkill, int duration);

        auto useSkill(pokemon &Pokemon) -> void override;

        auto setValuesBeforUse(pokemon &Pokemon) -> void override;
    };




