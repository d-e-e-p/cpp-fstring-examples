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

#include "clipp.h"

#pragma clang diagnostic ignored "-Wunusable-partial-specialization"

TEST(Class, Clipp_Src) {
  using testing::StrEq;
  using testing::HasSubstr;

  std::string expected, actual;

  using namespace clipp;
  using std::cout;

  bool a = false, b = false, c = true; //target variables

  auto cli = (
        option("-a").set(a)                  % "activates a",
        option("-b").set(b)                  % "activates b",
        option("-c", "--noc").set(c,false)   % "deactivates c",
        option("--hi")([]{cout << "hi!\n";}) % "says hi");

  auto usage = usage_lines(cli, "");

  std::string expected_cli = R"(cli=
clipp::detail::token<Derived>:
    PRIVATE int doc_:  
    PRIVATE bool repeatable_: false 
    PRIVATE bool blocking_: false 
)";


  std::string expected_usage = R"(usage=
clipp::usage_lines:
    PRIVATE const int & cli_: 
clipp::detail::token<Derived>:
    PRIVATE int doc_:  
    PRIVATE bool repeatable_: false 
    PRIVATE bool blocking_: false 
 
    PRIVATE doc_formatting fmt_: 
clipp::doc_formatting:
    PRIVATE int paramSep_:   
    PRIVATE int groupSep_:   
    PRIVATE int altParamSep_: | 
    PRIVATE int altGroupSep_:  |  
    PRIVATE int flagSep_: ,  
    PRIVATE int labelPre_: < 
    PRIVATE int labelPst_: > 
    PRIVATE int optionPre_: [ 
    PRIVATE int optionPst_: ] 
    PRIVATE int repeatPre_:  
    PRIVATE int repeatPst_: ... 
    PRIVATE int groupPre_: ( 
    PRIVATE int groupPst_: ) 
    PRIVATE int alternPre_: ( 
    PRIVATE int alternPst_: ) 
    PRIVATE int alternFlagPre_:  
    PRIVATE int alternFlagPst_:  
    PRIVATE int joinablePre_: ( 
    PRIVATE int joinablePst_: ) 
    PRIVATE int emptyLabel_:  
    PRIVATE int firstCol_: 8 
    PRIVATE int docCol_: 20 
    PRIVATE int lastCol_: 100 
    PRIVATE int indentSize_: 4 
    PRIVATE int maxAltInUsage_: 1 
    PRIVATE int maxAltInDocs_: 32 
    PRIVATE int lineSpc_: 0 
    PRIVATE int paragraphSpc_: 1 
    PRIVATE int groupSplitSize_: 3 
    PRIVATE bool splitTopAlt_: true 
    PRIVATE bool mergeAltCommonPfx_: false 
    PRIVATE bool mergeJoinableCommonPfx_: true 
    PRIVATE bool ignoreNewlines_: false 
 
    PRIVATE int prefix_:  
    PRIVATE bool ommitOutermostSurrounders_: false 
)";

  EXPECT_THAT("{cli=}", HasSubstr(expected_cli));
  EXPECT_THAT("{usage=}", HasSubstr(expected_usage));


}

