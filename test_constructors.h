#include "unit_tests.h"

TEST(Mutators, setCol1) {
  S21Matrix A(4, 4);
  A.setCols(6);
  EXPECT_EQ(6, A.getCols());
  ASSERT_EQ(A.getMatrix()[0][5], 0.0);
  A.RemoveMatrix();
}

TEST(Mutators, setCol2) {
  S21Matrix A(4, 4);
  A.setCols(3);
  EXPECT_EQ(3, A.getCols());
  A.RemoveMatrix();
}

TEST(Mutators, setCol3) {
  S21Matrix A(4, 4);
  ASSERT_THROW(A.setCols(-1);, std::invalid_argument);
  A.RemoveMatrix();
}

TEST(Mutators, setRows1) {
  S21Matrix A(4, 4);
  A.setRows(6);
  EXPECT_EQ(6, A.getRows());
  ASSERT_EQ(A.getMatrix()[5][3], 0.0);
  A.RemoveMatrix();
}

TEST(Mutators, setRows2) {
  S21Matrix A(4, 4);
  A.setRows(3);
  EXPECT_EQ(3, A.getRows());
  A.RemoveMatrix();
}

TEST(Mutators, setRows3) {
  S21Matrix A(4, 4);
  ASSERT_THROW(A.setRows(-1);, std::invalid_argument);
  A.RemoveMatrix();
}

TEST(Constructors, Constructor1) {
  S21Matrix A;
  ASSERT_EQ(A.getRows(), 0);
  ASSERT_EQ(A.getCols(), 0);
  ASSERT_EQ(A.getMatrix(), nullptr);
  A.RemoveMatrix();
}

TEST(Constructors, Constructor2) {
  S21Matrix A(5, 4);
  ASSERT_EQ(A.getRows(), 5);
  ASSERT_EQ(A.getCols(), 4);
  ASSERT_NE(A.getMatrix(), nullptr);
  A.RemoveMatrix();
}

TEST(Constructors, Constructor3) {
  S21Matrix A(4, 4);
  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < A.getCols(); j++) {
      ASSERT_EQ(A.getMatrix()[i][j], 0.0);
    }
  }
  A.RemoveMatrix();
}

TEST(Constructors, Constructor4) {
  ASSERT_THROW(S21Matrix A(0, 15), std::invalid_argument);
}

TEST(Constructors, Constructor5) {
  ASSERT_THROW(S21Matrix A(2, -2), std::invalid_argument);
}

TEST(Constructors, CopyConstructor) {
  S21Matrix A(3, 4);
  S21Matrix B(A);
  EXPECT_EQ(3, B.getRows());
  EXPECT_EQ(4, B.getCols());
  EXPECT_EQ(1, A == B);
  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Constructors, MoveConstructor) {
  S21Matrix A(5, 5);
  EXPECT_EQ(5, A.getRows());
  EXPECT_EQ(5, A.getCols());
  S21Matrix B(std::move(A));
  EXPECT_EQ(0, A.getRows());
  EXPECT_EQ(0, A.getCols());
  EXPECT_EQ(5, B.getRows());
  EXPECT_EQ(5, B.getCols());
  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Accessors, getRows) {
  S21Matrix A(5, 5);
  EXPECT_EQ(5, A.getRows());
  A.RemoveMatrix();
}

TEST(Accessors, getCols) {
  S21Matrix A(5, 5);
  EXPECT_EQ(5, A.getCols());
  A.RemoveMatrix();
}

TEST(Accessors, getMatrix) {
  S21Matrix A;
  ASSERT_EQ(A.getMatrix(), nullptr);
  A.RemoveMatrix();
}
