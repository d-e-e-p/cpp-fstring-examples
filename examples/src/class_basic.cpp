/**
 * @file class_basic.cpp
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


struct Foo { 
  int a = 32; 
  int b[10] = {}; 
// Generated to_string for PUBLIC STRUCT_DECL Foo
  public:
  auto to_string() const {
    return fstr::format(R"( Foo:
    PUBLIC int a: {} 
    PUBLIC int[10] b: {} 
)", a, b);
  }
};

struct Bar {
    char name[50] = "foo" ;
    int i = 10;
    double f = 3.14;
    Foo foo;
// Generated to_string for PUBLIC STRUCT_DECL Bar
  public:
  auto to_string() const {
    return fstr::format(R"( Bar:
    PUBLIC char[50] name: {} 
    PUBLIC int i: {} 
    PUBLIC double f: {} 
    PUBLIC Foo foo: {} 
)", name, i, f, foo);
  }
};

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area (void);
    Bar bar;
// Generated to_string for PUBLIC CLASS_DECL Rectangle
  public:
  auto to_string() const {
    return fstr::format(R"( Rectangle:
    PRIVATE int width: {} 
    PRIVATE int height: {} 
    PUBLIC Bar bar: {} 
)", width, height, bar);
  }
} rect;

int main()
{
    struct Local {
      int x = 0;    
    };

    Rectangle r;
    std::cout << fmt::format(" Rectangle r={} \n", r);
}



