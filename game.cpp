
#include <iostream>
#include "game.hpp"



void game::intro() {
    std::cout << "Welcome in world of pokemons" << '\n';
    auto choice = 0;
    std::cout << "Choose difficulty" << '\n';
    std::cout << "[1] Easy" << '\n';
    std::cout << "[2] Normal" << '\n';
    std::cout << "[3] Hard" << '\n';
    std::cin >> choice;
    switch(choice){
        case 1 : {
            std::cout << "You have chosen easy difficulty" << '\n';
            std::cout << "You gonna face 4 opponents, each having 4 pokemons" << '\n';
            pokemonDraw(4,4);
            break;
        }
        case 2 :
            std::cout << "You have chosen medium difficulty" << '\n';
            std::cout << "You gonna face 4 opponents, each having 5 pokemons" << '\n';
            game::pokemonDraw(4,5);
            break;
        case 3 :
            std::cout << "You have chosen hard difficulty" << '\n';
            std::cout << "You gonna face 5 opponents, each having 5 pokemons" << '\n';
            game::pokemonDraw(5,5);
            break;
        default: std::cout << "Wrong input !!!" << '\n';
        game::intro();
    }





}

void game::pokemonDraw(int amountOfEnemies, int amountOfPokemonsPerEnemy) {
    std::cout << "Choose your team: ";
    /**losujemy pulę pokemonów (mniejsze od 32 bo tyle max pokemonów może być w grze przy 5 enemy)**/
    for(int i = 0; i<32;i++){
        auto Pokemon = game::randomPokemon();
        AllPokemons.push_back(Pokemon);
    }

    auto counter = 1;

    for(auto e : AllPokemons) {
        std::cout << '[' << counter << ']' << '\n';
        e.showStats();
        counter++;
    }
    /**zamieniam counter na 1 bo przyda się dalej a nie chcemy tworzyć nowego**/
    counter = 1;
    auto choice = 0;

    std::set<int> alreadyUsed;

    while(PlayerPokemons.size()<6){

        std::cin >> choice;
        if(choice < 1 || choice > AllPokemons.size()){
            std::cout << "Wrong input!!!" << '\n';
        }
        else {
            auto isItUsed = alreadyUsed.contains(choice);
            if (choice >= 1 && choice < AllPokemons.size() && !isItUsed) {
                alreadyUsed.insert(choice);
                PlayerPokemons.push_back(AllPokemons.at(choice - 1));
                std::cout << "Selected " << AllPokemons.at(choice - 1).getName() << '\n';
            }
            if (isItUsed) {
                std::cout << "You already choosen this one" << '\n';
            }
        }
    }
    std::cout << "Your team: " << '\n';

    for(auto e : PlayerPokemons){
        std::cout << e.getName() << '\n';
    }

    /** teraz losuje dla przeciwników **/


    for(int i = 0; i < amountOfEnemies;i++){
        std::string s = std::to_string(counter);
        std::string enemyName = "Enemy " + s;
        counter++;
        std::vector<pokemon> enemyPokemons;
        enemy Enemy = enemy(enemyName,enemyPokemons);
        Enemy.enemyName = enemyName;


        std::cout << Enemy.enemyName << '\n';
        for(int j = 0; j<amountOfPokemonsPerEnemy;j++){
            pokemon Pokemon = AllPokemons.at(std::rand() % AllPokemons.size());
            Enemy.enemyPokemons.push_back(Pokemon);
        }
        for(auto e : Enemy.enemyPokemons){
            std::cout << e.getName() << '\n';
        }
        AllEnemies.push_back(Enemy);

    };

    /** pętla gry dla każdego przeciwnika **/
    for(auto e : AllEnemies) {
        game::playerVsEnemy(PlayerPokemons, e);
        /** przywracanie hp pokemonom po walce i resetowanie speciall skilli **/
        for(auto e  : PlayerPokemons){
            e.setCurrentHealth(e.getMaxHealth());
            e.specialSkill->setTimesOfUseLeft(e.specialSkill->getTimesOfUse());
            e.specialSkill->setDurationLeft(e.specialSkill->getDuration());
        }

    }
    // gra kończy się wygraną gracza

    std::cout << "YOU WON :) !!!!!!";

};
bool game::anyIsAlive(std::vector<pokemon> &pokemons){
    auto counter = 0;
    for(auto e : pokemons){
        if(e.isAlive()){
            counter++;
        }
    }
    return counter>0;
};


void game::playerVsEnemy(std::vector<pokemon> &yourPokemons,enemy &Enemy) {
    std::cout << "///////////////////////////////////////////////////////////////" << "\n";

    std::cout << "Your opponent is: " << Enemy.enemyName << '\n';
    /**domyślnie nasz pokemon do walki jest ustawiany jako pierwszy w vektorze **/
    pokemon pokemonAtHand = yourPokemons.at(0);
    yourPokemons.erase(yourPokemons.begin());

    while (anyIsAlive(yourPokemons) && Enemy.enemyPokemons.size() > 0) {
        std::cout << "///////////////////////////////////////////////////////////////" << "\n";
        std::cout << "Enemy pokemon is:  " << '\n';
        Enemy.enemyPokemons.back().showStats();

        std::cout << "Your pokemon in battle is: ";
        pokemonAtHand.showStats();
        std::cout << "What do you want do do? " << '\n';
        std::cout << "[1] Attack Enemy " << '\n';
        std::cout << "[2] Use special skill " << '\n';
        std::cout << "[3] Change your pokemon at hand" << '\n';
        std::cout << "[4] Evolve your pokemon at hand" << '\n';
        auto choice = 0;
        std::cin >> choice;
        switch (choice) {
            case 1 : {
                pokemonAtHand.attack(Enemy.enemyPokemons.back());
                if (Enemy.enemyPokemons.back().getCurrentHealth() <= 0) {
                    /** przyznajemy 500 exp dla pokemona który pokonał pokemona przeciwnika **/
                    pokemonAtHand.setExperiencePoints(pokemonAtHand.getExperiencePoints() + 500);
                    std::cout << "Enemy pokemon defeated !!!";
                    Enemy.enemyPokemons.pop_back();
                } else {
                    Enemy.enemyPokemons.back().attack(pokemonAtHand);
                    /** czas na abillity spada **/
                    if(pokemonAtHand.specialSkill->isAlreadyUsed())
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft() - 1);

                    if(pokemonAtHand.specialSkill->getDurationLeft()==0) {
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDuration());
                        pokemonAtHand.specialSkill->setTimesOfUseLeft(pokemonAtHand.specialSkill->getTimesOfUseLeft()-1);
                    }
                    if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                        pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                    }else
                        pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                    if (!pokemonAtHand.isAlive()) {
                        std::cout << "Your pokemon is UNCONSCIOUS !!!!";
                        //zwracamy nieprzytomnego pokemona do vektora
                        PlayerPokemons.push_back(pokemonAtHand);
                        for (int i = 0; i < PlayerPokemons.size();i++) {
                            if (PlayerPokemons[i].getCurrentHealth() > 0) {
                                pokemonAtHand = PlayerPokemons[i];
                                PlayerPokemons.erase(PlayerPokemons.begin() + i);
                                break;
                            }

                        }

                    }
                }
            }
                break;

            case 2: {  /** użycie umiejętności **/
                if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE){
                    if(pokemonAtHand.specialSkill->getTimesOfUseLeft()>0 && !pokemonAtHand.specialSkill->isAlreadyUsed()) {
                        pokemonAtHand.specialSkill->useSkill(Enemy.enemyPokemons.back());
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft()-1);

                        /** Przeciwnik robi turę **/

                        Enemy.enemyPokemons.back().attack(pokemonAtHand);
                        if(pokemonAtHand.specialSkill->isAlreadyUsed())
                            pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft() - 1);

                        if (!pokemonAtHand.isAlive()) {
                            std::cout << "Your pokemon is UNCONSCIOUS !!!!";
                            /** zwracamy nieprzytomnego pokemona do vektora **/
                            PlayerPokemons.push_back(pokemonAtHand);
                            for (auto e: PlayerPokemons) {
                                if (e.getCurrentHealth() > 0) {
                                    pokemonAtHand = e;
                                }
                                break;
                            }
                        }
                    }
                    else
                        std::cout << "Can't use it right now :( ";
                } else {
                    if(pokemonAtHand.specialSkill->getTimesOfUseLeft()>0 && !pokemonAtHand.specialSkill->isAlreadyUsed()) {
                        pokemonAtHand.specialSkill->useSkill(pokemonAtHand);

                        /** Przeciwnik robi turę **/

                        Enemy.enemyPokemons.back().attack(pokemonAtHand);

                        if(pokemonAtHand.specialSkill->isAlreadyUsed())
                            pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft() - 1);

                        if(pokemonAtHand.specialSkill->getDurationLeft()==0) {
                            pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDuration());
                            pokemonAtHand.specialSkill->setTimesOfUseLeft(pokemonAtHand.specialSkill->getTimesOfUseLeft()-1);
                            if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                                pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                            }else
                                pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                        }

                        if (!pokemonAtHand.isAlive()) {
                            std::cout << "Your pokemon is UNCONSCIOUS !!!!";
                            /**zwracamy nieprzytomnego pokemona do vektora **/
                            PlayerPokemons.push_back(pokemonAtHand);
                            for (int i = 0; i < PlayerPokemons.size();i++) {
                                if (PlayerPokemons[i].getCurrentHealth() > 0) {
                                    /** special skill się kończy wraz ze zmianą pokemona **/
                                    if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                                        pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                                    }else
                                        pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                                    pokemonAtHand = PlayerPokemons[i];
                                    PlayerPokemons.erase(PlayerPokemons.begin() + i);
                                    break;
                                }

                            }
                        }
                    }
                    else
                        std::cout << "Can't use it right now :( ";
                }

                break;
            };


            case 3: {
                /** ZMIANA POKEMONA DO WALKI **/

                std::cout << "///////////////////////////////////////////////////////////////" << "\n";
                std::cout << "Pokemons to choose from: " <<  PlayerPokemons.size() << "\n";
                auto counter = 1;
                for (auto e: PlayerPokemons) {
                    if (e.isAlive()) {
                        std::cout << '[' << counter << ']' << '\n';
                        e.showStats();
                        counter++;
                    } else {
                        std::cout << '[' << counter << ']' << " [UNCONSCIOUS] " << '\n';
                        e.showStats();
                        counter++;
                    }
                }
                int choice;
                std::cin >> choice;
                if (choice >= 1 && choice <= (PlayerPokemons.size() + 1) && PlayerPokemons.at(choice - 1).isAlive()) {
                    /** special skill się kończy wraz ze zmianą pokemona **/
                    if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                        pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                    }else
                        pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                    PlayerPokemons.push_back(pokemonAtHand);
                    pokemonAtHand = PlayerPokemons.at(choice - 1);
                    PlayerPokemons.erase(PlayerPokemons.begin() + (choice - 1));
                    std::cout << "Pokemon at hand changed to: " << pokemonAtHand.getName() << '\n';

                    /**przeciwnik robi turę**/
                    Enemy.enemyPokemons.back().attack(pokemonAtHand);

                    pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft() - 1);
                    if(pokemonAtHand.specialSkill->getDurationLeft()==0) {
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDuration());
                        pokemonAtHand.specialSkill->setTimesOfUseLeft(pokemonAtHand.specialSkill->getTimesOfUseLeft()-1);
                    }


                    if (!pokemonAtHand.isAlive()) {
                        std::cout << "Your pokemon is UNCONSCIOUS !!!!";
                        /**zwracamy nieprzytomnego pokemona do vektora **/
                        PlayerPokemons.push_back(pokemonAtHand);
                        for (int i = 0; i < PlayerPokemons.size();i++) {
                            if (PlayerPokemons[i].getCurrentHealth() > 0) {
                                /** special skill się kończy wraz ze zmianą pokemona **/
                                if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                                    pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                                }else
                                    pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                                pokemonAtHand = PlayerPokemons[i];
                                PlayerPokemons.erase(PlayerPokemons.begin() + i);
                                break;
                            }

                        }
                    }
                } else {
                    std::cout << "Can't pick that pokemon" << '\n';
                }

            }
                break;
            case 4: { /** ewolucja **/
                if (pokemonAtHand.getExperiencePoints() >= (500 * pokemonAtHand.getLvl())) {
                    pokemonAtHand.setLvl(pokemonAtHand.getLvl() + 1);
                    pokemonAtHand.setExperiencePoints(pokemonAtHand.getExperiencePoints() - 500 * pokemonAtHand.getLvl());
                    int choice;
                    auto counter = 0;
                    std::cin >> choice;
                    std::cout << "What do you want to evolove: ";
                    std::cout << "[1] Strength ";
                    std::cout << "[2] MaxHp ";
                    std::cout << "[3] Dexterity ";
                    while (counter <= 1) {
                        switch (choice) {
                            case 1 :
                                pokemonAtHand.setStrength(pokemonAtHand.getStrength() + 20);
                                counter++;
                                break;
                            case 2 :
                                pokemonAtHand.setMaxHealth(pokemonAtHand.getMaxHealth() + 50);
                                counter++;
                                break;
                            case 3 :
                                pokemonAtHand.setDexterity(pokemonAtHand.getDexterity() + 5);
                                counter++;
                                break;
                            default:
                                std::cout << "Wrong input" << '\n';
                        }
                    }

                    /**przeciwnik robi turę**/

                    Enemy.enemyPokemons.back().attack(pokemonAtHand);
                    if(pokemonAtHand.specialSkill->isAlreadyUsed())
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDurationLeft() - 1);
                    if(pokemonAtHand.specialSkill->getDurationLeft()==0) {
                        pokemonAtHand.specialSkill->setDurationLeft(pokemonAtHand.specialSkill->getDuration());
                        pokemonAtHand.specialSkill->setTimesOfUseLeft(pokemonAtHand.specialSkill->getTimesOfUseLeft()-1);
                    }
                    if (!pokemonAtHand.isAlive()) {
                        std::cout << "Your pokemon is UNCONSCIOUS !!!!";
                        /**zwracamy nieprzytomnego pokemona do vektora **/
                        PlayerPokemons.push_back(pokemonAtHand);
                        for (int i = 0; i < PlayerPokemons.size();i++) {
                            if (PlayerPokemons[i].getCurrentHealth() > 0) {
                                /** special skill się kończy wraz ze zmianą pokemona **/
                                if(pokemonAtHand.specialSkill->getTypeOfSkill()==Type_of_skill::OFFENSIVE) {
                                    pokemonAtHand.specialSkill->setValuesBeforUse(Enemy.enemyPokemons.back());
                                }else
                                    pokemonAtHand.specialSkill->setValuesBeforUse(pokemonAtHand);
                                pokemonAtHand = PlayerPokemons[i];
                                PlayerPokemons.erase(PlayerPokemons.begin() + i);
                                break;
                            }

                        }
                    }

                }
                else
                    std::cout << "Can't evlove, you need " << pokemonAtHand.getLvl() * 500 - pokemonAtHand.getExperiencePoints() << " more exp " << '\n';



            }
            break;

            default:
                std::cout << "Wrong input!!!";
            }


    }
        if (Enemy.enemyPokemons.size() < 0)
            std::cout << "CONGRATS YOU WON THIS BATTLE !!!!!" << '\n';
        else {
            std::cout << "YOU LOST :( ";
            exit(0);
        }

        }



    pokemon game::randomPokemon() {

        auto randomNameIndex = std::rand() % names.size();
        std::string name = names[randomNameIndex];
        names.erase(names.begin() + randomNameIndex);

        auto randomType = (std::rand() % 6) + 1;


        int randomStrength = (std::rand() % 50) + 25;
        int randomMaxHealth = (std::rand() % (400 - randomStrength) + 250);
        int randomDexterity = (std::rand() % (100 - randomStrength));

        switch (randomType) {
            case 1 : {
                auto Healing = healing_water("Healing water", 2, Type_of_skill::DEFFENSIVE, 1);
                auto PokemonToReturn = pokemon(name, Type_of_pokemon::WATER, randomStrength, randomDexterity,
                                               randomMaxHealth, new healing_water("Healing water", 2, Type_of_skill::DEFFENSIVE, 1));
                return PokemonToReturn;
                break;
            }
            case 2 : {

                auto PokemonToReturn = pokemon(name, Type_of_pokemon::WATER, randomStrength, randomDexterity,
                                               randomMaxHealth, new earthquake("Earthquake", 2, Type_of_skill::OFFENSIVE, 1));
                return PokemonToReturn;
                break;
            }
            case 3 : {

                auto PokemonToReturn = pokemon(name, Type_of_pokemon::AIR, randomStrength, randomDexterity,
                                               randomMaxHealth, new air_blessing("Air blessing", 2, Type_of_skill::DEFFENSIVE, 2));
                return PokemonToReturn;
                break;
            }
            case 4 : {

                auto PokemonToReturn = pokemon(name, Type_of_pokemon::FIRE, randomStrength, randomDexterity,
                                               randomMaxHealth, new fire_tornado("Fire Tornado", 2, Type_of_skill::OFFENSIVE, 1));
                return PokemonToReturn;
                break;
            }
            case 5 : {

                auto PokemonToReturn = pokemon(name, Type_of_pokemon::ICE, randomStrength, randomDexterity,
                                               randomMaxHealth, new ice_storm("Ice Storm", 2, Type_of_skill::OFFENSIVE, 1));
                return PokemonToReturn;
                break;
            }

            case 6 : {

                auto PokemonToReturn = pokemon(name, Type_of_pokemon::STEEL, randomStrength, randomDexterity,
                                               randomMaxHealth, new gear_up("Gear up", 3, Type_of_skill::DEFFENSIVE, 1));
                return PokemonToReturn;
                break;
            }
        }

        return pokemon(name, Type_of_pokemon::STEEL, randomStrength, randomDexterity,
                           randomMaxHealth, new gear_up("Gear up", 3, Type_of_skill::DEFFENSIVE, 1));
    };


    game::game()
    {

    };

    const std::vector<std::string> &game::getNames() const {
        return names;
    };
