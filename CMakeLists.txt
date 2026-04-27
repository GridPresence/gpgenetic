cmake_minimum_required(VERSION 3.30)
project(GPGenetic)

file(GLOB_RECURSE lib_SOURCES "src/*.cpp")
file(GLOB_RECURSE test_SOURCES "test/*.cpp")

add_library(gpgenetic
    ${lib_SOURCES}
)

target_include_directories(gpgenetic
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)