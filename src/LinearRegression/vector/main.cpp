//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "vector_linear_regression.h"

int main() {

  VectorLinearRegression<double> vectorLinearRegression;

  double * x = new double[LIMIT];
  double * y = new double[LIMIT];

  for (int i = 0; i < LIMIT; ++i) {
      double ys = i - std::rand() % 2;
      x[i] = i;
      y[i] = ys;
  }

  vectorLinearRegression.fit(x, y, LIMIT);

  return vectorLinearRegression.predict(10);
}