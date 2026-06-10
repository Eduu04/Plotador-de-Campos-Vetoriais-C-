cmake_minimum_required(VERSION 3.20)
project(plotador_vetorial CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(libs)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(plotador_vetorial
    src/main.cpp
    src/ExternalParserWrapper.cpp
    src/DatasetVetor.cpp
    src/Arrow.cpp
)

target_link_libraries(plotador_vetorial PRIVATE 

    SFML::Graphics
    SFML::Window
    SFML::System
)
