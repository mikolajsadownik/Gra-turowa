#include "healing_water.hpp"
#include "special_skill.h"
#include <iostream>


healing_water::healing_water(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
    : special_skill(name,timesOfUse,typeOfSkill,duration) { };




auto healing_water::useSkill(pokemon &Pokemon) -> void {

        auto hp = Pokemon.getCurrentHealth();
        if (hp + 50 > Pokemon.getMaxHealth())
            Pokemon.setCurrentHealth(Pokemon.getMaxHealth());
        else
            Pokemon.setCurrentHealth(hp + 50);

        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';


}
auto healing_water::setValuesBeforUse(pokemon &Pokemon) -> void {
    /** nic nie robi bo tylko leczy (nie zmienia wartości na kila rund) **/
};