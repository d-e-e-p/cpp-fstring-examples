/**
 * @file class_namespace1.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
   @license MIT License
*/
#include <iostream>
#include "fstr.h"

// Anonymous Class : Class is not having any name
struct {
    int i; 
} obj0;

struct Base {
    int i; 
// Generated to_string for PUBLIC STRUCT_DECL Base
  public:
  auto to_string() const {
    return fstr::format(R"( Base:
    PUBLIC int i: {} 
)", i);
  }
};

namespace a::b::c {
struct enclose {
  struct outer {
    struct inner {
      static int x;
      int y;
      Base b;
    // Generated to_string for PUBLIC STRUCT_DECL a::b::c::enclose::outer::inner
  public:
  auto to_string() const {
    return fstr::format(R"( a::b::c::enclose::outer::inner:
    PUBLIC int x: {} 
    PUBLIC int y: {} 
    PUBLIC Base b: {} 
)", x, y, b);
  }
} foo;
   // Generated to_string for PUBLIC STRUCT_DECL a::b::c::enclose::outer
  public:
  auto to_string() const {
    return fstr::format(R"( a::b::c::enclose::outer:
    PUBLIC struct inner foo: {} 
)", foo);
  }
} bar;
// Generated to_string for PUBLIC STRUCT_DECL a::b::c::enclose
  public:
  auto to_string() const {
    return fstr::format(R"( a::b::c::enclose:
    PUBLIC struct outer bar: {} 
)", bar);
  }
} obj1;

} // end namespace a::b::c
int a::b::c::enclose::outer::inner::x = 42; 

int main() {
    a::b::c::obj1.bar.foo.y = 24;
    std::cout << fmt::format(" a::b::c::obj1={} \n", a::b::c::obj1);
    return 0;
}



