//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "linear_regression.h"


int main() {
  LinearRegression<double> linearRegression;

  std::vector<double> x;
  std::vector<double> y;

  for (int i = 0; i < LIMIT; ++i) {
    double ys = i - rand() % 1;
    x.push_back(i);
    y.push_back(ys);
  }

  linearRegression.fit(x, y);

  return linearRegression.predict(10);

}