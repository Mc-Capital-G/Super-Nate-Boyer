cmake_minimum_required(VERSION 3.26.0)

set_property(GLOBAL PROPERTY CXX_STANDARD C++17)

project(SUPER_NATE_BOYER)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf)

set_target_properties(${PROJECT_NAME} 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/Super Nate Boyer"
    )
file(GLOB_RECURSE ASSET_FILES assets/*)
file(COPY ${ASSET_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/bin/Super Nate Boyer/assets")