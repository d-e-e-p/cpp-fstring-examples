/**
 * @file class_union.cpp
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
 *   @license MIT License
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "fstr.h"
#include "utils.h"

struct Base {
  int a{};
  union {
    int i;
    double d;
    char c;
  } u{};
} b;

union Onion1 {
  int i;
  double d;
  char c;
} ui{10}, ud{20}, uc{30};

union Onion2 {
  float f;
  char c;
};


union Outer {
  Onion1 u1;
  Onion2 u2;
} out;


int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);

  cout << " {b=} \n";
  ui.i = 1;
  ud.d = 4.2;
  uc.c = 'u';
  cout << " {ui=}\n {ud=}\n {uc=}\n";
  cout << " {out}\n";
}
