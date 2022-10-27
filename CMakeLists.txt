cmake_minimum_required(VERSION 3.21)
project(gra_turowa)

set(CMAKE_CXX_STANDARD 23)

add_executable(gra_turowa main.cpp Pokemons/pokemon.cpp Skills/special_skill.cpp Skills/special_skill.h Pokemons/pokemon.hpp Skills/healing_water.cpp Skills/healing_water.hpp Skills/fire_tornado.cpp Skills/fire_tornado.hpp Skills/air_blessing.cpp Skills/air_blessing.hpp Skills/ice_storm.cpp Skills/ice_storm.hpp Skills/earthquake.cpp Skills/earthquake.hpp Skills/gear_up.cpp Skills/gear_up.hpp game.cpp game.hpp enemy.cpp enemy.hpp)
