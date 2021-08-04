//
// Created by mini on 27.07.21.
//

#ifndef BENCHMARK_VECTOR_LINEAR_REGRESSION_H
#define BENCHMARK_VECTOR_LINEAR_REGRESSION_H
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx")  //Enable AVX

template <typename X>
class PragmaVectorLinearRegression {
 private:
  X intercept;
  X slope;

 public:
  void fit(const X * x, const X * y, int size) {
    X sumx = 0;
    X sumy = 0;
#pragma GCC ivdep loop vectorize(enable) interleave(enable)
    for (int i = 0; i < size; ++i) {
      sumx += x[i];
      sumy += y[i];
    }

    X xbar = sumx / size;
    X ybar = sumy / size;

    X xxbar = 0;
    X xybar = 0;
//#pragma gcc
#pragma GCC ivdep loop vectorize(enable) interleave(enable)
    for (int i = 0; i < size; ++i) {
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
