#include <iostream>
#include <benchmark/benchmark.h>

#include "LinearRegression/intrinsic_vector/integer/integer_intrinsic_vector_linear_regression.h"
#include "LinearRegression/intrinsic_vector/double/double_intrinsic_vector_linear_regression.h"
#include "LinearRegression/scalar/linear_regression.h"
#include "LinearRegression/vector/vector_linear_regression.h"
#include "constants/constants.h"
#include "LinearRegression/intrinsic_vector/long/long_intrinsic_vector_linear_regression.h"


// SCALAR
static void BM_LR_DOUBLE(benchmark::State& state) {
    auto * x = new double[LIMIT];
    auto * y = new double[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - std::rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<double> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(std::rand());
        }
    }
}


static void BM_LR_INTEGER(benchmark::State& state) {
    auto * x = new int[LIMIT];
    auto * y = new int[LIMIT];
    volatile int blackhole = 0;


    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - std::rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<int> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_LONG(benchmark::State& state) {
    auto * x = new long[LIMIT];
    auto * y = new long[LIMIT];
    volatile long blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - std::rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<long> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

static void BM_LR_FLOAT(benchmark::State& state) {
    auto * x = new float [LIMIT];
    auto * y = new float[LIMIT];
    volatile float blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        float ys = i - std::rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    LinearRegression<float> linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(state.items_processed());
        }
    }
}

// INTRINSIC
static void BM_VLR_INTEGER(benchmark::State& state) {
    auto * x = new int[LIMIT];
    auto * y = new int[LIMIT];
    volatile int blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        int ys = i - rand() % 1;
        x[i] = i;
        y[i] = ys;
    }
    IntVectorLinearRegression linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}

static void BM_VLR_DOUBLE(benchmark::State& state) {
    auto * x = new double[LIMIT];
    auto * y = new double[LIMIT];
    volatile double blackhole = 0;
    for (int i = 0; i < LIMIT; ++i) {
        double ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }

    DoubleVectorLinearRegression linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}

static void BM_VLR_LONG(benchmark::State& state) {
    auto * x = new long[LIMIT];
    auto * y = new long[LIMIT];
    volatile long blackhole = 0;
    for (int i = 0; i < LIMIT; ++i) {
        long ys = i - std::rand() % 2;
        x[i] = i;
        y[i] = ys;
    }

    LongVectorLinearRegression linearRegression{};
    for (auto _ : state) {
        for (int i = 0; i < 100; ++i) {
            linearRegression.fit(x, y, LIMIT);
            blackhole += linearRegression.predict(rand());
        }
    }
}

// PRAGMA
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
BENCHMARK(BM_LR_DOUBLE)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_LR_INTEGER)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_LR_LONG)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_LR_FLOAT)->Unit(benchmark::kMillisecond)->Repetitions(10)->ReportAggregatesOnly(true);

BENCHMARK(BM_VLR_DOUBLE)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_VLR_INTEGER)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_VLR_LONG)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);

BENCHMARK(BM_PLR_DOUBLE)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_PLR_INTEGER)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_PLR_LONG)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);
BENCHMARK(BM_PLR_FLOAT)->Unit(benchmark::kMillisecond)->Repetitions(100)->ReportAggregatesOnly(true);


BENCHMARK_MAIN();

