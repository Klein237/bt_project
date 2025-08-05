cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0074 NEW)  # Assure que CMake utilise les bonnes variables

project(bt_three_color)

# Définir la version de C++ (BehaviorTree.CPP nécessite C++14 ou supérieur)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(behaviortree_cpp REQUIRED)


# Ajouter les fichiers sources
set(SOURCES
    src/pedestrianrequest.cpp 
    src/triggerlight.cpp
    src/main.cpp
)

#include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/include)


# Créer l'exécutable
add_executable(three_color
    ${SOURCES}
   )


# Lier BehaviorTree.CPP et ses dépendances
target_link_libraries(three_color
    PRIVATE
    behaviortree_cpp
)
