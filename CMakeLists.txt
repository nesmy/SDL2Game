cmake_minimum_required(VERSION 3.0)
SET(CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")

project(OpenGL)

file(GLOB SOURCE src/*cpp)

include_directories(${PROJECT_NAME}
                        PUBLIC include/)
                        
add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/Glad)

target_include_directories(${PROJECT_NAME}
                                PUBLIC vendor/GLFW/include
                                PUBLIC vendor/Glad/include
                                PUBLIC vendor/glm)

target_link_directories(${PROJECT_NAME}
                            PUBLIC vendor/GLFW/src
                            PUBLIC vendor/Glad/src)

target_link_libraries(${PROJECT_NAME}
                            ${OPENGL_LIBRARIES}
                            glfw
                            glad)