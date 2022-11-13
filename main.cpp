#include <iostream>
#include "Matrix/matrix.hpp"

using namespace std;

int main() {
  MatrixNS::Matrix m(3, 2);

  m.print();

  m.fill();

  m.print();

  cout << "norm: " << m.norm() << endl;

  return 0;
}
