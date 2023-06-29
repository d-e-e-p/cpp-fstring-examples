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
  // Generated to_string() for PUBLIC STRUCT_DECL Base1
  public:
  auto to_string() const {
    const std::string fmt_string = "Base1: int name={}, a={}";
    return fstr::format(fmt_string, name, a);
  }
};

struct Base2 {
  string name = "base2";
  int b = 2;
  // Generated to_string() for PUBLIC STRUCT_DECL Base2
  public:
  auto to_string() const {
    const std::string fmt_string = "Base2: int name={}, b={}";
    return fstr::format(fmt_string, name, b);
  }
};

struct Embed {
  string name  = "embed";
  Base1 b1;
  Base2 b2;
  // Generated to_string() for PUBLIC STRUCT_DECL Embed
  public:
  auto to_string() const {
    const std::string fmt_string = "Embed: int name={}, b1={}, b2={}";
    return fstr::format(fmt_string, name, b1, b2);
  }
};

struct Derived : Base1, Base2 {
  string name = "derived";
  // Generated to_string() for PUBLIC STRUCT_DECL Derived
  public:
  auto to_string() const {
    const std::string fmt_string = "Derived: int name={}, a={}, b={}";
    return fstr::format(fmt_string, name, this->a, this->b);
  }
};

// example 2

// example 3
class Out {
    class Node {
       public:
          int data;
          Node* next;
      // Generated to_string() for PRIVATE CLASS_DECL Out::Node
  public:
  auto to_string() const {
    const std::string fmt_string = "Out::Node: int data={}, Node * next={}";
    return fstr::format(fmt_string, data, fmt::ptr(next));
  }
} node;
  // Generated to_string() for PUBLIC CLASS_DECL Out
  public:
  auto to_string() const {
    const std::string fmt_string = "Out: node={}";
    return fstr::format(fmt_string, node);
  }
};
   

int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);
  cout << fmt::format(" Embed()={}\n Derived()={}\n", Embed(), Derived());
  cout << fmt::format(" {}\n", Out());
}



