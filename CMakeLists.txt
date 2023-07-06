cmake_minimum_required(VERSION 3.26.0)

project(SUPER_NATE_BOYER)

find_package(SDL2 REQUIRED PATHS libs/)
find_package(SDL2_image REQUIRED PATHS libs/)
find_package(SDL2_mixer REQUIRED PATHS libs/)
find_package(SDL2_ttf REQUIRED PATHS libs/)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp src/window.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include/ ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} SDL2_image SDL2_mixer SDL2_ttf)
