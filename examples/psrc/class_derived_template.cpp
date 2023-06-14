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

template <typename T> class M {
  public:
  T m;
};

class N {
  int n = 32;
};

class B : public M<bool> { 
  public:
  int b = 13;
};

template<class T>
class Base { };
class X1 : public Base<X1> {};
class Y1 {};
class X2 : public Y1 {};

int main() {
    using std::cout;

    cout << " {M<int>()=} ";
    cout << " {N()=} ";
    // TODO(deep): make this print base class M as well
    cout << " {B()=} \n";
    auto b = B();
    cout << " B() should print both b and m,  b.b:" << b.b << " b.m:" << b.m << " \n";
    
    return 0;
}



