#pragma once
#include <string>

#include "../Pokemons/pokemon.hpp"



enum class Type_of_skill {
    OFFENSIVE,
    DEFFENSIVE
};

class special_skill {

    int timesOfUse;
    int timesOfUseLeft;
    Type_of_skill typeOfSkill;
    int duration;
    int durationLeft;

public:
    std::string name;

    special_skill(std::string name, int timesOfUse, Type_of_skill typeOfSkill, int duration);

    special_skill(special_skill const& other);

   auto virtual setValuesBeforUse(pokemon &Pokemon) -> void;

    auto isAlreadyUsed() -> bool;

    auto virtual useSkill(pokemon &Pokemon) -> void;
//    auto useSkill(pokemon &Pokemon) -> void;

    int getTimesOfUseLeft() const;

    const std::string &getName() const;

    int getTimesOfUse() const;

    int getDuration() const;

    Type_of_skill getTypeOfSkill() const;

    const std::string &getDescription() const;

    void setTimesOfUse(int timesOfUse);

    void setTimesOfUseLeft(int timesOfUseLeft);

    int getDurationLeft() const;

    void setDurationLeft(int durationLeft);


};