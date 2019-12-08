cmake_minimum_required(VERSION 3.15)
project(PSZT1)

set(CMAKE_CXX_STANDARD 14)

set(sources
        main.cpp
        WycieczkaObjazdowa.cpp
        ObslugaPlikow.cpp
        AlgorytmEwolucyjny.cpp
        Populacja.cpp
        Test.cpp)

add_executable(PSZT1 ${sources})