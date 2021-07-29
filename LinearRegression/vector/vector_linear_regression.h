//
// Created by mini on 27.07.21.
//

#ifndef BENCHMARK_VECTOR_LINEAR_REGRESSION_H
#define BENCHMARK_VECTOR_LINEAR_REGRESSION_H
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx")  //Enable AVX

#define LIMIT 10000000
#include <vector>

template <typename X>
class VectorLinearRegression {
 private:
  X intercept;
  X slope;

 public:
  void fit(const std::vector<X> x, const std::vector<X> y) {
    X sumx = 0;
    X sumy = 0;
#pragma gcc loop vectorize(enable) interleave(enable)
    for (int i = 0; i < x.size(); ++i) {
      sumx += x[i];
      sumy += x[i];
    }

    X xbar = sumx / x.size();
    X ybar = sumy / x.size();

    X xxbar = 0;
    X xybar = 0;
#pragma gcc loop vectorize(enable) interleave(enable)
    for (int i = 0; i < x.size(); ++i) {
      xxbar += (x[i] - xbar) * (x[i] - xbar);
      xybar += (x[i] - xbar) * (y[i] - ybar);
    }

    slope = xybar / xxbar;
    intercept = ybar - slope * xbar;
  }

  X predict(const X & x) {
    return slope * x + intercept;
  }

  X get_intercept() {
    return intercept;
  }

  X get_slope() {
    return slope;
  }
};

#endif  // BENCHMARK_VECTOR_LINEAR_REGRESSION_H
