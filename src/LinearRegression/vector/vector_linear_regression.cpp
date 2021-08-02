//
// Created by mini on 27.07.21.
//

#include <benchmark/benchmark.h>
#include "vector_linear_regression.h"
#include "../../constants/constants.h"

static void BM_PLR_DOUBLE(benchmark::State& state) {
    auto * x = new double[LIMIT];
    auto * y = new double[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    PragmaVectorLinearRegression<double> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}


static void BM_PLR_INTEGER(benchmark::State& state) {
    auto * x = new int[LIMIT];
    auto * y = new int[LIMIT];
    volatile int blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    PragmaVectorLinearRegression<int> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}

static void BM_PLR_LONG(benchmark::State& state) {
    auto * x = new long[LIMIT];
    auto * y = new long[LIMIT];
    volatile long blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    PragmaVectorLinearRegression<long> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}

static void BM_PLR_FLOAT(benchmark::State& state) {
    auto * x = new float[LIMIT];
    auto * y = new float[LIMIT];
    volatile float blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        float ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }
    PragmaVectorLinearRegression<float> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}
// Register the function as a benchmark
BENCHMARK(BM_PLR_DOUBLE)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_PLR_INTEGER)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_PLR_LONG)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_PLR_FLOAT)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();

// objdump -d -M intel ./lr > LinearRegression/vectorized.ass
