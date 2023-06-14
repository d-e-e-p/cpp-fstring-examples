# cmake test
cmake_minimum_required(VERSION 3.15...3.22)
include(../cmake/common.cmake)

# --- Setup project ---
project(unit_tests LANGUAGES CXX)
common_compiler_settings()
enable_testing()
enable_coverage()


# ---Setup GoogleTest --

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(CMAKE_BUILD_TYPE "Debug")

#FetchContent_MakeAvailable(googletest-src)
CPMAddPackage("gh:google/googletest@1.13.0")

# ---Config Test Src ---
file(GLOB ssources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../src/*/*.cpp)
file(GLOB tsources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../test/*/*.cpp)
message(STATUS "sources = ${ssources} ${tsources} dir=${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${PROJECT_NAME} ${ssources} ${tsources})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE "../include")
target_link_libraries(${PROJECT_NAME} gtest_main gmock_main ${libs}) 
add_test(NAME tests COMMAND ${PROJECT_NAME})

