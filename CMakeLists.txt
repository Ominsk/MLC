cmake_minimum_required(VERSION 3.16)
project(BMLC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O3 -mavx")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

# Libraries google test and google benchmark
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG master) # need master for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

# Test
enable_testing()
add_executable(
        main_test
        test/test.cpp
)



add_executable(
        main
        src/main.cpp
)


target_link_libraries(
        main_test
        gtest_main
)


## change this if you install google benchmark not in home directory
target_link_libraries(main PUBLIC benchmark benchmark_main pthread)
target_link_directories(main PUBLIC ~/benchmark/build/src)
target_include_directories(main PUBLIC
        ~/benchmark/include)

include(GoogleTest)
gtest_discover_tests(main_test)
