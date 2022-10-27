#pragma once

#include "special_skill.h"
#include "../Pokemons/pokemon.hpp"

class air_blessing: public special_skill{

        public:

        air_blessing(std::string name,int timesOfUse,Type_of_skill typeOfSkill, int duration);

        auto useSkill(pokemon &Pokemon) -> void override;

        auto  setValuesBeforUse(pokemon &Pokemon) -> void override;


};
