//
// Created by mini on 27.07.21.
//

#ifndef LONG_VECTOR_LINEAR_REGRESSION_H
#define LONG_VECTOR_LINEAR_REGRESSION_H

#ifdef __AVX__
#include <immintrin.h>
#else
#warning AVX is not available. Code will not compile!
#endif

#include <iostream>

class LongVectorLinearRegression {
private:
    long intercept;
    long slope;

public:
    void fit(const long* x, const long* y, const int size) {
        long sumx = 0;
        long sumy = 0;

        __m256i xs = _mm256_loadu_si256((__m256i*)&x[0]);
        __m256i ys = _mm256_loadu_si256((__m256i*)&y[0]);
        int i = 4;
        int species_len = size - size % i;
        for (; i < species_len; i += 4) {
            xs = _mm256_add_epi64(xs, _mm256_loadu_si256(reinterpret_cast<const __m256i_u *>(&x[i])));
            ys = _mm256_add_epi64(ys, _mm256_loadu_si256(reinterpret_cast<const __m256i_u *>(&y[i])));
        }


        sumx += xs[0] + xs[1] + xs[2] + xs[3];
        sumy += ys[0] + ys[1] + ys[2] + ys[3];


        for (; i < size; ++i) {
            sumx += x[i];
            sumy += y[i];
        }

        long xbar = sumx / size;
        long ybar = sumy / size;

        long xxbar = 0;
        long xybar = 0;

        i = 0;
        xs = _mm256_set1_epi64x(0);
        ys = _mm256_set1_epi64x(0);
        __m256i vxbar = _mm256_set1_epi64x(xbar);
        __m256i vybar = _mm256_set1_epi64x(ybar);
        for (; i < species_len; i += 4) {
            __m256i x_sub = _mm256_sub_epi64(_mm256_loadu_si256((__m256i*)&x[i]), vxbar);
            __m256i y_sub = _mm256_sub_epi64(_mm256_loadu_si256((__m256i*)&y[i]), vybar);
            //TODO replace mullo_epi32 with mullo_epi64 when in avx512
            xs = _mm256_add_epi64(xs, _mm256_mullo_epi32(x_sub, x_sub));
            ys = _mm256_add_epi64(ys, _mm256_mullo_epi32(x_sub, y_sub));
        }

        xxbar += xs[0] + xs[1] + xs[2] + xs[3];
        xybar += ys[0] + ys[1] + ys[2] + ys[3];

        for (; i < size; ++i) {
            xxbar += (x[i] - xbar) * (x[i] - xbar); // vxbar * vxbar
            xybar += (x[i] - xbar) * (y[i] - ybar);

        }

        slope = xybar / xxbar;
        intercept = ybar - slope * xbar;

    }

    long predict(const long &x) {
        return slope * x + intercept;
    }

    long get_intercept() {
        return intercept;
    }

    long get_slope() {
        return slope;
    }
};

#endif
