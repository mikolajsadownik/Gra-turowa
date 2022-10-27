//
// Created by mikol on 13.06.2022.
//

#include <iostream>
#include "earthquake.hpp"

earthquake::earthquake(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
        : special_skill(name,timesOfUse,typeOfSkill,duration) { };

auto earthquake::useSkill(pokemon &Pokemon) -> void {
    if(getTimesOfUseLeft()>0) {
        Pokemon.setDexterity(Pokemon.getDexterity() - 20);
        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';
    }
    else
        std::cout << "No usages left on skill";

}
auto earthquake::setValuesBeforUse(pokemon &Pokemon) -> void {
    Pokemon.setDexterity(Pokemon.getDexterity() + 20);
};