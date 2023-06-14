/**
 * @file  test_fmt_format.cpp
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

#include <iostream>        // for operator<<, cout
#include <string>          // for basic_string, string_literals

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fstr.h"

#include "clang_AST_Type.hpp"

TEST(Enum, Clang_Src) {
  using testing::StrEq;
  using testing::HasSubstr;

  std::string expected, actual;

  using std::cout;



  EXPECT_THAT("RED", HasSubstr(R"(RED)"));


}




