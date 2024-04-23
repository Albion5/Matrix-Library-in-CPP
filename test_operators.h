#include "unit_tests.h"

TEST(Operators, EqMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  std::string test_data = "square/5x5_4.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    int status = A == B;
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, EqMatrix2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);
  std::string test_data = "rect/3x2_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    int status = A == B;
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, EqMatrix3) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);
  std::string test_data = "rect/3x2_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    int status = A == B;
    EXPECT_EQ(status, 0);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, EqMatrix4) {
  S21Matrix A(1, 5);
  S21Matrix B(3, 2);
  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "rect/3x2_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    int status = A == B;
    EXPECT_EQ(status, 0);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, SumMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_4.dat";
  std::string result_data = "result/test_sum_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    C.createTestMatrix(result_data);
    A + B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, SumMatrix2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_1.dat";
  std::string test_data2 = "square/5x5_zero.dat";
  std::string result_data = test_data;

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A + B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, SumMatrix3) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);

  std::string test_data = "square/3x3_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    EXPECT_THROW(A + B, std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, SubMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_3.dat";
  std::string result_data = "square/5x5_zero.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    C.createTestMatrix(result_data);
    A - B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, SubMatrix2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_4.dat";
  std::string test_data2 = "square/5x5_3.dat";
  std::string result_data = "result/test_sub_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A - B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, SubMatrix3) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);

  std::string test_data = "square/3x3_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    EXPECT_THROW(A - B, std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, MulNumber1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    A * 1;
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, MulNumber2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_1.dat";
  std::string result_data = "square/5x5_zero.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    A * 0;
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, MulNumber3) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_3.dat";
  std::string result_data = "square/5x5_-3.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    A*(-1);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, MulNumber4) {
  S21Matrix A(1, 5);
  S21Matrix B(1, 5);

  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "result/test_mult_number_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    A * 10;
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, MulMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_4.dat";
  std::string test_data2 = "square/5x5_3.dat";
  std::string result_data = "result/test_mult_m_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A* B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, MulMatrix2) {
  S21Matrix A(1, 5);
  S21Matrix B(5, 1);
  S21Matrix C(1, 1);

  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "rect/5x1_2.dat";
  std::string result_data = "result/test_mult_m_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A* B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, MulMatrix3) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 2);
  S21Matrix C(3, 2);

  std::string test_data = "rect/3x2_1.dat";
  std::string test_data2 = "square/2x2_2.dat";
  std::string result_data = "result/test_mult_m_3.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A* B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, MulMatrix4) {
  S21Matrix A(1, 5);
  S21Matrix B(3, 2);

  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    EXPECT_THROW(A * B, std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, Indexation1) {
  S21Matrix A(3, 3);
  std::string test_data = "square/3x3_3.dat";
  double expected_result = 778.658341;
  try {
    A.createTestMatrix(test_data);
    EXPECT_DOUBLE_EQ(A(1, 1), expected_result);
    expected_result = 37.5;
    A(0, 2) = expected_result;
    EXPECT_DOUBLE_EQ(A(0, 2), expected_result);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Operators, Indexation2) {
  S21Matrix A(1, 5);

  std::string test_data = "rect/1x5_1.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A(0, -1), std::out_of_range);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Operators, Indexation3) {
  S21Matrix A(1, 5);

  std::string test_data = "rect/1x5_1.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A(1, 2), std::out_of_range);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Operators, EqSum1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_one.dat";

  try {
    A.createTestMatrix(test_data);
    C += B += A;
    int status = (A).EqMatrix(B);
    EXPECT_EQ(status, 1);
    status = (C).EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, EqSub1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_one.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    A -= B;
    int status = (A).EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Operators, EqMulNumber1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    A *= 1;
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, EqMulMatrix1) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 2);
  S21Matrix C(3, 2);

  std::string test_data = "rect/3x2_1.dat";
  std::string test_data2 = "square/2x2_2.dat";
  std::string result_data = "result/test_mult_m_3.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    C.createTestMatrix(result_data);
    A *= B;
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

TEST(Operators, Assign1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_1.dat";

  try {
    A.createTestMatrix(test_data);
    B = A;
    int status = B.EqMatrix(A);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Operators, Assign2) {
  S21Matrix A(5, 5);
  S21Matrix B = std::move(A);
  EXPECT_EQ(5, B.getRows());
  EXPECT_EQ(5, B.getCols());
  EXPECT_EQ(0, A.getRows());
  EXPECT_EQ(0, A.getCols());
  A.RemoveMatrix();
  B.RemoveMatrix();
}