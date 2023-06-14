/**
 * @file class_union.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
   @license MIT License
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "fstr.h"

struct Base { 
  int a; 
  union {
    int i;
    double d;
    char c;
  } u;
// Generated to_string for PUBLIC STRUCT_DECL Base
  public:
  auto to_string() const {
    return fstr::format(R"( Base:
    PUBLIC int a: {} 
)", a);
  }
} b;


union Onion {
  int i;
  double d;
  char c;
// Generated to_string for PUBLIC UNION_DECL Onion
  public:
  auto to_string() const {
    return fstr::format(R"( Onion:
    PUBLIC int i: {} 
    PUBLIC double d: {} 
    PUBLIC char c: {} 
)", i, d, c);
  }
} u;


int main()
{
    std::cout << fmt::format(" b={} \n", b);

    u.i = 10;
    u.d = 4.2;
    u.c = 'u';
    std::cout << "u.i = " << u.i <<  " u.d = " << u.d <<  " u.c = " << u.c << " \n";
    std::cout << fmt::format(" u={} \n", u);
}



