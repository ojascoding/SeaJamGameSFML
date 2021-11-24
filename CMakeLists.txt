cmake_minimum_required(VERSION 3.14)
project(SeaJamGameSFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_OSX_ARCHITECTURES "arm64")

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h "src/Button.cpp" "src/Button.h" src/UI.cpp src/UI.h src/ShopMenu.cpp src/ShopMenu.h)
add_executable(SeaJamGameSFML ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SeaJamGameSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
