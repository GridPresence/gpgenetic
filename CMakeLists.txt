cmake_minimum_required(VERSION 3.30)
project(GPGenetic)

find_package(Catch2 REQUIRED)

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

install (TARGETS gpgenetic DESTINATION lib)

add_executable(gpgenetic-test ${test_SOURCES})
target_link_libraries(gpgenetic-test gpgenetic Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(gpgenetic-test)