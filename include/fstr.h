/**
 * @file fstr.h
 * Companion utilities for cpp-fstring, which brings python-style fstring to C++
 *
 * This file contains 2 different routines:
 *   1. If a class has a member function called to_string(void), then a custom formatter is inferred for
 *   that class giving fmt::format the ability to display the stringified version of that class.
 *   the cpp-fstring routine from https://github.com/d-e-e-p/cpp-fstring automatically generates these
 *   to_string() calls. eg loading fstr.h allows fmt::print to format Foo using it's to_string() function:
 *
 *   @code{.cpp}
 *      #include "fstr.h"
 *      struct Foo {
 *        int a = 32;
 *        auto to_string() const {
 *          return fstr::format(R"( Foo: PUBLIC int a: {})", a);
 *        }
 *      };
 *      Foo f;
 *      fmt::print("f={}\n", f);
 *   @endcode
 *
 *   produces the result:
 *
 *   @code{.sh}
 *    Foo: PUBLIC int a: 32
 *   @endcode
 *
 *   2. fstr::format is a wrapper around fmt::format that tries to skip unformattable entries, replacing
 *   them with "<unknown>" .  Does not currently support range specifications. eg:
 *
 *   @code{.cpp}
 *      int main() {
 *        int i = 0;
 *        std::vector<int> v{1,3,4};
 *        int a[10] = {};
 *        enum class example {yes, no};
 *        example e = example::yes;
 *
 *        std::cout << fstr::format("i={}, v={}, a={}, e={}\n", i, v, a, e);
 *      }
 *   @endcode
 *
 *   produces the result:
 *
 *   @code{.sh}
 *   i=0, v=[1, 3, 4], a=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], e=<unknown>
 *   @endcode
 *
 * @defgroup fstring-include
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag> All rights reserved.
   @license MIT License
*/

#pragma once

#include <string>
#include <type_traits>
#include <typeinfo>

#include <fmt/ranges.h>
#include <fmt/std.h>
#include <fmt/xchar.h>

#ifdef _MSC_VER
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#else
#include <cxxabi.h>
#endif

namespace fstr {

// return typename in human readable form (demangle)
void _remove_substring (std::string& str, const std::string& substr) {
    size_t pos = str.find(substr);
    while (pos != std::string::npos) {
        str.erase(pos, substr.length());
        pos = str.find(substr, pos);
    }
}

// get unmangled name for template or variable types
template <typename T>
std::string get_type_name() {
    const char* mangledName = typeid(T).name();
    std::string result;

#ifdef _MSC_VER
    // Using __unDName for Microsoft Visual C++
    DWORD bufferSize = 1024;
    std::unique_ptr<char[]> buffer(new char[bufferSize]);
    DWORD status = 0;
    if (UnDecorateSymbolName(mangledName, buffer.get(), bufferSize, UNDNAME_COMPLETE) != 0) {
        result = buffer.get();
    } else {
        result = mangledName;
    }
#else
    // Using abi::__cxa_demangle for other compilers
    int status = 0;
    std::unique_ptr<char, decltype(&std::free)> demangledName{
        abi::__cxa_demangle(mangledName, nullptr, nullptr, &status),
        std::free
    };
    result = (status == 0) ? demangledName.get() : mangledName;
#endif
    // std::__1::char_traits -> char_traits
    _remove_substring(result, "std::__1::");
    // basic_string<char, char_traits<char>, allocator<char>> -> basic_string
    _remove_substring(result, "<char, char_traits<char>, allocator<char>>");
    _remove_substring(result, "<char, char_traits<char>, allocator<char> >");

    return result;
}

// Helper function to check if a type has a to_string member function
template <typename T>
constexpr auto has_to_string(int)
    -> decltype(std::declval<T>().to_string(), std::true_type{});

template <typename T>
constexpr auto has_to_string(...) -> std::false_type;


// safe format returns <unknown> string for un-formattable variables
// return param if it's formattable, else return <unknown> atring.
template <typename T>
auto safe_format(const T& value) -> std::string {
  if constexpr (fmt::is_formattable<T>::value) {
    return fmt::to_string(value); 
  } else {
    return "<unknown>";
  }
}

// Inspect all format args for fmt:: formattability
// TODO(deep): deal with unformattable entries with format spec expecting integers or floats
template <typename... Args>
std::string format(const std::string& fmt_string, const Args&... args) {
  return fmt::format(fmt_string, safe_format(args)...);
}

} // namespace fstr

// Custom formatter for classes and structs with a to_string member function
namespace fmt {
template <typename T>
struct formatter <T, char, std::enable_if_t<decltype(fstr::has_to_string<T>(0))::value>> {
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
    template <typename FormatContext>
    auto format(const T& obj, FormatContext& ctx) const {
        // Call the to_string function and format the resulting string
        return fmt::format_to(ctx.out(), obj.to_string());
    }
};
} // namespace fmt
