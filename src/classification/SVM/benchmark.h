//
// Created by mini on 26.08.21.
//

#ifndef BMLC_SVM_BENCHMARK_H
#define BMLC_SVM_BENCHMARK_H

#define LIMIT 1000000
#define ITERATIONS 1
#define REPETITIONS 2

#include "Svm.h"

void linearBinaryClass(double ** X, double * Y, int n, int low, int high, double m, double q, int dimension) {
    for (int i = 0; i < n; i++) {
        X[i] = new double [dimension];
        for (int j = 0; j < dimension; j++) {
            X[i][j] = rand() % high + low;
        }
    }


    for (int i = 0; i < n; i++) {
        if (X[i][1] - (X[i][0] * m + q) > 0) Y[i] = 1;
        else Y[i] = -1;
    }
}

static void BM_SVM_2DIMESNION(benchmark::State& state) {

    double *X[200];
    double  Y[200];
    Svm svm;
    volatile double blackhole = 0;

    linearBinaryClass(X, Y, 200, 0, 20, 0.8, 0, 2);
    double pred[] = {10, 10};
    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            svm.fit(X, Y, 200, 2);
            blackhole += svm.predict((double *) pred);
        }
    }
}

BENCHMARK(BM_SVM_2DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);

#endif //BMLC_SVM_BENCHMARK_H
