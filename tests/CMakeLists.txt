cmake_minimum_required(VERSION 3.10)
project(orgChartApiTests)

set(CMAKE_CXX_STANDARD 17)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Drogon
find_package(Drogon REQUIRED)
include_directories(${DROGON_INCLUDE_DIRS})

# Test sources
set(TEST_SOURCES
    test_main.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests PRIVATE Drogon::Drogon GTest::GTest GTest::Main pthread) 