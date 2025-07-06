cmake_minimum_required(VERSION 3.10)
project(orgChartApiTests)

set(CMAKE_CXX_STANDARD 17)

# Enable coverage flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Drogon
find_package(Drogon REQUIRED)
include_directories(${DROGON_INCLUDE_DIRS})

# Include orgChartApi source directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../orgChartApi)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../orgChartApi/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../orgChartApi/utils)

# Automatically find all test source files
file(GLOB TEST_SOURCES "test_*.cpp")

# If no test files found, use the default one
if(NOT TEST_SOURCES)
    set(TEST_SOURCES test_main.cpp)
endif()

# Create executable
add_executable(runTests ${TEST_SOURCES})

# Link libraries
target_link_libraries(runTests PRIVATE 
    Drogon::Drogon 
    GTest::GTest 
    GTest::Main 
    pthread 
    gcov
)

# Enable testing
enable_testing()
add_test(NAME AllTests COMMAND runTests) 