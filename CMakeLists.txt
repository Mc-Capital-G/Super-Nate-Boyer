cmake_minimum_required(VERSION 3.26.0)

set_property(GLOBAL PROPERTY CXX_STANDARD C++17)

project(SUPER_NATE_BOYER)

find_package(SDL2 REQUIRED PATHS libs/)
find_package(SDL2_image REQUIRED PATHS libs/)
find_package(SDL2_mixer REQUIRED PATHS libs/)
find_package(SDL2_ttf REQUIRED PATHS libs/)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp src/window.cpp src/inputHandler.cpp src/timer.cpp src/closeSDL.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include/ ${SDL2_INCLUDE_DIRS})

target_link_directories(${PROJECT_NAME} PUBLIC libs/)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf)