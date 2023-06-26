/*
 *  common utils
 *
 */ 

#pragma once

#include <iostream>
#include <filesystem>

// unfortunately __FILE_NAME__ is only supported by clang and recent gcc ...
// so we're forced to call basename
inline void print_info(const char* filename, const char* timestamp) {
    const std::filesystem::path path(filename);
    auto basename = path.filename().string();
    std::cout << "file: " << basename << "\ntime: " << timestamp << "\n";
}


