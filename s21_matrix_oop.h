#ifndef _S21_MATRIX_OOP_H_
#define _S21_MATRIX_OOP_H_

#include <cmath>
#include <fstream>  // For file input/output
#include <iostream>
#include <stdexcept>

#define s21_EPS 1e-7
class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // Constructors
  S21Matrix();                        // Default constructor
  S21Matrix(int rows, int cols);      // Parameterized constructor
  S21Matrix(const S21Matrix& other);  // Copy constructor
  S21Matrix(S21Matrix&& other);       // Move constructor
  ~S21Matrix();                       // Destructor

  // Accessors and Mutators
  void setRows(int rows);
  void setCols(int cols);
  int getRows() const;
  int getCols() const;
  double** getMatrix();

  // Functions
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix();

  // Operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);

  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);

  double& operator()(int i, int j);
  double& operator()(int i, int j) const;

  // Helper functions
  void CreateMatrix(int rows, int cols);
  void RemoveMatrix();
  double MultRowByColumn(const S21Matrix& other, int times, int row,
                         int column) const;
  void FillMatrix(double num);
  void Clone(const S21Matrix& other);
  void SumCommon(const S21Matrix& other, int k);
  void getMinorMatrix(S21Matrix& minorMatrix, int i, int j) const;
  int getSign(int row) const;
  double getDeterminant() const;
  void createTestMatrix(std::string filename);
};
#endif  // _S21_MATRIX_OOP_H_
