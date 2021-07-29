//
// Created by mini on 27.07.21.
//

#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include "vector_linear_regression.h"

#define ITERATIONS 1


static void BM_VLR_DOUBLE(benchmark::State& state) {
    std::vector<double> x;
    std::vector<double> y;

    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    VectorLinearRegression<double> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(rand());
        }
    }
}


static void BM_VLR_INTEGER(benchmark::State& state) {
    std::vector<int> x;
    std::vector<int> y;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    VectorLinearRegression<int> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(rand());
        }
    }
}

static void BM_VLR_LONG(benchmark::State& state) {
    std::vector<long> x;
    std::vector<long> y;

    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    VectorLinearRegression<long> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(rand());
        }
    }
}

static void BM_VLR_FLOAT(benchmark::State& state) {
    std::vector<float> x;
    std::vector<float> y;

    for (int i = 0; i < LIMIT; ++i) {
        float ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    VectorLinearRegression<float> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(rand());
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_VLR_DOUBLE)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_VLR_INTEGER)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_VLR_LONG)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_VLR_FLOAT)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();

// objdump -d -M intel ./lr > LinearRegression/vectorized.ass
