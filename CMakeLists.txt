cmake_minimum_required(VERSION 3.21)
project(hw4)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw4 main.cpp
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
        )
