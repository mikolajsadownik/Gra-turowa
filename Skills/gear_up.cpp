//
// Created by mikol on 13.06.2022.
//

#include "gear_up.hpp"
gear_up::gear_up(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
        : special_skill(name,timesOfUse,typeOfSkill,duration) { };

auto gear_up::useSkill(pokemon &Pokemon) -> void {
    if(getTimesOfUseLeft()>0) {
        Pokemon.setStrength(Pokemon.getStrength() + 20);
        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';
    }
    else
        std::cout << "No usages left on skill";

}
auto gear_up::setValuesBeforUse(pokemon &Pokemon) -> void {
    Pokemon.setStrength(Pokemon.getStrength()-20);
}