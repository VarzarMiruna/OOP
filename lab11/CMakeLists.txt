cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SortingAlgorithmTest)

# Add GoogleTest
add_subdirectory(googletest)

include_directories(googletest/googletest/include googletest/googlemock/include src)

# Add the sources
add_executable(test_student_a tests/test_student_a.cpp)
add_executable(test_student_b tests/test_student_b.cpp)

# Link GoogleTest to the tests
target_link_libraries(test_student_a gtest gtest_main)
target_link_libraries(test_student_b gtest gtest_main)
