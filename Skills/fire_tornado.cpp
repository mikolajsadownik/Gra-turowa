

#include <iostream>
#include "fire_tornado.hpp"

fire_tornado::fire_tornado(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
        : special_skill(name,timesOfUse,typeOfSkill,duration) { };

auto fire_tornado::useSkill(pokemon &Pokemon) -> void {
    if(getTimesOfUseLeft()>0) {
        Pokemon.setCurrentHealth(Pokemon.getCurrentHealth()-70);
        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';
    }
    else
        std::cout << "No usages left on skill";

}
auto fire_tornado::setValuesBeforUse(pokemon &Pokemon) -> void {
    /** nic nie robi bo tylko leczy (nie zmienia wartości na kila rund) **/
}