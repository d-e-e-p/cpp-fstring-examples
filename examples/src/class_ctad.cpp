/**
 * @file class_ctad.cpp
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

// from https://stackoverflow.com/questions/65781641/im-trying-to-format-a-template-using-fmt
template <typename T, T Min, T Max>
class LimitedInt {
   T mValue{Min};
public:
   explicit LimitedInt(const T value) {
      setValue(value);
   }
   void setValue(const T value) {
      mValue = value;
   }
   T getValue() const {
      return mValue;
   }
// Generated to_string for PUBLIC CLASS_TEMPLATE LimitedInt<T, Min, Max>
  public:
  auto to_string() const {
    return fstr::format(R"( LimitedInt<T, Min, Max>:
    PRIVATE T={} mValue: {} 
)", typeid(T).name(), mValue);
  }
};

template<auto n>
struct Auto { 
  int v = 1;
// Generated to_string for PUBLIC CLASS_TEMPLATE Auto<n>
  public:
  auto to_string() const {
    return fstr::format(R"( Auto<n>:
    PUBLIC int v: {} 
)", v);
  }
};

/* TODO

template <auto... Values>
struct ValueList {
    static constexpr auto values = std::array{Values...};

    static void print() {
        for (const auto& value : values) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
};
ValueList<42, 'A'>vl;
*/

// from https://en.cppreference.com/w/cpp/language/class_template_argument_deduction
//
//
template<class T>
struct A {
    T t;
 
    struct {
        long a, b;
    } u;
// Generated to_string for PUBLIC CLASS_TEMPLATE A<T>
  public:
  auto to_string() const {
    return fstr::format(R"( A<T>:
    PUBLIC T={} t: {} 
     PUBLIC long u.a: {} 
     PUBLIC long u.b: {} 
)", typeid(T).name(), t, this->u.a, this->u.b);
  }
};
 
A<int> a{1,{2,4}};

template<class T>
struct B {
    T a, b;
// Generated to_string for PUBLIC CLASS_TEMPLATE B<T>
  public:
  auto to_string() const {
    return fstr::format(R"( B<T>:
    PUBLIC T={} a: {} 
    PUBLIC T={} b: {} 
)", typeid(T).name(), a, typeid(T).name(), b);
  }
};
auto b = B<int>{1, 2};



int main() {
  using std::cout;

  cout << fmt::format("a={} b={}", a, b);
  cout << "\n";

}



