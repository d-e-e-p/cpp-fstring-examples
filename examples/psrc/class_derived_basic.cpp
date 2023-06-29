/**
 * @file class_derived_basic.cpp
 * demo of cpp-fstring 
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

using std::string;

// example 1
struct Base1 {
  string name = "base1";
  int a = 1;
};

struct Base2 {
  string name = "base2";
  int b = 2;
};

struct Embed {
  string name  = "embed";
  Base1 b1;
  Base2 b2;
};

struct Derived : Base1, Base2 {
  string name = "derived";
};

// example 2

// example 3
class Out {
    class Node {
       public:
          int data;
          Node* next;
    } node;
};
   

int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);
  cout << " {Embed()=}\n {Derived()=}\n";
  cout << " {Out()}\n";
}
