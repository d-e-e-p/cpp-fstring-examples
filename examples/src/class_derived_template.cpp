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
// Generated to_string for PUBLIC CLASS_TEMPLATE M<T>
  public:
  auto to_string() const {
    return fstr::format(R"( M<T>:
    PUBLIC T={} m: {} 
)", typeid(T).name(), m);
  }
};

class N {
  int n = 32;
// Generated to_string for PUBLIC CLASS_DECL N
  public:
  auto to_string() const {
    return fstr::format(R"( N:
    PRIVATE int n: {} 
)", n);
  }
};

class B : public M<bool> { 
  public:
  int b = 13;
// Generated to_string for PUBLIC CLASS_DECL B
  public:
  auto to_string() const {
    return fstr::format(R"( B:
    PUBLIC int b: {} 
)", b);
  }
};

template<class T>
class Base { // Generated to_string for PUBLIC CLASS_TEMPLATE Base<T>
  public:
  auto to_string() const {
    return fstr::format(R"( Base<T>:
)");
  }
};
class X1 : public Base<X1> {};
class Y1 {};
class X2 : public Y1 {};

int main() {
    using std::cout;

    cout << fmt::format(" M<int>()={} ", M<int>());
    cout << fmt::format(" N()={} ", N());
    // TODO(deep): make this print base class M as well
    cout << fmt::format(" B()={} \n", B());
    auto b = B();
    cout << " B() should print both b and m,  b.b:" << b.b << " b.m:" << b.m << " \n";
    
    return 0;
}






