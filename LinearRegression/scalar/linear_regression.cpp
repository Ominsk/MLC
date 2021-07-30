//
// Created by mini on 27.07.21.
//
//#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX2
#include <benchmark/benchmark.h>
#include "linear_regression.h"
#define ITERATIONS 1

static void BM_LR_DOUBLE(benchmark::State& state) {
    std::vector<double> x;
    std::vector<double> y;

    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    LinearRegression<double> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(state.items_processed());
        }
    }
}


static void BM_LR_INTEGER(benchmark::State& state) {
    std::vector<int> x;
    std::vector<int> y;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    LinearRegression<int> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_LONG(benchmark::State& state) {
    std::vector<long> x;
    std::vector<long> y;

    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    LinearRegression<long> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_FLOAT(benchmark::State& state) {
    std::vector<float> x;
    std::vector<float> y;

    for (int i = 0; i < LIMIT; ++i) {
        float ys = i - rand() % 1;
        x.push_back(i);
        y.push_back(ys);
    }
    LinearRegression<float> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y);
            linearRegression.predict(state.items_processed());
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_LR_DOUBLE)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_INTEGER)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_LONG)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_FLOAT)->Iterations(ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();


