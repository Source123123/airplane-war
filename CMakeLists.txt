cmake_minimum_required(VERSION 3.15)
project(AirplaneWar)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3.0.0 COMPONENTS Graphics Window System REQUIRED)
include_directories(${SFML_INCLUDE_DIRS} /opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable(AirplaneWar
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/BossEnemy.cpp
    src/MinionEnemy.cpp
    src/ResourceManager.cpp
    src/CollisionGrid.cpp
)

target_include_directories(AirplaneWar PRIVATE include ${SFML_INCLUDE_DIRS})

target_link_libraries(AirplaneWar sfml-graphics sfml-window sfml-system)