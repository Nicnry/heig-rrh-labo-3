cmake_minimum_required(VERSION 3.17)
project(heig_rrh_labo_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(heig_rrh_labo_3 main.cpp
        calculsDeDate.h calculsDeDate.cpp saisieUtilisateur.h affichageConsole.h
        saisieUtilisateur.cpp affichageConsole.cpp)