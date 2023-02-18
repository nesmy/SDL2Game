cmake_minimum_required(VERSION 3.0) 

project(SDL2Game)

file(GLOB SOURCE src/*.cpp)

find_package(SDL2 REQUIRED)

include_directories(${PROJECT_NAME} 
                        PUBLIC ${SDL2_INCLUDE_DIRS}
                        PUBLIC include/)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})