#include "test_suite.h"

#include <vector>
#include <string>

#include <stdio.h>

namespace {
std::vector<test_suite::Test *> *tests = 0;
} // anonymous namespace

namespace test_suite {

Test::Test(test_ptr test_function, std::string name) : test_function_(test_function),
  name_(name), fail_(false) {

  if(tests == 0)
    tests = new std::vector<test_suite::Test *>();
  tests->push_back(this);
}
void Test::run() {
  (*test_function_)(this);
}
void Test::fail() {
  fail_ = true;
}

int RunTests() {
  int test_failures = 0;
  bool even = false;

  for(size_t i = 0; i < tests->size(); i++) {
    Test *test = (*tests)[i];
    if(even)
      printf("\x1B[1m");
    printf("Running test: %-40s", test->name().c_str());
    test->run();
    printf(" %s\x1B[m\n", test->has_failed() ? "\x1B[31mFAILED" : "\x1B[32mPASSED");
    even = !even;
    if(test->has_failed())
      test_failures++;
  }

  return test_failures;
}

} // namespace test_suite

int main() {
  return test_suite::RunTests();
}
