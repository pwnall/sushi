/*
 * test_suite_test.cc
 *
 *  Created on: Sep 26, 2008
 *      Author: Victor Costan
 */
#include "test_suite.h"

TEST(TestEmptyTestPasses) {
  return;
}

TEST(TestTrueExpectPasses) {
  EXPECT(true);
  return;
}
