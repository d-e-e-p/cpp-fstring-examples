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
};

struct Bar {
    char name[50] = "foo" ;
    int i = 10;
    double f = 3.14;
    Foo foo;
};

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area (void);
    Bar bar;
} rect;

int main()
{
    struct Local {
      int x = 0;    
    };

    Rectangle r;
    std::cout << " Rectangle {r=} \n";
}
