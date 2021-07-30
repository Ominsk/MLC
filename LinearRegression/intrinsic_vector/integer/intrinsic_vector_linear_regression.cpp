//
// Created by mini on 27.07.21.
//

#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include "intrinsic_vector_linear_regression.h"

#define ITERATIONS 1

static void BM_VLR_INTEGER(benchmark::State& state) {
    std::vector<int> x;
    std::vector<int> y;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    VectorLinearRegression linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(rand());
        }
    }
}


// Register the function as a benchmark
BENCHMARK(BM_VLR_INTEGER)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();

