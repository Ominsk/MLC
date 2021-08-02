//
// Created by mini on 27.07.21.
//

#ifndef INT_VECTOR_LINEAR_REGRESSION_H
#define INT_VECTOR_LINEAR_REGRESSION_H

#ifdef __AVX__
#include <immintrin.h>
#else
#warning AVX is not available. Code will not compile!
#endif
#include <iostream>


class IntVectorLinearRegression {
private:
    int intercept;
    int slope;

public:
    void fit(const int * x, const int * y, const int size) {
        int sumx = 0;
        int sumy = 0;
        // __m256d xs = _mm256_load_pd(&x[0]);
        // __m256d ys = _mm256_load_pd(&y[0]); // --> segmentation fault in not aligned data
        __m256i xs = _mm256_loadu_si256((__m256i*)&x[0]);
        __m256i ys = _mm256_loadu_si256((__m256i*)&y[0]);


        int i = 8;
        int species_len = size - size % i;
        for (; i < species_len; i += 8) {
            xs = _mm256_add_epi32(xs, _mm256_loadu_si256(reinterpret_cast<const __m256i_u *>(&x[i])));
            ys = _mm256_add_epi32(ys, _mm256_loadu_si256(reinterpret_cast<const __m256i_u *>(&y[i])));

        }


        for (; i < size; ++i) {
            sumx += x[i];
            sumy += y[i];
        }

        for (i=0; i < 4; ++i) {
            sumx += (int) xs[i] + (int) (xs[i] >> 32);
            sumy += (int) ys[i] + (int) (ys[i] >> 32);
        }


        int xbar = sumx / size;
        int ybar = sumy / size;


        int xxbar = 0;
        int xybar = 0;

        i = 0;
        xs = _mm256_set1_epi32(0);
        ys = _mm256_set1_epi32(0);
        __m256i vxbar = _mm256_set1_epi32(xbar);
        __m256i vybar = _mm256_set1_epi32(ybar);
        for (; i < species_len; i += 8) {
            __m256i x_sub = _mm256_sub_epi32(_mm256_loadu_si256((__m256i*)&x[i]), vxbar);
            __m256i y_sub = _mm256_sub_epi32(_mm256_loadu_si256((__m256i*)&y[i]), vybar);
            xs = _mm256_add_epi32(xs, _mm256_mul_epi32(x_sub, x_sub));
            ys = _mm256_add_epi32(ys, _mm256_mul_epi32(x_sub, y_sub));


        }


        for (; i < size; ++i) {
            xxbar += (x[i] - xbar) * (x[i] - xbar); // vxbar * vxbar
            xybar += (x[i] - xbar) * (y[i] - ybar);

        }

        for (i=0; i < 4; ++i) {
            xxbar += (int) xs[i] + (int) (xs[i] >> 32);
            xybar += (int) ys[i] + (int) (ys[i] >> 32);
        }

        slope = xybar / xxbar;
        intercept = ybar - slope * xbar;

    }

    int predict(const int x) {
        return slope * x + intercept;
    }

    int get_intercept() {
        return intercept;
    }

    int get_slope() {
        return slope;
    }
};

#endif//INT_VECTOR_LINEAR_REGRESSION_H
