#include "s21_matrix_oop.h"

// Constructors

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows_, int cols_) : rows_(rows_), cols_(cols_) {
  CreateMatrix(rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  Clone(other);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { this->RemoveMatrix(); }

// Accessors and Mutators

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

double** S21Matrix::getMatrix() { return this->matrix_; }

void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("Exception: Invalid number of rows");
  } else if (this->rows_ != rows) {
    S21Matrix temp(rows, this->cols_);
    int minRows = std::min(rows_, rows);
    for (int row = 0; row < minRows; row++) {
      for (int col = 0; col < this->cols_; col++) {
        temp.matrix_[row][col] = matrix_[row][col];
      }
    }
    this->RemoveMatrix();

    *this = temp;
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("Exception: Invalid number of cols");
  } else if (this->cols_ != cols) {
    S21Matrix temp(this->rows_, cols);
    int minCols = std::min(cols_, cols);
    for (int row = 0; row < this->rows_; row++) {
      for (int col = 0; col < minCols; col++) {
        temp.matrix_[row][col] = matrix_[row][col];
      }
    }
    this->RemoveMatrix();
    *this = temp;
  }
}

// Functions

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  int res = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    res = false;
  }
  for (int row = 0; row < rows_ && res; ++row) {
    for (int col = 0; col < cols_ && res; ++col) {
      if (fabs(this->matrix_[row][col] - other.matrix_[row][col]) >= 1e-7) {
        res = false;
      }
    }
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { this->SumCommon(other, 1); }

void S21Matrix::SubMatrix(const S21Matrix& other) {
  this->SumCommon(other, -1);
}

void S21Matrix::MulNumber(const double num) {
  for (int row = 0; row < this->rows_; row++) {
    for (int col = 0; col < this->cols_; col++) {
      this->matrix_[row][col] = this->matrix_[row][col] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_) {
    throw std::invalid_argument(
        "Exception: The number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix");
  }
  S21Matrix result(this->rows_, other.cols_);
  for (int row = 0; row < result.rows_; row++) {
    for (int col = 0; col < result.cols_; col++) {
      result.matrix_[row][col] = MultRowByColumn(other, this->cols_, row, col);
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(this->cols_, this->rows_);
  for (int row = 0; row < result.rows_; row++) {
    for (int col = 0; col < result.cols_; col++) {
      result.matrix_[row][col] = this->matrix_[col][row];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Exception: The matrix is not square");
  }
  int size = this->rows_;
  S21Matrix resultMatrix(size, size);
  if (size == 1) {
    resultMatrix.matrix_[0][0] = this->matrix_[0][0];
  } else {
    S21Matrix minorMatrix(size - 1, size - 1);
    for (int row = 0; row < resultMatrix.rows_; row++) {
      for (int column = 0, sign = getSign(row); column < resultMatrix.cols_;
           column++, sign = -sign) {
        this->getMinorMatrix(minorMatrix, row, column);
        resultMatrix.matrix_[row][column] = sign * minorMatrix.getDeterminant();
      }
    }
    minorMatrix.RemoveMatrix();
  }

  return resultMatrix;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Exception: The matrix is not square");
  }

  return this->getDeterminant();
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Exception: The matrix is not square");
  }
  double det = this->getDeterminant();
  if (det == 0) {
    throw std::invalid_argument("Exception: Matrix determinant is 0");
  }
  S21Matrix cofactorMatrix, transpose;
  cofactorMatrix = this->CalcComplements();
  transpose = cofactorMatrix.Transpose();
  transpose.MulNumber(1 / det);
  cofactorMatrix.RemoveMatrix();
  return transpose;
}

// Operators

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  this->SumMatrix(other);
  S21Matrix result = *this;
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  this->SubMatrix(other);
  S21Matrix result = *this;
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  this->MulMatrix(other);
  S21Matrix result = *this;
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  this->MulNumber(num);
  S21Matrix result = *this;
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->RemoveMatrix();
  this->Clone(other);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  this->RemoveMatrix();
  this->Clone(other);
  other.RemoveMatrix();
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Exception: Index is out of range");
  }
  return this->matrix_[i][j];
}

double& S21Matrix::operator()(int i, int j) const {
  if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Exception: Index is out of range");
  }
  return this->matrix_[i][j];
}

// Helper functions

void S21Matrix::CreateMatrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Exception: Invalid number of rows or columns");
  }
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = nullptr;
  this->matrix_ = new double*[this->rows_]();
  if (this->matrix_ == nullptr) {
    throw std::invalid_argument(
        "Exception: Memory was not allocated for rows.");
  }
  for (int row = 0; row < this->rows_; row++) {
    this->matrix_[row] = new double[this->cols_]();
    if (this->matrix_[row] == nullptr) {
      for (int cr_row = 0; cr_row < row; cr_row++) {
        delete[] this->matrix_[cr_row];
      }
      delete[] this->matrix_;
      throw std::invalid_argument(
          "Exception: Memory was not allocated for cols.");
    }
  }
  this->FillMatrix(0.0);
}

void S21Matrix::RemoveMatrix() {
  if (this->matrix_ != nullptr) {
    for (int row = 0; row < this->rows_; row++) {
      delete[] this->matrix_[row];
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
    this->rows_ = 0;
    this->cols_ = 0;
  }
}

double S21Matrix::MultRowByColumn(const S21Matrix& other, int times, int row,
                                  int column) const {
  double n = 0;
  for (int i = 0; i < times; i++) {
    n += this->matrix_[row][i] * other.matrix_[i][column];
  }
  return n;
}

void S21Matrix::FillMatrix(double num) {
  if (this->matrix_ != nullptr) {
    for (int row = 0; row < this->rows_; row++) {
      for (int col = 0; col < this->cols_; col++) {
        this->matrix_[row][col] = num;
      }
    }
  }
}

void S21Matrix::Clone(const S21Matrix& other) {
  this->CreateMatrix(other.rows_, other.cols_);
  for (int row = 0; row < other.rows_; row++) {
    for (int col = 0; col < other.cols_; col++) {
      this->matrix_[row][col] = other.matrix_[row][col];
    }
  }
}

void S21Matrix::SumCommon(const S21Matrix& other, int k) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::invalid_argument(
        "Exception: Matrices should have the same size");
  }
  for (int row = 0; row < this->rows_; row++) {
    for (int col = 0; col < this->cols_; col++) {
      this->matrix_[row][col] =
          this->matrix_[row][col] + other.matrix_[row][col] * k;
    }
  }
}
void S21Matrix::getMinorMatrix(S21Matrix& minorMatrix, int i, int j) const {
  for (int row = 0, m_row = 0; row < this->rows_; row++) {
    for (int column = 0, m_column = 0; column < this->cols_; column++) {
      if (row != i && column != j) {
        minorMatrix.matrix_[m_row][m_column++] = this->matrix_[row][column];
      }
    }
    if (row != i) m_row++;
  }
}

int S21Matrix::getSign(int row) const { return (row % 2) ? -1 : 1; }

double S21Matrix::getDeterminant() const {
  double det = 0;
  int size = this->rows_;
  if (size == 1) {
    det = this->matrix_[0][0];
  } else {
    S21Matrix minorMatrix(size - 1, size - 1);
    double* first_row = this->matrix_[0];
    for (int sign = 1, column = 0; column < size; column++, sign = -sign) {
      this->getMinorMatrix(minorMatrix, 0, column);
      det += sign * first_row[column] * minorMatrix.getDeterminant();
    }
    minorMatrix.RemoveMatrix();
  }
  return det;
}

void S21Matrix::createTestMatrix(std::string filename) {
  std::string path = "tests/data/" + filename;
  std::ifstream file(path.c_str());

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open the file");
  }

  int rows = this->getRows();
  int cols = this->getCols();

  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < cols; column++) {
      double value;
      if (!(file >> value)) {
        throw std::runtime_error(
            "Exception: Failed to read a value from the file");
      }
      this->matrix_[row][column] = value;
    }
  }

  file.close();
}