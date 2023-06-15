/**
 * @file class_namespace2.cpp
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

//
// test classes in different hier and namespaces...
//

namespace A {
    template <typename T>
    class Base {
    public:
        T x;
    // Generated to_string for PUBLIC CLASS_TEMPLATE A::Base<T>
  public:
  auto to_string() const {
    return fstr::format(R"( A::Base<T>:
    PUBLIC T={} x: {} 
)", typeid(T).name(), x);
  }
};

    template <typename T>
    class Derived : public Base<T> {
    public:
        T y;
    // Generated to_string for PUBLIC CLASS_TEMPLATE A::Derived<T>
  public:
  auto to_string() const {
    return fstr::format(R"( A::Derived<T>:
    PUBLIC T={} y: {} 
     PUBLIC T={} x: {} 
)", typeid(T).name(), y, typeid(T).name(), this->x);
  }
};
}


// from https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170
// test inline namespace
namespace Test {
    namespace old_ns {
        auto Func() { return std::string("Hello from old"); }
        struct S { int a{0}; // Generated to_string for PUBLIC STRUCT_DECL Test::old_ns::S
  public:
  auto to_string() const {
    return fstr::format(R"( Test::old_ns::S:
    PUBLIC int a: {} 
)", a);
  }
} s;
    }

    inline namespace new_ns {
        auto Func() { return std::string("Hello from new"); }
        struct S { int a{1}; // Generated to_string for PUBLIC STRUCT_DECL Test::new_ns::S
  public:
  auto to_string() const {
    return fstr::format(R"( Test::new_ns::S:
    PUBLIC int a: {} 
)", a);
  }
} s;
    }
}

//
// from https://devdocs.io/cpp/language/derived_class
struct Base0 {
    int a, b , base0;
// Generated to_string for PUBLIC STRUCT_DECL Base0
  public:
  auto to_string() const {
    return fstr::format(R"( Base0:
    PUBLIC int a: {} 
    PUBLIC int b: {} 
    PUBLIC int base0: {} 
)", a, b, base0);
  }
};

struct Base1 {
    int c, d , base1;
// Generated to_string for PUBLIC STRUCT_DECL Base1
  public:
  auto to_string() const {
    return fstr::format(R"( Base1:
    PUBLIC int c: {} 
    PUBLIC int d: {} 
    PUBLIC int base1: {} 
)", c, d, base1);
  }
};

// every object of type Derived includes Base as a subobject
struct Derived0 : Base0 {
    int a {10}, derived0;
// Generated to_string for PUBLIC STRUCT_DECL Derived0
  public:
  auto to_string() const {
    return fstr::format(R"( Derived0:
    PUBLIC int a: {} 
    PUBLIC int derived0: {} 
     PUBLIC int b: {} 
     PUBLIC int base0: {} 
)", a, derived0, this->b, this->base0);
  }
};

struct Derived1 : Base1 {
    int c {21}, derived1;
// Generated to_string for PUBLIC STRUCT_DECL Derived1
  public:
  auto to_string() const {
    return fstr::format(R"( Derived1:
    PUBLIC int c: {} 
    PUBLIC int derived1: {} 
     PUBLIC int d: {} 
     PUBLIC int base1: {} 
)", c, derived1, this->d, this->base1);
  }
};


// every object of type Derived2 includes Derived and Base as subobjects
struct Derived2 : Derived0, Derived1 {
    int b{42}, d{42}, derived2;
// Generated to_string for PUBLIC STRUCT_DECL Derived2
  public:
  auto to_string() const {
    return fstr::format(R"( Derived2:
    PUBLIC int b: {} 
    PUBLIC int d: {} 
    PUBLIC int derived2: {} 
     PUBLIC int a: {} 
     PUBLIC int derived0: {} 
      PUBLIC int base0: {} 
     PUBLIC int c: {} 
     PUBLIC int derived1: {} 
      PUBLIC int base1: {} 
)", b, d, derived2, this->a, this->derived0, this->base0, this->c, this->derived1, this->base1);
  }
}; 

namespace Parent {
    inline namespace new_ns {
         template <typename T>
         struct C {
             T member;
         // Generated to_string for PUBLIC CLASS_TEMPLATE Parent::new_ns::C<T>
  public:
  auto to_string() const {
    return fstr::format(R"( Parent::new_ns::C<T>:
    PUBLIC T={} member: {} 
)", typeid(T).name(), member);
  }
};
    }
    // TODO(deep): including the next line masks to_string
    // template<> class C<int> {};
}

//
// from https://en.cppreference.com/w/cpp/language/template_parameters
//
template<typename T>
class my_array {
  T x;
// Generated to_string for PUBLIC CLASS_TEMPLATE my_array<T>
  public:
  auto to_string() const {
    return fstr::format(R"( my_array<T>:
    PRIVATE T={} x: {} 
)", typeid(T).name(), x);
  }
};
 
// two type template parameters and one template template parameter:
template<typename K, typename V, template<typename> typename C = my_array>
struct Map
{
    C<K> key = {};
    C<V> value = {};
// Generated to_string for PUBLIC CLASS_TEMPLATE Map<K, V, C>
  public:
  auto to_string() const {
    return fstr::format(R"( Map<K, V, C>:
    PUBLIC C<K> key: {} 
    PUBLIC C<V> value: {} 
)", key, value);
  }
};
struct Y {
    struct B {
      int X;
    // Generated to_string for PUBLIC STRUCT_DECL Y::B
  public:
  auto to_string() const {
    return fstr::format(R"( Y::B:
    PUBLIC int X: {} 
)", X);
  }
};
    int C;
    int Y;
// Generated to_string for PUBLIC STRUCT_DECL Y
  public:
  auto to_string() const {
    return fstr::format(R"( Y:
    PUBLIC int C: {} 
    PUBLIC int Y: {} 
)", C, Y);
  }
};
 
template<class B>
struct X : Y {
    B b; // A's B
// Generated to_string for PUBLIC CLASS_TEMPLATE X<B>
  public:
  auto to_string() const {
    return fstr::format(R"( X<B>:
    PUBLIC B={} b: {} 
     PUBLIC int C: {} 
     PUBLIC int Y: {} 
)", typeid(B).name(), b, this->C, this->Y);
  }
};


int main() {
    using namespace Test;
    using std::cout;

    cout << fmt::format(" old Func()=old_ns::Func()={} s = old_ns::s={} \n", old_ns::Func(), old_ns::s);
    cout << fmt::format(" new Func()=Func()={} s = {} \n", Func(), s);
    cout << fmt::format(" Base0()={} Base1()={} Derived0()={} Derived1()={} Derived2()={} \n", Base0(), Base1(), Derived0(), Derived1(), Derived2());

     A::Derived<int> obj;
     obj.x = 12;
     obj.y = 21;
    cout << fmt::format(" obj={} \n", obj);

    Parent::C<int> c;
    cout << fmt::format(" c={} \n", c);
    
    Map<int, std::string> m1; // uses my_array as default container type
    cout << fmt::format(" m1={} \n", m1);


    return 0;
}






