
#include <string>
#include <iostream>
#include <cstdlib>
#include "pokemon.hpp"
#include "../Skills/air_blessing.hpp"
#include "../Skills/earthquake.hpp"
#include "../Skills/fire_tornado.hpp"
#include "../Skills/gear_up.hpp"
#include "../Skills/healing_water.hpp"
#include "../Skills/ice_storm.hpp"
#include "../Pokemons/pokemon.hpp"





    pokemon::pokemon(std::string Name, Type_of_pokemon typeOfPokemon, int Strength, int Dexterity, int MaxHealth, special_skill *specialSkill)
            : name(Name),type_of_pokemon(typeOfPokemon), Strength(Strength), Dexterity(Dexterity),
            MaxHealth(MaxHealth)
            , specialSkill(specialSkill)
            {
        setCurrentHealth(MaxHealth);
};

    pokemon::pokemon(pokemon const& other) :
        name(other.name), type_of_pokemon(other.type_of_pokemon), Strength(other.Strength), Dexterity(other.Dexterity), MaxHealth(other.MaxHealth), specialSkill(other.specialSkill){
        setCurrentHealth(other.CurrentHealth);
    }

int pokemon::getCurrentHealth() const {
    return CurrentHealth;
}

void pokemon::setCurrentHealth(int currentHealth) {
    CurrentHealth = currentHealth;
}

void pokemon::showStats() {

        std::cout << "Name: " << name << '\n';
        std::cout << "Type of pokemon: " << typeToString(type_of_pokemon) << '\n';
        std::cout << "Strength: " << Strength << '\n';
        std::cout << "Dexterity: " << Dexterity << '\n';
        std::cout << "Max Health: " << MaxHealth << '\n';
        std::cout << "Current Health: " << CurrentHealth << '\n';
        std::cout << "Special skill: " << specialSkill->getName() << '\n';
        std::cout << "Experience points: " << experience_points << '\n';
    }

    auto pokemon::typeToString(Type_of_pokemon type_of_pokemon) -> std::string {
        switch (type_of_pokemon) {
            case Type_of_pokemon::WATER:
                return "Water";
            case Type_of_pokemon::EARTH:
                return "Earth";
            case Type_of_pokemon::AIR:
                return "Air";
            case Type_of_pokemon::FIRE:
                return "Fire";
            case Type_of_pokemon::ICE:
                return "Ice";
            case Type_of_pokemon::STEEL:
                return "Steel";

        }
    }

    auto pokemon::attack(pokemon &Pokemon) -> void {
        if (isStunned == false) {
            auto chanceOfDodge = std::rand() % 100;
            if (chanceOfDodge > Pokemon.getDexterity()) {
                int dmg = pokemon::compablility(Pokemon) * Strength;
                std::cout << name << " attacked " << Pokemon.getName() << " and dealt " << dmg << '\n';
                Pokemon.setCurrentHealth(Pokemon.getCurrentHealth() - dmg);

            } else
                std::cout << name << " attacked " << Pokemon.getName() << " and missed!!! " << '\n';
        }
        else
            std::cout << name << " is stunned " << '\n';
    }



    auto pokemon::isAlive() -> bool {
        return CurrentHealth > 0;
    }

int pokemon::getExperiencePoints() const {
    return experience_points;
}

auto pokemon::compablility(pokemon Pokemon) -> double {
    /**najpierw słabe oddziaływanie**/
    /**z wodą**/
    if((type_of_pokemon==Type_of_pokemon::WATER && Pokemon.type_of_pokemon==Type_of_pokemon::WATER) ||
    (type_of_pokemon==Type_of_pokemon::FIRE && Pokemon.type_of_pokemon==Type_of_pokemon::WATER) ||
    (type_of_pokemon==Type_of_pokemon::ICE && Pokemon.type_of_pokemon==Type_of_pokemon::WATER) ||
    /** z ziemią**/
    (type_of_pokemon==Type_of_pokemon::AIR && Pokemon.type_of_pokemon==Type_of_pokemon::EARTH) ||
    (type_of_pokemon==Type_of_pokemon::FIRE && Pokemon.type_of_pokemon==Type_of_pokemon::EARTH) ||
/** z powietrzem**/
(type_of_pokemon==Type_of_pokemon::EARTH && Pokemon.type_of_pokemon==Type_of_pokemon::AIR) ||
/** z ogniem**/
(type_of_pokemon==Type_of_pokemon::ICE && Pokemon.type_of_pokemon==Type_of_pokemon::FIRE) ||
(type_of_pokemon==Type_of_pokemon::STEEL && Pokemon.type_of_pokemon==Type_of_pokemon::FIRE) ||
/** z lodem**/
(type_of_pokemon==Type_of_pokemon::ICE && Pokemon.type_of_pokemon==Type_of_pokemon::ICE) ||
/**ze stalą**/
(type_of_pokemon==Type_of_pokemon::AIR && Pokemon.type_of_pokemon==Type_of_pokemon::STEEL) ||
(type_of_pokemon==Type_of_pokemon::STEEL && Pokemon.type_of_pokemon==Type_of_pokemon::STEEL))
    return 0.5;
/**teraz zwiększona efektywność**/
/** woda**/
if((type_of_pokemon==Type_of_pokemon::STEEL && Pokemon.type_of_pokemon==Type_of_pokemon::WATER) ||
/** ziemia**/
(type_of_pokemon==Type_of_pokemon::WATER && Pokemon.type_of_pokemon==Type_of_pokemon::EARTH) ||
(type_of_pokemon==Type_of_pokemon::ICE && Pokemon.type_of_pokemon==Type_of_pokemon::EARTH) ||
/** powietrze**/
(type_of_pokemon==Type_of_pokemon::STEEL && Pokemon.type_of_pokemon==Type_of_pokemon::AIR) ||
/**ogień**/
(type_of_pokemon==Type_of_pokemon::WATER && Pokemon.type_of_pokemon==Type_of_pokemon::FIRE) ||
(type_of_pokemon==Type_of_pokemon::EARTH && Pokemon.type_of_pokemon==Type_of_pokemon::FIRE) ||
/**lód**/
(type_of_pokemon==Type_of_pokemon::EARTH && Pokemon.type_of_pokemon==Type_of_pokemon::ICE) ||
(type_of_pokemon==Type_of_pokemon::AIR && Pokemon.type_of_pokemon==Type_of_pokemon::ICE) ||
(type_of_pokemon==Type_of_pokemon::FIRE && Pokemon.type_of_pokemon==Type_of_pokemon::ICE) ||
/**stal**/
(type_of_pokemon==Type_of_pokemon::EARTH && Pokemon.type_of_pokemon==Type_of_pokemon::STEEL) ||
(type_of_pokemon==Type_of_pokemon::FIRE && Pokemon.type_of_pokemon==Type_of_pokemon::STEEL))
    return 1.5;


/**domyślnie mnożnik x1**/
return 1;
}

Type_of_pokemon pokemon::getTypeOfPokemon() const {
return type_of_pokemon;
}

int pokemon::getStrength() const {
return Strength;
}

int pokemon::getDexterity() const {
return Dexterity;
}

int pokemon::getMaxHealth() const {
return MaxHealth;
}


bool pokemon::isSstunned() const {
return isStunned;
}
/**settery**/

void pokemon::setStrength(int strength) {
Strength = strength;
}

void pokemon::setDexterity(int dexterity) {
Dexterity = dexterity;
}

void pokemon::setMaxHealth(int health) {
MaxHealth = health;
}

void pokemon::setExperiencePoints(int experiencePoints) {
experience_points = experiencePoints;
}

void pokemon::setLvl(int lvl) {
pokemon::lvl = lvl;
}

void pokemon::setIsStunned(bool isStunned) {
pokemon::isStunned = isStunned;
}

const std::string &pokemon::getName() const {
return name;
}

int pokemon::getLvl() const {
return lvl;
}

const special_skill *pokemon::getSpecialSkill() const {
return specialSkill;
}

///////////////////////////////////


