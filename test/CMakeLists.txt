# cmake test
cmake_minimum_required(VERSION 3.15...3.22)
include(../cmake/common.cmake)

# --- Setup project ---
project(unit_tests LANGUAGES CXX)
common_compiler_settings()
enable_testing()


# ---Setup GoogleTest --

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(CMAKE_BUILD_TYPE "Debug")

#FetchContent_MakeAvailable(googletest-src)
CPMAddPackage("gh:google/googletest@1.13.0")

find_package(fmt)
cmake_print_properties(TARGETS fmt::fmt PROPERTIES NAME TYPE INTERFACE_INCLUDE_DIRECTORIES)

# ---- Include  ------
file(GLOB headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/psrc/*.h)

set(headtgts)
foreach(header ${headers})
    get_filename_component(hdr ${header} NAME_WE)
    set(target ${CMAKE_CURRENT_SOURCE_DIR}/src/${hdr}.h)
    add_custom_command(
        OUTPUT ${target}
        DEPENDS ${header}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND cpp-fstring ${header} -I ../include > ${target}
        VERBATIM
    )
    list(APPEND headtgts ${target})
endforeach()
add_custom_target(gen_headers DEPENDS ${headtgts})

# ---- Executable ----
file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/psrc/*.cpp)
set(targets)
foreach(source ${sources})
    get_filename_component(src ${source} NAME_WE)
    set(target ${CMAKE_CURRENT_SOURCE_DIR}/src/${src}.cpp)
    message(STATUS " adding test ${target}")
    add_custom_command( 
        OUTPUT ${target}
        DEPENDS ${source}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND cpp-fstring ${source} -I src -I psrc -I ../include > ${target}
        VERBATIM
    )
    list(APPEND targets ${target})
endforeach()


# ---Config Test Src ---
add_executable(${PROJECT_NAME} ${targets})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE "../include")
target_link_libraries(${PROJECT_NAME} gtest_main gmock_main fmt::fmt) 
add_dependencies(${PROJECT_NAME} gen_headers)

add_test(NAME tests COMMAND ${PROJECT_NAME})
