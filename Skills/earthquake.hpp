
#pragma once


#include "special_skill.h"
#include "../Pokemons/pokemon.hpp"

class earthquake: public special_skill{

        public:

        earthquake(std::string name,int timesOfUse,Type_of_skill typeOfSkill, int duration);

        auto useSkill(pokemon &Pokemon) -> void override;

        auto setValuesBeforUse(pokemon &Pokemon) -> void override;

};




