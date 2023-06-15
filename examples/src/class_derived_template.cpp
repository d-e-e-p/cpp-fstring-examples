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

  friend class B;
// Generated to_string for PUBLIC CLASS_DECL A
  public:
  auto to_string() const {
    return fstr::format(R"( A:
    PRIVATE int a: {} 
)", a);
  }
};

class B : public A { 
  int b = 13;
// Generated to_string for PUBLIC CLASS_DECL B
  public:
  auto to_string() const {
    return fstr::format(R"( B:
    PRIVATE int b: {} 
     PRIVATE int a: {} 
)", b, this->a);
  }
};


template <typename T> class X {
  public:
  T x;
// Generated to_string for PUBLIC CLASS_TEMPLATE X<T>
  public:
  auto to_string() const {
    return fstr::format(R"( X<T>:
    PUBLIC T={} x: {} 
)", typeid(T).name(), x);
  }
};

class Y : public X<bool> { 
  int y = 13;
// Generated to_string for PUBLIC CLASS_DECL Y
  public:
  auto to_string() const {
    return fstr::format(R"( Y:
    PRIVATE int y: {} 
)", y);
  }
};

int main() {
    using std::cout;

    // should print both a and b
    cout << fmt::format(" B()={} \n", B());

    cout << fmt::format(" X<int>()={} ", X<int>());
    cout << fmt::format(" X<bool>()={} ", X<bool>());
    cout << fmt::format(" X<std::string>()={} ", X<std::string>());
    cout << fmt::format(" Y()={} ", Y());
    auto y = Y();
    cout << " Y() should print both y and x="  << y.x << " \n";
    
    return 0;
}






