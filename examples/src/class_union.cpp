/**
 * @file class_union.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
 *   @license MIT License
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "fstr.h"
#include "utils.h"

struct Base {
  int a{};
  union {
    int i;
    double d;
    char c;
    // Generated to_string() for PUBLIC UNION_DECL Base::(unnamed union)
  public:
  auto to_string() const {
    const std::string fmt_string = "Base::(unnamed union): int i={}, double d={}, char c={}";
    return fstr::format(fmt_string, i, d, c);
  }
} u{};
  // Generated to_string() for PUBLIC STRUCT_DECL Base
  public:
  auto to_string() const {
    const std::string fmt_string = "Base: int a={}, u={}";
    return fstr::format(fmt_string, a, u);
  }
} b;

union Onion1 {
  int i;
  double d;
  char c;
  // Generated to_string() for PUBLIC UNION_DECL Onion1
  public:
  auto to_string() const {
    const std::string fmt_string = "Onion1: int i={}, double d={}, char c={}";
    return fstr::format(fmt_string, i, d, c);
  }
} ui{10}, ud{20}, uc{30};

union Onion2 {
  float f;
  char c;
  // Generated to_string() for PUBLIC UNION_DECL Onion2
  public:
  auto to_string() const {
    const std::string fmt_string = "Onion2: float f={}, char c={}";
    return fstr::format(fmt_string, f, c);
  }
};


union Outer {
  Onion1 u1;
  Onion2 u2;
  // Generated to_string() for PUBLIC UNION_DECL Outer
  public:
  auto to_string() const {
    const std::string fmt_string = "Outer: u1={}, u2={}";
    return fstr::format(fmt_string, u1, u2);
  }
} out;


int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);

  cout << fmt::format(" b={} \n", b);
  ui.i = 1;
  ud.d = 4.2;
  uc.c = 'u';
  cout << fmt::format(" ui={}\n ud={}\n uc={}\n", ui, ud, uc);
  cout << fmt::format(" {}\n", out);
}



