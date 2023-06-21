# debug/release cmake
cmake_minimum_required(VERSION 3.15...3.22)
include(../cmake/common.cmake)

# ---- Setup Project ---
project(examples LANGUAGES ${LANGUAGE}) 
common_compiler_settings()
if (CMAKE_BUILD_TYPE MATCHES Debug)
    enable_sanitizers()
    enable_warnings()
    enable_analyzers()
endif()

# ---- Create libs and standalone example executables ----
#file(GLOB headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../include/*/*.h)
file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/psrc/*.cpp)
file(GLOB headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/psrc/*.h)

#CPMAddPackage("gh:fmtlib/fmt#10.0.0")
find_package(fmt)
cmake_print_properties(TARGETS fmt::fmt PROPERTIES NAME TYPE INTERFACE_INCLUDE_DIRECTORIES)

# ---- Executable ----

# process headers with cpp-fstring
set(headtgts)
foreach(header ${headers})
    get_filename_component(hdr ${header} NAME_WE)
    set(target ${CMAKE_CURRENT_SOURCE_DIR}/src/${hdr}.h)
    add_custom_command( 
        OUTPUT ${target}
        DEPENDS ${header}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND cpp-fstring ${header} -I src -I ../include > ${target}
        VERBATIM
    )
    list(APPEND headtgts ${target})
endforeach()
add_custom_target(gen_headers DEPENDS ${headtgts})

# run cpp source files through cpp-fstring
set(targets)
foreach(source ${sources})
    get_filename_component(src ${source} NAME_WE)
    set(target ${CMAKE_CURRENT_SOURCE_DIR}/src/${src}.cpp)
    add_custom_command( 
        OUTPUT ${target}
        DEPENDS ${source}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        IMPLICIT_DEPENDS
        COMMAND cpp-fstring ${source} -I src -I ../include > ${target}
        VERBATIM
    )
    list(APPEND targets ${target})
endforeach()

# compile processed sources
foreach(target ${targets})
    get_filename_component(tgt ${target} NAME_WE)
    message(STATUS " adding exe ${tgt} from ${target}")
    add_executable(${tgt} ${target})
    target_link_libraries(${tgt} fmt::fmt)
    target_include_directories(${tgt} PRIVATE "../include" "psrc")
    target_compile_features(${tgt} PRIVATE cxx_std_17)
    add_dependencies(${tgt} gen_headers)
endforeach()

# run the produced program
foreach(target ${targets})
    get_filename_component(tgt ${target} NAME_WE)
    add_custom_command(
        TARGET ${tgt}
        POST_BUILD
        COMMAND ${tgt} | tee ${CMAKE_CURRENT_SOURCE_DIR}/out/${tgt}.log 2>&1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERBATIM
    )
endforeach()


