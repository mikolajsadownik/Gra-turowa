
#include <iostream>
#include "air_blessing.hpp"
air_blessing::air_blessing(std::string name, int timesOfUse, Type_of_skill typeOfSkill,int duration)
        : special_skill(name,timesOfUse,typeOfSkill,duration) { };

auto air_blessing::useSkill(pokemon &Pokemon) -> void {
        Pokemon.setDexterity(Pokemon.getDexterity() + 20);
        setTimesOfUseLeft(getTimesOfUseLeft()-1);
        std::cout << "Used " << getName() << " on " << Pokemon.getName() << '\n';

}
auto  air_blessing::setValuesBeforUse(pokemon &Pokemon) -> void {
    Pokemon.setDexterity(Pokemon.getDexterity() - 20);
}