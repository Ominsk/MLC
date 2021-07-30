//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "intrinsic_vector_linear_regression.h"

int main() {

  VectorLinearRegression vectorLinearRegression;

  std::vector<double> x;
  std::vector<double> y;

  for (int i = 0; i < 20; ++i) {
    double ys = i - std::rand() % 2;
    x.push_back(i);
    y.push_back(ys);
  }

  vectorLinearRegression.fit(x, y);
  std::cout << "predicted: " << vectorLinearRegression.predict(10) << std::endl;
  return vectorLinearRegression.predict(10);

}