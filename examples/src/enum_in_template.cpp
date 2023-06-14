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


#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <unordered_map>
#include <deque>
#include <iomanip>
#include <codecvt>
#include <iostream>
#include <cstddef>          // for size_t
#include <cctype>           // for isprint
                            //
#include "fstr.h"

namespace fssb {

template <size_t SPACE>
class FixedSizeStringBuffer {

 private:
  // main storage for strings...search for plus1 for the reason for +1
  std::array<char, SPACE+1> chars_ = {};
  size_t max_chars_;
   public:
  ///  @brief Constructor that creates a string buffer of fixed character size
  ///  template value (eg <10>) has to be a constexpr, ie known at compile-time
  FixedSizeStringBuffer<SPACE>()
      : max_chars_(SPACE)
  {
  }

   enum class CT {left, open, close, dash, space, right};
   using BOX = std::unordered_map<CT,char>;

  const BOX box_top = {
      {CT::left,  L'⎧'},
      {CT::open,  L'╭'},
      {CT::close, L'╮'},
      {CT::dash,  L'─'},
      {CT::space, L' '},
      {CT::right, L'⎫'},
   };

  const BOX box_bot = {
      {CT::left,  L'⎩'},
      {CT::open,  L'╰'},
      {CT::close, L'╯'},
      {CT::dash,  L'─'},
      {CT::space, L' '},
      {CT::right, L'⎭'},
   };

    void print_box_line();
// Generated formatter for PUBLIC enum fssb::FixedSizeStringBuffer<SPACE>::CT of type INT scoped
 friend constexpr auto format_as(const fssb::FixedSizeStringBuffer<SPACE>::CT obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case fssb::FixedSizeStringBuffer<SPACE>::CT::left : name = "left" ; break;  // index=0
    case fssb::FixedSizeStringBuffer<SPACE>::CT::open : name = "open" ; break;  // index=0
    case fssb::FixedSizeStringBuffer<SPACE>::CT::close: name = "close"; break;  // index=0
    case fssb::FixedSizeStringBuffer<SPACE>::CT::dash : name = "dash" ; break;  // index=0
    case fssb::FixedSizeStringBuffer<SPACE>::CT::space: name = "space"; break;  // index=0
    case fssb::FixedSizeStringBuffer<SPACE>::CT::right: name = "right"; break;  // index=0
  }
  return name;
}
// Generated to_string for PUBLIC CLASS_TEMPLATE fssb::FixedSizeStringBuffer<SPACE>
  public:
  auto to_string() const {
    return fstr::format(R"( fssb::FixedSizeStringBuffer<SPACE>:
    PRIVATE int chars_: {} 
    PRIVATE int max_chars_: {} 
    PUBLIC const int box_top: {} 
    PUBLIC const int box_bot: {} 
)", chars_, max_chars_, box_top, box_bot);
  }
};

template <size_t SPACE>
void FixedSizeStringBuffer<SPACE>::print_box_line()
{
  enum class CB {left, open, close, dash, space, right};
  typedef std::unordered_map<CB,wchar_t> BOX;

  static const BOX box_top = {
      {CB::left,  L'⎧'},
      {CB::open,  L'╭'},
      {CB::close, L'╮'},
      {CB::dash,  L'─'},
      {CB::space, L' '},
      {CB::right, L'⎫'},
   };

  static const BOX box_bot = {
      {CB::left,  L'⎩'},
      {CB::open,  L'╰'},
      {CB::close, L'╯'},
      {CB::dash,  L'─'},
      {CB::space, L' '},
      {CB::right, L'⎭'},
   };

};

} // end namespace fssb

#include <iostream>

int main() {
  std::cout << "fixed_size_string_buffer demo \n\n";
  constexpr size_t max_size = 10;
  auto rb = fssb::FixedSizeStringBuffer<max_size>();
  std::cout << fmt::format(" rb={} ", rb);
}


