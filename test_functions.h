#include "unit_tests.h"

TEST(Functions, CalcComplements1) {
  S21Matrix A(3, 3);
  S21Matrix C(3, 3);
  S21Matrix D(3, 3);

  std::string test_data = "square/3x3_4.dat";
  std::string result_data = "result/test_calc_complements_1.dat";

  try {
    A.createTestMatrix(test_data);
    D.createTestMatrix(result_data);
    C = A.CalcComplements();
    int status = (C == D);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  C.RemoveMatrix();
  D.RemoveMatrix();
}

TEST(Functions, CalcComplements2) {
  S21Matrix A(3, 2);

  std::string test_data = "rect/3x2_2.dat";
  std::string result_data = "result/test_calc_complements_1.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A.CalcComplements(), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Functions, CalcComplements3) {
  S21Matrix A(1, 1);
  A(0, 0) = 10;

  S21Matrix B = A.CalcComplements();

  EXPECT_EQ(10, B.getMatrix()[0][0]);
  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, EqMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  std::string test_data = "square/5x5_4.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, EqMatrix2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);
  std::string test_data = "rect/3x2_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, EqMatrix3) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);
  std::string test_data = "rect/3x2_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 0);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, EqMatrix4) {
  S21Matrix A(1, 5);
  S21Matrix B(3, 2);
  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "rect/3x2_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 0);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, SumMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_4.dat";
  std::string result_data = "result/test_sum_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    C.createTestMatrix(result_data);
    A.SumMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, SumMatrix2) {
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
    A.SumMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, SumMatrix3) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);

  std::string test_data = "square/3x3_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    EXPECT_THROW(A.SumMatrix(B), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, SubMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  S21Matrix C(5, 5);

  std::string test_data = "square/5x5_3.dat";
  std::string result_data = "square/5x5_zero.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    C.createTestMatrix(result_data);
    A.SubMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, SubMatrix2) {
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
    A.SubMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, SubMatrix3) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);

  std::string test_data = "square/3x3_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    EXPECT_THROW(A.SubMatrix(B), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, Determinant1) {
  S21Matrix A(3, 3);
  double exp_result = 478898923.35815844927;
  double fact_result = 0;
  std::string test_data = "square/3x3_3.dat";

  try {
    A.createTestMatrix(test_data);
    fact_result = A.Determinant();
    EXPECT_DOUBLE_EQ(fact_result, exp_result);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Functions, Determinant2) {
  S21Matrix A(5, 5);
  double exp_result = 7485357851.9474929894;
  double fact_result = 0;
  std::string test_data = "square/5x5_2.dat";

  try {
    A.createTestMatrix(test_data);
    fact_result = A.Determinant();
    EXPECT_DOUBLE_EQ(fact_result, exp_result);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Functions, Determinant3) {
  S21Matrix A(1, 5);
  std::string test_data = "rect/1x5_1.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A.Determinant(), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Functions, MulNumber1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data);
    A.MulNumber(1);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, MulNumber2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_1.dat";
  std::string result_data = "square/5x5_zero.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    A.MulNumber(0);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, MulNumber3) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);

  std::string test_data = "square/5x5_3.dat";
  std::string result_data = "square/5x5_-3.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    A.MulNumber(-1);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, MulNumber4) {
  S21Matrix A(1, 5);
  S21Matrix B(1, 5);

  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "result/test_mult_number_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);

    A.MulNumber(10);
    int status = A.EqMatrix(B);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, MulMatrix1) {
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
    A.MulMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, MulMatrix2) {
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
    A.MulMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, MulMatrix3) {
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
    A.MulMatrix(B);
    int status = A.EqMatrix(C);
    EXPECT_EQ(status, 1);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
  C.RemoveMatrix();
}

TEST(Functions, MulMatrix4) {
  S21Matrix A(1, 5);
  S21Matrix B(3, 2);

  std::string test_data = "rect/1x5_1.dat";
  std::string test_data2 = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(test_data2);
    EXPECT_THROW(A.MulMatrix(B), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, Transpose1) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);

  std::string test_data = "rect/3x2_1.dat";
  std::string result_data = "result/test_transpose_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    S21Matrix C = A.Transpose();
    int status = C.EqMatrix(B);
    EXPECT_EQ(status, 1);
    C.RemoveMatrix();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, Transpose2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  std::string test_data = "square/3x3_3.dat";
  std::string result_data = "result/test_transpose_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    S21Matrix C = A.Transpose();
    int status = C.EqMatrix(B);
    EXPECT_EQ(status, 1);
    C.RemoveMatrix();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, InverseMatrix1) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  std::string test_data = "square/5x5_2.dat";
  std::string result_data = "result/test_inverse_1.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    S21Matrix C = A.InverseMatrix();
    int status = B.EqMatrix(C);
    EXPECT_EQ(status, 1);
    C.RemoveMatrix();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, InverseMatrix2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  std::string test_data = "square/3x3_3.dat";
  std::string result_data = "result/test_inverse_2.dat";

  try {
    A.createTestMatrix(test_data);
    B.createTestMatrix(result_data);
    S21Matrix C = A.InverseMatrix();
    int status = B.EqMatrix(C);
    EXPECT_EQ(status, 1);
    C.RemoveMatrix();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
  B.RemoveMatrix();
}

TEST(Functions, InverseMatrix3) {
  S21Matrix A(3, 3);
  std::string test_data = "square/3x3_det_0.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}

TEST(Functions, InverseMatrix4) {
  S21Matrix A(3, 2);
  std::string test_data = "rect/3x2_2.dat";

  try {
    A.createTestMatrix(test_data);
    EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  A.RemoveMatrix();
}