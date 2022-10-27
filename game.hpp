#pragma once

#include <vector>
#include "Pokemons/pokemon.hpp"
#include "enemy.hpp"
#include <ctime>    // losowanie
#include <cstdlib>  // losowanie
#include <set>
#include "Pokemons/pokemon.hpp"
#include "Skills/special_skill.h"
#include "Skills/healing_water.hpp"
#include "Skills/earthquake.hpp"
#include "Skills/air_blessing.hpp"
#include "Skills/fire_tornado.hpp"
#include "Skills/ice_storm.hpp"
#include "Skills/gear_up.hpp"
#include "enemy.hpp"


class game {
    std::vector<enemy> AllEnemies;
    std::vector<pokemon> AllPokemons;
    std::vector<pokemon> PlayerPokemons;
    std::vector<std::string> names = {"Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle",
                                      "Blastoise", "Caterpie", "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill", "Pidgey", "Pidgeotto",
                                      "Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu", "Raichu", "Sandshrew",
                                      "Jolteon", "Flareon", "Porygon", "Omanyte", "Omastar", "Kabuto", "Kabutops", "Aerodactyl", "Snorlax"};
public:
    game();
    void intro();

    pokemon randomPokemon();

    const std::vector<std::string> &getNames() const;

    void pokemonDraw(int amountOfEnemies, int amountOfPokemonsPerEnemy);


    void playerVsEnemy(std::vector<pokemon> &playerPokemons, enemy &Enemy);

    bool anyIsAlive(std::vector<pokemon> &pokemons);


};


