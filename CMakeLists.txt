cmake_minimum_required(VERSION 3.30)
project(GPGenetic)

find_package(Catch2 3 REQUIRED)

include(CTest)
include(Catch)
include(GNUInstallDirs)

file(GLOB_RECURSE lib_SOURCES "src/*.cpp")
file(GLOB_RECURSE test_SOURCES "test/*.cpp")
file(GLOB_RECURSE evapp_SOURCES "app/evolve-iir.cpp")
file(GLOB_RECURSE sarge_SOURCES "app/sarge-test.cpp")

include_directories("${CMAKE_SOURCE_DIR}/include")


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

# set_target_properties(gpgenetic PROPERTIES PUBLIC_HEADER Gene.hpp)
# install(TARGETS include/ PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


add_executable(gpgenetic-test ${test_SOURCES})
target_link_libraries(gpgenetic-test PUBLIC gpgenetic PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(gpgenetic-test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test/test01.json ${CMAKE_CURRENT_BINARY_DIR}/test01.json COPYONLY)

add_executable(sarge-test ${sarge_SOURCES})
target_link_libraries(sarge-test PUBLIC gpgenetic)

add_executable(evolve-iir ${evapp_SOURCES})
target_link_libraries(evolve-iir PUBLIC gpgenetic)