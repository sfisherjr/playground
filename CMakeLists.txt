cmake_minimum_required(VERSION 3.17)
project(playground)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(SOURCES main.cpp)

add_subdirectory(src)
add_subdirectory(resources)

add_executable(playground ${SOURCES} ${HEADERS})

target_link_libraries(playground PRIVATE sfml-system sfml-window sfml-graphics)

# If you want SFML to provide an implementation of main():
# target_link_libraries(playground PRIVATE sfml-main)