// https://en.cppreference.com/w/cpp/language/constructor
// Constructors and member initializer lists
#include <fstream>
#include <string>
#include <mutex>
#include <iostream>
#include "fstr.h"
 
struct Base
{
    int n;
// Generated to_string for PUBLIC STRUCT_DECL Base
  public:
  auto to_string() const {
    return fstr::format(R"( Base:
    PUBLIC int n: {} 
)", n);
  }
};   
 
struct Class : public Base
{
    unsigned char x;
    unsigned char y;
    std::mutex m;
    std::lock_guard<std::mutex> lg;
    std::fstream f;
    std::string s;
 
    Class(int x) : Base{123}, // initialize base class
        x(x),     // x (member) is initialized with x (parameter)
        y{0},     // y initialized to 0
        f{"test.cc", std::ios::app}, // this takes place after m and lg are initialized
        s(__func__), // __func__ is available because init-list is a part of constructor
        lg(m),    // lg uses m, which is already initialized
        m{}       // m is initialized before lg even though it appears last here
    {}            // empty compound statement
 
    Class(double a) : y(a + 1),
        x(y), // x will be initialized before y, its value here is indeterminate
        lg(m)
    {} // base class initializer does not appear in the list, it is
       // default-initialized (not the same as if Base() were used, which is value-init)
 
    Class()
    try // function-try block begins before the function body, which includes init list
      : Class(0.0) // delegate constructor
    {
        // ...
    }
    catch (...)
    {
        // exception occurred on initialization
    }
// Generated to_string for PUBLIC STRUCT_DECL Class
  public:
  auto to_string() const {
    return fstr::format(R"( Class:
    PUBLIC unsigned char x: {} 
    PUBLIC unsigned char y: {} 
    PUBLIC int m: {} 
    PUBLIC int lg: {} 
    PUBLIC int f: {} 
    PUBLIC int s: {} 
     PUBLIC int n: {} 
)", x, y, m, lg, f, s, this->n);
  }
};
 
int main()
{
    Class c;
    Class c1(1);
    Class c2(0.1);
    std::cout << fmt::format(" Class()={} ", Class());
    std::cout << fmt::format(" Class(1)={} ", Class(1));
    std::cout << fmt::format(" Class(0.1)={} ", Class(0.1));
}



