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
#include <string>

#include "fstr.h"

// set1
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


// set2
#include <map>
#include <vector>
template<typename T>
struct Obj {
    T value;
// Generated to_string for PUBLIC CLASS_TEMPLATE Obj<T>
  public:
  auto to_string() const {
    return fstr::format(R"( Obj<T>:
    PUBLIC T={} value: {} 
)", typeid(T).name(), value);
  }
};

template<typename K, typename T>
struct Map {
  std::map<K, T> map1;
  std::map<K, Obj<T>> map2;
  // map3 is not found by libclang
  std::map<K, std::vector<Obj<T>>> map3;
// Generated to_string for PUBLIC CLASS_TEMPLATE Map<K, T>
  public:
  auto to_string() const {
    return fstr::format(R"( Map<K, T>:
    PUBLIC int map1: {} 
    PUBLIC int map2: {} 
)", map1, map2);
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
    // TODO(deep): fix derived template class missing vars
    cout << " Y() should print both y and x="  << y.x << " \n";

    Map<std::string, int> m;
    m.map1["key1"] = 100;
    m.map1["key2"] = 200;

    m.map2["key3"] = {300};
    m.map2["key4"] = {500};

    m.map3["key5"] = {{600}};
    m.map3["key6"] = {{700}, {800}};

    // TODO(deep): fix derived template class missing map3 
    // TODO(deep): map2 print is very ugly
    cout << fmt::format("Map m={}", m);
    
    return 0;
}






