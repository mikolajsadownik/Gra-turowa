
#pragma once
//#include "../Skills/special_skill.h"

class special_skill;

enum class Type_of_pokemon {
    WATER, EARTH, AIR, FIRE, ICE, STEEL
};

class pokemon {
    std::string name;
    Type_of_pokemon type_of_pokemon;
    int Strength;
    int Dexterity;
    int MaxHealth;
    int CurrentHealth;
    //skill na public
    int experience_points = 0;
    int lvl = 1;
    bool isStunned = false;

public:
    special_skill *specialSkill;

    void showStats() ;

    auto typeToString(Type_of_pokemon type_of_pokemon) -> std::string;

    auto attack(pokemon &Pokemon) -> void;

    bool isAlive();

    pokemon(std::string Name,Type_of_pokemon typeOfPokemon, int Strength, int Dexterity, int MaxHealth
            ,special_skill *specialSkill
            );

    pokemon(pokemon const& other);

    Type_of_pokemon getTypeOfPokemon() const;

    int getStrength() const;

    int getDexterity() const;

    int getMaxHealth() const;

    const special_skill * getSpecialSkill() const;

    bool isSstunned() const;

    void setStrength(int strength);

    void setDexterity(int dexterity);

    void setMaxHealth(int health);

    void setExperiencePoints(int experiencePoints);

    const std::string &getName() const;

    void setLvl(int lvl);

    void setIsStunned(bool isStunned);

    int getCurrentHealth() const;

    void setCurrentHealth(int currentHealth);

    int getLvl() const;

    double compablility(pokemon Pokemon);

    int getExperiencePoints() const;


};