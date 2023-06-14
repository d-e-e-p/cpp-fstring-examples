/**
 * @file  test_basic.cpp
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

#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wnarrowing"

#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <cstdlib>     /* srand, rand */
#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fstr.h"


TEST(Compare, BasicString) {

  std::string expected, actual;

  std::string str = "hello";
  expected = R"( "hello" how are you?)";
  actual   = fmt::format(R"( "{}" how are you?)", str);

  EXPECT_THAT(expected, testing::StrEq(actual));

}




