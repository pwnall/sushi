/*
 * test_suite.h
 *
 *  Created on: Sep 21, 2008
 *      Author: Victor Costan
 */

#include <string>

namespace test_suite {

// forward declaration of Test that can be used in the test_ptr definition
class Test;

// pointer to a test function
typedef void (*test_ptr)(Test *__test_suite_object);

class Test {
public:
  Test(test_ptr test_function, std::string test_name);

  std::string name() { return name_; }
  bool has_failed() { return fail_; }

  void fail();
  void run();
private:
  test_ptr test_function_;
  // not a wstring because C++ sources aren't unicode
  std::string name_;
  bool fail_;
};

} // namespace test_suite

#define TEST(test_name) \
   void test_name(test_suite::Test *__test_suite_object); \
   static test_suite::Test __test_suite_test_##test_name(&test_name, #test_name); \
   void test_name(test_suite::Test *__test_suite_object)

#define FAIL() \
  __test_suite_object->fail();

#define EXPECT(expr) \
  if((expr) == false) { \
    __test_suite_object->fail(); \
  }

#define EXPECT_EQ(golden, actual) \
  if((golden) != (actual)) { \
    __test_suite_object->fail(); \
  }
