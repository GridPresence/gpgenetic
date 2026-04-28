cmake_minimum_required(VERSION 3.30)
project(GPGenetic)

find_package(Catch2 3 REQUIRED)

include(CTest)
include(Catch)
include(GNUInstallDirs)

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

set_target_properties(gpgenetic PROPERTIES PUBLIC_HEADER Gene.hpp)
install(PUBLIC_HEADER include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


add_executable(gpgenetic-test ${test_SOURCES})
target_link_libraries(gpgenetic-test PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(gpgenetic-test)