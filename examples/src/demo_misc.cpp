/**
 * @file demo_misc.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
   @license MIT License
*/
/**
 * @file demo_misc.cpp
 * misc demo of cpp-fstring for STL variables
 * 
 * Examples of:
 *   1. Format Specifiers
 *   2. Dates
 *   3. Expressions
 *   4. Ranges
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag> All rights reserved.
   @license MIT License
*/

#include <ctime>             // for tm
#include <cwchar>            // for tm
#include <iostream>          // for operator<<, cout, basic_ostream
#include <map>               // for operator!=, map
#include <string>            // for basic_string, char_traits, operator""s, operator<, string_literals
#include <tuple>             // for tuple
#include <valarray>          // for __val_expr, pow, begin, end, operator+, valarray
#include <variant>           // for variant
#include <vector>            // for vector
#include <cmath>
#include <chrono>

#include "fstr.h"
#include "fmt/chrono.h"

using namespace std::string_literals;

int main() {
  using std::cout;
  std::string str;
  int num = 97;
  cout <<  fmt::format(R"(
Overview of f-strings in C++
============================

1. Format Specifiers
--------------------


+----------------------+
| int     | {: >8d}   |
+=========+============+
| {{{}:#b}} | {:#08b}  |
+---------+------------+
| {{{}:c}}  | {: >8c}   |
+---------+------------+
| {{{}:d}}  | {: 8d}   |
+---------+------------+
| {{{}:o}}  | {: 8o}   |
+---------+------------+
| {{{}:x}}  | {: 8x}   |
+---------+------------+

+----------------------------------+
|  float    | {}    |
+==================================+
| {{M_PI:a}}  | {: <20a} |
+----------------------------------+
| {{M_PI:e}}  | {: <20e} |
+----------------------------------+
| {{M_PI:g}}  | {: <20g} |
+----------------------------------+
| {{M_PI:f}}  | {: <20f} |
+----------------------------------+

)", num, num, num, num, num, num, num, num, num, num, num, M_PI, M_PI, M_PI, M_PI, M_PI);

   auto tp = std::chrono::time_point_cast<std::chrono::seconds>(
      std::chrono::system_clock::now());
   auto tt = std::chrono::system_clock::to_time_t(tp);
   auto tm = *std::localtime(&tt);
   // int large = 10'000'000;

  cout <<  fmt::format(R"(
2. Dates
---------

It was a sunny {{tm:%A}} in {{tm:%B}} around {{tm:%OI}}{{tm:%p}}
          becomes:
It was a sunny {:%A} in {:%B} around {:%OI}{:%p}

)", tm, tm, tm, tm);

  cout <<  R"(
3. Expressions
--------------
)";

  auto va = std::vector<float>{5, M_PI, 10'000'000};
  int b = 10;

  for (auto & a : va) {
    cout <<  fmt::format(R"(

  when a={}, b={} =>

      {} + {} = {}
      {} * {} = {}
      {} ^ {} = {}

     )", a, b, a, b, a+b, a, b, a*b, a, b, std::pow(a, b)); // cout
  }


  int arr[] = {3, 2, 1};
  auto v1 = std::vector<int>{1, 2, 3,};
  auto v2 = std::vector<std::vector<int>>{{1, 2}, {3, 5}, {7, 11}};
  std::vector<std::vector<int>> v3 = {{1, 2, 3}, {4, 5}, {6}};

  auto m1 = std::map<std::string, int>{{"one", 1}, {"two", 2}};
  std::map<int, std::vector<int>> m2 = {{1, {1, 2}}, {2, {3, 4}}};

  auto p1 = std::pair<int, float>(42, 1.5F);
  std::tuple<double, char, std::string> t1 = {3.8, 'A', "Lisa Simpson"};

  cout <<  fmt::format(R"(

4. Ranges
---------

  Vectors:
    vector<int> v1={}
    vector<vector<int>> v2={}
    vector<vector<int>> v3={}

  Pairs:
    pair<int, float> p1={}

  Maps:
    map<string, int> m1={}
    map<int, vector<int>> m2={}
    
  Tuples: 
    tuple<double, char, string> t1={}

   )", v1, v2, v3, p1, m1, m2, t1) ;

  using Var = std::variant<int, float, std::string, char>;
  Var r0(42);
  Var r1(1.5f);
  Var r2("hello");
  Var r3('i');
  cout <<  fmt::format(R"(

  Variants:
    r0={}
    r1={}
    r2={}
    r3={}
   )", r0, r1, r2, r3) ;

  using IArr =  std::valarray<int>;
  IArr ia {1,2,3};
  IArr ib {4,5,6};
  IArr iab = std::pow(ia, ib);
  IArr iba = std::pow(ib, ia);
  IArr iabba = iab+iba;

  cout <<  fmt::format(R"(
    Valarray:
      a^b + b^a = {}^{} + {}^{}
                = {} + {}
                = {}

      min({}) = {}
      sum({}) = {}
      max({}) = {}
    

   )", ia, ib, ib, ia, iab, iba, iabba, iabba, iabba.min(), iabba, iabba.sum(), iabba, iabba.max()) ;


}



