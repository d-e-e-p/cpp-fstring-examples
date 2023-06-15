/**
 * @file class_derived_template.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
   @license MIT License
*/
// from https://stackoverflow.com/questions/41333185/python-clang-getting-template-arguments
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "fstr.h"


class A {
  int a = 32;
};

class B : public A { 
  int b = 13;
};


template <typename T> class X {
  public:
  T x;
};

class Y : public X<bool> { 
  int y = 13;
};

int main() {
    using std::cout;

    // should print both a and b
    cout << " {B()=} \n";

    cout << " {X<int>()=} ";
    cout << " {X<bool>()=} ";
    cout << " {X<std::string>()=} ";
    cout << " {Y()=} ";
    auto y = Y();
    cout << " Y() should print both y and x="  << y.x << " \n";
    
    return 0;
}



