//
// Created by mini on 27.07.21.
//

#include <benchmark/benchmark.h>
#include <iostream>
#include "long_intrinsic_vector_linear_regression.h"



static void BM_VLR_DOUBLE(benchmark::State& state) {
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];
    volatile double blackhole = 0;
    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }

    LongVectorLinearRegression linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}



// Register the function as a benchmark
BENCHMARK(BM_VLR_DOUBLE)->Unit(benchmark::kMillisecond);


BENCHMARK_MAIN();

// objdump -d -M intel ./lr > LinearRegression/vectorized.ass
