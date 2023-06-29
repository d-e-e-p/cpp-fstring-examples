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
  
/************ skipped because enum in inside unnamed struct/class **
// Generated formatter for PUBLIC enum EC::(unnamed struct)::ab of type INT scoped
 friend constexpr auto format_as(const EC::(unnamed struct)::ab obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case EC::(unnamed struct)::ab::a: name = "a"; break;  // index=0
    case EC::(unnamed struct)::ab::b: name = "b"; break;  // index=1
  }
  return name;
}

******************** skipped */
  // Generated to_string() for PUBLIC STRUCT_DECL EC::(unnamed struct)
  public:
  auto to_string() const {
    const std::string fmt_string = "EC::(unnamed struct): val={}";
    return fstr::format(fmt_string, val);
  }
} var;
  // Generated to_string() for PUBLIC STRUCT_DECL EC
  public:
  auto to_string() const {
    const std::string fmt_string = "EC: hval={}, var={}";
    return fstr::format(fmt_string, hval, var);
  }
// Generated formatter for PUBLIC enum EC::hdir of type INT scoped
 friend constexpr auto format_as(const EC::hdir obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case EC::hdir::left : name = "left" ; break;  // index=0
    case EC::hdir::right: name = "right"; break;  // index=1
  }
  return name;
}
};

template <typename T>
class ET {
  enum class vdir { up, down };
  vdir vval;
  T tval{};
  // Generated to_string() for PUBLIC CLASS_TEMPLATE ET<T>
  public:
  auto to_string() const {
    const std::string fmt_string = "ET<T:={}>: vval={}, T tval={}";
    return fstr::format(fmt_string, fstr::get_type_name<T>(), vval, tval);
  }
// Generated formatter for PRIVATE enum ET<T>::vdir of type INT scoped
 friend constexpr auto format_as(const ET<T>::vdir obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case ET<T>::vdir::up  : name = "up"  ; break;  // index=0
    case ET<T>::vdir::down: name = "down"; break;  // index=0
  }
  return name;
}
};



int main()
{
  using std::cout;
  print_info(__FILE__, __TIMESTAMP__);
  cout << fmt::format(" ET<int>()={}\n", ET<int>());
  cout << fmt::format(" ET<ET<EC>>()={}\n", ET<ET<EC>>());
}



