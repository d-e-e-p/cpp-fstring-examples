/**
 * @file class_template1.cpp
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
};

template<auto n>
struct Auto { 
  int v = 1;
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
template<class T>
struct A {
    T a_;
    T b_;
    A(T a, T b) {
      a_ = a;
      b_ = b;
        std::cout << "A<" << typeid(T).name() << "> Constructor: " << a << ", " << b << std::endl;
    }
};


template<int N0,int N1,int N2,int N3>
struct Const {
  // making this static would optimize out v!
	//static const int v = N0 + N1 + N2 + N3;
	int v = N0 + N1 + N2 + N3;
};

/* TODO
template<typename T>
class my_array {};
 
// two type template parameters and one template template parameter:
template<typename K, typename V, template<typename> typename C = my_array>
class Map {
    C<K> key;
    C<V> value;
};
struct A {
    struct B {
      int X;
    };
    int C;
    int Y;
};
 
template<class B>
struct X : A {
    B b; // A's B
};
*/


template <typename T>
struct Pair {
    T first{};
    T second{};
};

// simple non-type template parameter
template<typename T, int N>
struct S {T a[N] = {}; };

enum class Cowboys {good, bad, ugly};

int main() {
  using std::cout;

	Const<1,1,1,1> c;
  auto v = LimitedInt<uint16_t, 0, 4094>(10);
  Auto<'a'> a; 
  //X<A::B> x;
  S<bool,10> s; 
  s.a[9] = true;

  S<Cowboys,10> cb;
  cb.a[0] = Cowboys::bad;
  Pair<double> p{ 7.8, 9.0 };

  cout << "{c=}";
  cout << "{v=}";
  cout << "{a=}";
  cout << "{s=}";
  cout << "{cb=}";
  cout << "{p=}";

  auto y = A{1, 2};
  cout << "{y=}";
  cout << "\n";

}
