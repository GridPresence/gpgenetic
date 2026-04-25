cmake_minimum_required(VERSION 3.30)
project(GPGenetic)

add_library(gpgenetic
    src/Gene.cpp
)

target_include_directories(gpgenetic
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)