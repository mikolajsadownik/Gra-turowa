//
// Created by mikol on 13.06.2022.
//

#include <iostream>
#include "ice_storm.hpp"

ice_storm::ice_storm(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
        : special_skill(name,timesOfUse,typeOfSkill,duration) { };

ice_storm::ice_storm(ice_storm const& other)
        : special_skill(other.getName(),other.getTimesOfUse(),getTypeOfSkill(),other.getDuration()) { };

auto ice_storm::useSkill(pokemon &Pokemon) -> void {
    if(getTimesOfUseLeft()>0) {
        Pokemon.setIsStunned(true);
        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';
    }
    else
        std::cout << "No usages left on skill";

}
auto ice_storm::setValuesBeforUse(pokemon &Pokemon) -> void{
    Pokemon.setIsStunned(false);
}