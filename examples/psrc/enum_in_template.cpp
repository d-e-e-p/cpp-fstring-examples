/*!
 * @file enum_in_template.cpp.h
 * test enum/class templates
 *
 * @author  Sandeep <deep@tensorfield.ag>
 * @version 1.0
 *
 * @section LICENSE
 *
 * MIT License <http://opensource.org/licenses/MIT>
 *
 * @section DESCRIPTION
 *
 * https://github.com/d-e-e-p/fixed-size-string-buffer
 * @copyright
 * Copyright (c) 2023 Sandeep <deep@tensorfield.ag>
 *
 */


#include <iostream>        // for operator<<, cout
#include <string>          // for basic_string
#include <unordered_map>   // for unordered_map
                           
#include "fstr.h"
#include "utils.h"

struct EC {
  enum class hdir { left, right };
  hdir hval;
  struct {
    // enum inside unnamed class/struct can't be printed
    enum class ab { a, b };
    ab val;
  } var;
};

template <typename T>
class ET {
  enum class vdir { up, down };
  vdir vval;
  T tval{};
};



int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);
  cout << " {ET<int>()=}\n";
  cout << " {ET<ET<EC>>()=}\n";
}
