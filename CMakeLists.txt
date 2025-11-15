cmake_minimum_required(VERSION 3.28)
project(lista_della_spesa)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista_della_spesa main.cpp Observer.h Subject.h DataDiScadenza.h Oggetto.h
        Oggetto.cpp Lista.cpp Lista.h Utente.h Utente.cpp)

add_subdirectory(test)

set(SOURCE_FILES Observer.h Subject.h DataDiScadenza.h Oggetto.h Oggetto.cpp Lista.cpp
        Lista.h Utente.h Utente.cpp)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} core)