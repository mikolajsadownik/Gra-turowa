
#include <string>
#include <iostream>


#include "special_skill.h"



special_skill::special_skill(std::string name,int timesOfUse,Type_of_skill typeOfSkill,int duration)
    : name(name),timesOfUse(timesOfUse),typeOfSkill(typeOfSkill), duration(duration) {
    setTimesOfUseLeft(timesOfUse);
    setDurationLeft(duration);
}

special_skill::special_skill(special_skill const& other) : name(other.name),timesOfUse(other.timesOfUse),typeOfSkill(other.typeOfSkill), duration(other.duration) {
    setTimesOfUseLeft(other.timesOfUse);
    setDurationLeft(other.duration);
}



    auto special_skill::useSkill(pokemon &Pokemon) -> void {
        std::cout << "Testing if works" << '\n';
    };

    auto special_skill::setValuesBeforUse(pokemon &Pokemon) -> void{};

void special_skill::setTimesOfUse(int timesOfUse) {
    special_skill::timesOfUse = timesOfUse;
}

auto special_skill::isAlreadyUsed() -> bool{
    return duration!=durationLeft;
};

const std::string &special_skill::getName() const {
    return name;
}

void special_skill::setDurationLeft(int durationLeft) {
    special_skill::durationLeft = durationLeft;
}

int special_skill::getDurationLeft() const {
    return durationLeft;
}

void special_skill::setTimesOfUseLeft(int timesOfUseLeft) {
    special_skill::timesOfUseLeft = timesOfUseLeft;
}


int special_skill::getTimesOfUse() const {
    return timesOfUse;
}

int special_skill::getDuration() const {
    return duration;
}

Type_of_skill special_skill::getTypeOfSkill() const {
    return typeOfSkill;
}

int special_skill::getTimesOfUseLeft() const {
    return timesOfUseLeft;
}



//special_skill::useSkill(pokemon Pokemon) -> void;




