//
// Created by mini on 27.07.21.
//

#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include "integer_intrinsic_vector_linear_regression.h"


static void BM_VLR_INTEGER(benchmark::State& state) {
   int * x = new int[LIMIT];
   int * y = new int[LIMIT];
   volatile int blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    IntVectorLinearRegression linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}


// Register the function as a benchmark
BENCHMARK(BM_VLR_INTEGER)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
