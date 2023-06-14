/**
 * @file  test_enum_basic.cpp
 * @author  Sandeep <deep@tensorfield.ag>
 * @version 1.0
 *
 * @section LICENSE
 *
 * MIT License <http://opensource.org/licenses/MIT>
 *
 * @section DESCRIPTION
 *
 *
 * https://github.com/d-e-e-p/cpp-fstring-examples
 * Copyright (c) 2023 Sandeep <deep@tensorfield.ag>
 *
 */

#include <cstdint>         // for uint64_t, uint8_t
#include <iostream>        // for operator<<, cout
#include <limits>          // for numeric_limits
#include <map>             // for operator!=, map
#include <string>          // for basic_string, string_literals
#include <vector>          // for vector

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fstr.h"

using namespace std::string_literals;

// from https://en.cppreference.com/w/cpp/language/enum
// The name of an unscoped enumeration may be omitted: such declaration only introduces the enumerators into the enclosing scope:
enum { a, b, c = 0, d = a + 2 }; // defines a = 0, b = 1, c = 0, d = 2

struct X {
    enum direction3 { left = 'l', right = 'r' };
};
                                 
// test cases from:
// https://github.com/Neargye/magic_enum/blob/master/test/test.cpp
// Copyright (c) 2019 - 2023 Daniil Goncharov <neargye@gmail.com>
enum class Color1 { RED = -12, GREEN = 7, BLUE = 15 };
enum Color2 { RED = -12, GREEN = 7, BLUE = 15 };
enum class Color3 : unsigned char  { RED = u'r', GREEN = u'g', BLUE = u'b' };
enum class Number1 : int { one = 1, two, three, many = 127 };
enum Directions { Up = 85, Down = -42, Right = 120, Left = -120 };
enum Number2 : uint64_t {
  one = 100,
  two = 200,
  three = 300,
  four = 400,
};
enum class crc_hack {
  b5a7b602ab754d7ab30fb42c4fb28d82
};

enum class crc_hack_2 {
  b5a7b602ab754d7ab30fb42c4fb28d82,
  d19f2e9e82d14b96be4fa12b8a27ee9f
};

enum class MaxUsedAsInvalid : std::uint8_t {
  ONE,
  TWO = 63,
  INVALID = std::numeric_limits<std::uint8_t>::max()
};

enum class Binary : bool {
  ONE,
  TWO
};

enum class Number3 : int {
  one = 1 << 1,
  two = 1 << 2,
  three = 1 << 3,
  many = 1 << 30,
};

enum Dir : std::uint64_t {
  L = std::uint64_t{1} << 10,
  D = std::uint64_t{1} << 20,
  U = std::uint64_t{1} << 31,
  R = std::uint64_t{1} << 63,
};

namespace space {
enum class rangers {
  humans, maloqs, pelengs, faeyans, gaalians
};
}


TEST(Enum, Basic) {
  using testing::StrEq;
  using testing::HasSubstr;

  std::vector<Color1> vc = {Color1::RED, Color1::GREEN, Color1::BLUE};
  std::map<Color1, std::vector<Number3>> mc = {
    {Color1::RED,   {Number3::one, Number3::two}},
    {Color1::GREEN, {Number3::three}},
    {Color1::BLUE,  {Number3::many}}
  };


  std::string expected, actual;

  EXPECT_THAT("{Color1::GREEN}", StrEq("GREEN"));
  EXPECT_THAT("{GREEN}", StrEq("GREEN"));
  EXPECT_THAT("{L}", StrEq("L"));
  EXPECT_THAT("{Number1::one}", StrEq("one"));
  EXPECT_THAT("{Number2::one}", StrEq("one"));
  EXPECT_THAT("{Number3::one}", StrEq("one"));
  EXPECT_THAT("{Binary::ONE}", StrEq("ONE"));
  EXPECT_THAT("{space::rangers::humans}", StrEq("humans"));
  EXPECT_THAT("{vc}", StrEq(R"([RED, GREEN, BLUE])"));
  EXPECT_THAT("{mc}", HasSubstr(R"(RED: [one, two], GREEN: [three], BLUE: [many])"));


}

