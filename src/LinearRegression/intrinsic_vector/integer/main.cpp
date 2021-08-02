//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "integer_intrinsic_vector_linear_regression.h"

int main() {

  IntVectorLinearRegression vectorLinearRegression;

  int * x = new int[20];
  int * y = new int[20];

  for (int i = 0; i < 20; ++i) {
    double ys = i - std::rand() % 2;
    x[i] = i;
    y[i] = ys;
  }

  vectorLinearRegression.fit(x, y);
  std::cout << "predicted: " << vectorLinearRegression.predict(10) << std::endl;
  return vectorLinearRegression.predict(10);

}