//
// Created by mini on 27.07.21.
//
#include <benchmark/benchmark.h>
#include "linear_regression.h"
#include "../../constants/constants.h"

static void BM_LR_DOUBLE(benchmark::State& state) {
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<double> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}


static void BM_LR_INTEGER(benchmark::State& state) {
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];
    volatile int blackhole = 0;


    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<int> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_LONG(benchmark::State& state) {
    long * x = new long[LIMIT];
    long * y = new long[LIMIT];
    volatile long blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<long> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_FLOAT(benchmark::State& state) {
    float * x = new float [LIMIT];
    float * y = new float[LIMIT];
    volatile float blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        float ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<float> linearRegression;
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_LR_DOUBLE)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_INTEGER)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_LONG)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_LR_FLOAT)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();


