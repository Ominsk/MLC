//
// Created by mini on 27.07.21.
//

#ifndef BENCHMARK_VECTOR_LINEAR_REGRESSION_H
#define BENCHMARK_VECTOR_LINEAR_REGRESSION_H

#ifdef __AVX__
#include <immintrin.h>
#include <iostream>
#else
#warning AVX is not available. Code will not compile!
#endif

#define LIMIT 10000000

#include <vector>


class VectorLinearRegression {
private:
    double intercept;
    double slope;

public:
    void fit(const std::vector<double> x, const std::vector<double> y) {
        double sumx = 0;
        double sumy = 0;
        // __m256d xs = _mm256_load_pd(&x[0]);
        // __m256d ys = _mm256_load_pd(&y[0]); // --> segmentation fault in not aligned data
        __m256d xs = _mm256_loadu_pd(&x[0]);
        __m256d ys = _mm256_loadu_pd(&y[0]);
        int i = 4;
        int species_len = x.size() - x.size() % i;
        for (; i < species_len; i += 4) {
            xs = _mm256_add_pd(xs, _mm256_loadu_pd(&x[i]));
            ys = _mm256_add_pd(ys, _mm256_loadu_pd(&y[i]));
        }


        sumx += xs[0] + xs[1] + xs[2] + xs[3];
        sumy += ys[0] + ys[1] + ys[2] + ys[3];

        for (; i < x.size(); ++i) {
            sumx += x[i];
            sumy += y[i];
        }

        double xbar = sumx / x.size();
        double ybar = sumy / x.size();

        double xxbar = 0;
        double xybar = 0;

        i = 0;
        xs = _mm256_set1_pd(0);
        ys = _mm256_set1_pd(0);
        __m256d vxbar = _mm256_set1_pd(xbar);
        __m256d vybar = _mm256_set1_pd(ybar);
        for (; i < species_len; i += 4) {
            __m256d x_sub = _mm256_sub_pd(_mm256_loadu_pd(&x[i]), vxbar);
            __m256d y_sub = _mm256_sub_pd(_mm256_loadu_pd(&y[i]), vxbar);
            xs = _mm256_add_pd(xs, _mm256_mul_pd(x_sub, x_sub));
            xs = _mm256_add_pd(xs, _mm256_mul_pd(x_sub, y_sub));


        }

        xxbar += xs[0] + xs[1] + xs[2] + xs[3];
        xybar += ys[0] + ys[1] + ys[2] + ys[3];

        for (; i < x.size(); ++i) {
            xxbar += (x[i] - xbar) * (x[i] - xbar); // vxbar * vxbar
            xybar += (x[i] - xbar) * (y[i] - ybar);

        }

        slope = xybar / xxbar;
        intercept = ybar - slope * xbar;

    }

    double predict(const double &x) {
        return slope * x + intercept;
    }

    double get_intercept() {
        return intercept;
    }

    double get_slope() {
        return slope;
    }
};

#endif  // BENCHMARK_VECTOR_LINEAR_REGRESSION_H
