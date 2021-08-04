//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "long_intrinsic_vector_linear_regression.h"

#define SIZE 10000000

int main() {

  LongVectorLinearRegression vectorLinearRegression;

  double * x = new double[SIZE];
  double * y = new double[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    double ys = i - std::rand() % 2;
    x[i] = i;
    y[i] = ys;
  }

  vectorLinearRegression.fit(x, y, SIZE);
  std::cout << "predicted: " << vectorLinearRegression.predict(10) << std::endl;

  delete[] x;
  delete[] y;
  return vectorLinearRegression.predict(10);

}