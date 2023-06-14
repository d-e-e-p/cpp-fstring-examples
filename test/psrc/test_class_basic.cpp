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
#include <string>          // for basic_string, string_literals
#include <vector>          // 
#include <regex>           // 

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fstr.h"

struct Foo { 
  int a = 32; 
  int b[10] = {}; 
};

struct Bar {
    char name[50] = "foo" ;
    int i = 10;
    double f = 3.14;
    Foo foo;
};

class Rectangle {
    int width=0, height=0;
  public:
    void set_values (int,int);
    int area (void);
    Bar bar;
} rect;


void compare(std::string actual, std::string expect) {
  using testing::HasSubstr;

  const std::regex whitespace("\\s+");
  expect = std::regex_replace(expect, whitespace, "");
  actual = std::regex_replace(actual, whitespace, "");

  EXPECT_THAT(actual, HasSubstr(expect));
}

TEST(Class, Basic) {
  using namespace ::testing;

  std::string expect, actual;
  Rectangle r;

  actual = "{r}";
  expect = R"(Rectangle:
    PRIVATE int width: 0 
    PRIVATE int height: 0 
    PUBLIC Bar bar: 
Bar:
    PUBLIC char[50] name: foo 
    PUBLIC int i: 10 
    PUBLIC double f: 3.14 
    PUBLIC Foo foo: 
Foo:
    PUBLIC int a: 32 
    PUBLIC int[10] b: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
)";

  compare(actual, expect);



}
