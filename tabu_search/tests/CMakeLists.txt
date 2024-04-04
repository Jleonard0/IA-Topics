cmake_minimum_required( VERSION 3.5 )

project( tests CXX )

set(TESTS_LIBS_INCLUDE_DIR "libs")

set(LIBS_INCLUDE_DIR "../src/libs")

set(SOURCE_FILES 
    tests.cpp
)

add_executable(tests ${SOURCE_FILES} ${TESTS_LIBS_INCLUDE_DIR}/catch.hpp ${LIBS_INCLUDE_DIR}/Graph.hpp)

target_include_directories(tests PRIVATE ${TESTS_LIBS_INCLUDE_DIR})
target_include_directories(tests PRIVATE ${LIBS_INCLUDE_DIR})

target_compile_features(tests PRIVATE cxx_std_11)