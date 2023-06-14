/**
 * @file class_union.cpp
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

struct Base { 
  int a; 
  union {
    int i;
    double d;
    char c;
  } u;
} b;


union Onion {
  int i;
  double d;
  char c;
} u;


int main()
{
    std::cout << " {b=} \n";

    u.i = 10;
    u.d = 4.2;
    u.c = 'u';
    std::cout << "u.i = " << u.i <<  " u.d = " << u.d <<  " u.c = " << u.c << " \n";
    std::cout << " {u=} \n";
}
