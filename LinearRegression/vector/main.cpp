//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "vector_linear_regression.h"

int main() {

  VectorLinearRegression<double> vectorLinearRegression;

  std::vector<double> x;
  std::vector<double> y;

  for (int i = 0; i < LIMIT; ++i) {
    double ys = i - std::rand() % 1;
    x.push_back(i);
    y.push_back(ys);
  }

  vectorLinearRegression.fit(x, y);

  return vectorLinearRegression.predict(10);
}