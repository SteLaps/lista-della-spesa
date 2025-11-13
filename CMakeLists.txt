cmake_minimum_required(VERSION 3.28)
project(lista_della_spesa)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista_della_spesa main.cpp
        Observer.h
        Subject.h
        DataDiScadenza.h
        Oggetto.h
        Oggetto.cpp
        Lista.cpp
        Lista.h)
