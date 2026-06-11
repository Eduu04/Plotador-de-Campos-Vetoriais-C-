cmake_minimum_required(VERSION 3.20)
project(plotador_vetorial CXX)

if(WIN32 AND CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wa,-mbig-obj)
endif()

add_compile_options(-O2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(libs)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(plotador_vetorial
    src/main.cpp
    src/Parser.cpp
    src/DatasetVetor.cpp
    src/Arrow.cpp

)


target_link_libraries(plotador_vetorial PRIVATE 

    SFML::Graphics
    SFML::Window
    SFML::System
)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Nexa-Heavy.ttf"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
