//
// Created by Andriy Kobetiak on 13.11.2022.
//

#ifndef OOP_LAB_7_MATRIX_HPP
#define OOP_LAB_7_MATRIX_HPP

#include <iostream>
#include "cmath"
#include <vector>

using namespace std;

namespace MatrixNS {
  typedef vector<vector<int>> matrixInt;
  const int maxSize = 20;

  class Matrix
  {
    private:
      matrixInt matrix;

    public:
      Matrix();
      Matrix(unsigned r, unsigned c);
      explicit Matrix(const matrixInt &matrix);

      [[nodiscard]] matrixInt getMatrix() const;
      [[nodiscard]] int getRowsCount() const;
      [[nodiscard]] int getColsCount() const;
      [[nodiscard]] bool isEmpty() const;
      [[nodiscard]] int getByIndexes(int, int) const;

      void print() const;
      [[nodiscard]] string toString() const;
      void fill();

      [[nodiscard]] double norm() const;

      Matrix& operator=(const Matrix&);
      vector<int> operator[](int r);
      Matrix operator*(int);

      bool operator==(const Matrix &rhs) const;
      bool operator!=(const Matrix &rhs) const;
  };
}


#endif //OOP_LAB_7_MATRIX_HPP
