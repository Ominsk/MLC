//
// Created by mini on 27.07.21.
//

#include <cstdlib>
#include "linear_regression.h"
#include "../../constants/constants.h"

int main() {
  LinearRegression<int> linearRegression;
  auto * x = new int[LIMIT];
  auto * y = new int[LIMIT];

  for (int i = 0; i < LIMIT; ++i) {
      int ys = i - std::rand() % 2;
      x[i] = i;
      y[i] = ys;
  }

  linearRegression.fit(x, y, LIMIT);

  return linearRegression.predict(10);

}