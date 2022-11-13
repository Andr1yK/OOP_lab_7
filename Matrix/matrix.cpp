//
// Created by Andriy Kobetiak on 13.11.2022.
//

#include "matrix.hpp"

using namespace MatrixNS;

Matrix::Matrix(const vector<vector<int>> &matrix)
  : matrix(matrix) {}

Matrix::Matrix() {
  matrix = matrixInt(1, vector<int>(1));
}

Matrix::Matrix(unsigned r, unsigned c) {
  if (r <= 0 || c <= 0) {
    throw range_error("r <= 0 or c <= 0");
  }

  if (r > maxSize) {
    r = maxSize;
  }

  if (c > maxSize) {
    c = maxSize;
  }

  matrix = matrixInt(r, vector<int>(c));
}

void Matrix::print() const {
  cout << this->toString();
}

bool Matrix::isEmpty() const {
  return this->matrix.empty();
}

int Matrix::getRowsCount() const {
  if (this->isEmpty()) {
    throw std::runtime_error("matrix is empty");
  }

  return static_cast<int>(matrix.size());
}

int Matrix::getColsCount() const {
  if (this->isEmpty()) {
    throw std::runtime_error("matrix is empty");
  }

  return static_cast<int>(matrix[0].size());
}

int Matrix::getByIndexes(int r, int c) const {
  if (this->getRowsCount() <= r || this->getColsCount() <= c) {
    throw std::out_of_range("out of range");
  }

  return this->matrix[r][c];
}

string Matrix::toString() const {
  string temp;

  const int r = this->getRowsCount();
  const int c = this->getColsCount();

  for(int i = 0; i < r; i++){   // i = row
    for(int j = 0; j < c; j++){  //j = column
      temp += to_string(matrix[i][j]) + " ";
    }
    temp += '\n';
  }

  return temp;
}

Matrix &Matrix::operator=(const Matrix &other) {
  if (this!=&other)
  {
    matrix= other.getMatrix();
  }

  return *this;
}

matrixInt Matrix::getMatrix() const {
  return this->matrix;
}

void Matrix::fill() {
  const int r = this->getRowsCount();
  const int c = this->getColsCount();

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("matrix[%d][%d]: ", i, j);

      cin >> matrix[i][j];
    }

    cout << endl;
  }
}

vector<int> Matrix::operator[](int r) {
  if (this->isEmpty()) {
    throw std::runtime_error("matrix is empty");
  }

  return this->matrix[r];
}

Matrix Matrix::operator*(int num) {
  const int r = this->getRowsCount();
  const int c = this->getColsCount();

  Matrix temp(*this);

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      temp[i][j] *= num;
    }
  }

  return temp;
}

bool Matrix::operator==(const Matrix &rhs) const {
  const int r = this->getRowsCount();
  const int c = this->getColsCount();

  if (r != rhs.getRowsCount()
    || c != rhs.getColsCount()) {
    return false;
  }

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if (matrix[i][j] != rhs.matrix[i][j])
        return false;

  return true;
}

bool Matrix::operator!=(const Matrix &rhs) const {
  return !(rhs == *this);
}

double Matrix::norm() const {
  const int r = this->getRowsCount();
  const int c = this->getColsCount();

  double s = 0.0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      s += pow(this->matrix[i][j], 2);

  return sqrt(s);
}
