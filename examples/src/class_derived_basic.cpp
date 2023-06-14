/**
 * @file class_derived_basic.cpp
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
  std::string bname = "base";
  int a = 4; 
// Generated to_string for PUBLIC STRUCT_DECL Base
  public:
  auto to_string() const {
    return fstr::format(R"( Base:
    PUBLIC int bname: {} 
    PUBLIC int a: {} 
)", bname, a);
  }
};

struct Foo {
  char name[50] = "foo" ;
  Base b;
// Generated to_string for PUBLIC STRUCT_DECL Foo
  public:
  auto to_string() const {
    return fstr::format(R"( Foo:
    PUBLIC char[50] name: {} 
    PUBLIC Base b: {} 
)", name, b);
  }
};

struct Bar: Base {
  char name[50] = "bar" ;
// Generated to_string for PUBLIC STRUCT_DECL Bar
  public:
  auto to_string() const {
    return fstr::format(R"( Bar:
    PUBLIC char[50] name: {} 
     PUBLIC int bname: {} 
     PUBLIC int a: {} 
)", name, this->bname, this->a);
  }
};


int main()
{
  Foo f;
  Bar b;
  std::cout << fmt::format(" f={} b={} \n", f, b);
}



