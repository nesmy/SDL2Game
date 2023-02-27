cmake_minimum_required(VERSION 3.0) 

set(SDL2_DIR "vendor/SDL2/cmake")
set(SDL2_image_DIR "vendor/SDL2/cmake")
set(SDL2_ttf_DIR "vendor/SDL2/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}vendor/SDL2/cmake")

project(SDL2Game)

file(GLOB SOURCE src/*.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${PROJECT_NAME} 
                        PUBLIC ${SDL2_INCLUDE_DIRS}
                        PUBLIC include/)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} 
                                      ${SDL2_IMAGE_LIBRARIES}
                                      SDL2_image
                                      SDL2_ttf)