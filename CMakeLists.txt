cmake_minimum_required(VERSION 3.20.2)
project(hw4)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw4
        main.cpp
        #test.cpp
        Players/Fighter.cpp
        Players/Fighter.h
        Players/Player.h
        Players/Player.cpp
        Players/Wizard.cpp
        Players/Wizard.h
        Players/Rogue.cpp
        Players/Rogue.h
        utilities.h
        utilities.cpp
        Exception.h
        Cards/Card.h
        Cards/Card.cpp
        Mtmchkin.h
        Cards/Monster.h Cards/Goblin.cpp Cards/Goblin.h Cards/Monster.cpp Cards/Vampire.cpp Cards/Vampire.h Cards/Dragon.cpp Cards/Dragon.h Cards/Pitfall.cpp Cards/Pitfall.h Cards/Fairy.cpp Cards/Fairy.h Cards/Barfight.cpp Cards/Barfight.h Cards/Treasure.cpp Cards/Treasure.h Cards/Merchant.cpp Cards/Merchant.h)
