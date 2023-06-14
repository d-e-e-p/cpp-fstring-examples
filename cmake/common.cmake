#
# shared by all cmake runs
#

# --- Vars  -----------

set(PROJECT cpp_fstring_example)
set(VERSION 0.0.1)
set(LANGUAGE CXX)
set(DESCRIPTION "Example of using f-string in C++")
set(HOMEPAGE_URL " ")

# --- Import tools ----

include(CMakePrintHelpers)

# prefer actual filenames over CMAKE_MODULE_PATH + magic include
set(dir ${CMAKE_CURRENT_LIST_DIR})

include(${dir}/Utils.cmake)
include(${dir}/CompilerWarnings.cmake)
include(${dir}/StaticAnalyzers.cmake)
include(${dir}/CompilerSettings.cmake)

download_CPM_cmake()
include(${dir}/CPM.cmake)

include(${dir}/Sanitizers.cmake)
include(${dir}/Coverage.cmake)

# ---- settings --------
set(CPM_SOURCE_CACHE "${dir}/../.cache/CPM") # store all downloaded packages

# at flag at compile time in Debug config
#add_compile_definitions("$<$<NOT:$<CONFIG:Debug>>:NDEBUG>")

# --- Import tools ----
# CPMAddPackage("gh:TheLartians/Ccache.cmake@1.2.3")


