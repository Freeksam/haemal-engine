cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(haemal-engine VERSION 1.0)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(haemal ${SRC_FILES})
target_include_directories(haemal PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${SDL_INCLUDE_DIRS})

target_link_libraries(haemal PUBLIC 
                           ${SDL2_LIBRARIES} 
                           ${SDL2_DEPENDENCIES}
                           m)
