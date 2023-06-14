/**
 * @file enum_include.cpp
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

#include "fstr.h"

#include "enum_include.h"

int main() {

  // TODO make {x} work
  std::cout << "x = " << x << "\n";
  
  std::cout << R"(

  {Foo::b=} {Foo::e=}

  {Color::yellow=}
  {X::left=} {X::right=}       
  {e1=}            
  {Fruit::apple=}  
  {S::apple=}
  {E11::x=}        

  vector<Foo> vc = {vc}
  map<Color, vector<Fruit>> mc = {mc}

)";

}
