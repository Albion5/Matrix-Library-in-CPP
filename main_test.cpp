#include "test_constructors.h"
#include "test_functions.h"
#include "test_operators.h"

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}