//
// Created by mini on 17.08.21.
//

#ifndef BMLC_BENCHMARK_KMEANS_H
#define BMLC_BENCHMARK_KMEANS_H

#include "../../dataset/csv.h"
#include <vector>
#include <iostream>
#include <benchmark/benchmark.h>
#include "kmeans.h"
static void BM_KMEANS_2DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");

    int SIZE = temperature.size();
    int DIMENSION = 2;

    double * x[SIZE];
    volatile double blackhole = 0;



    for (int i = 0; i < SIZE; ++i) {
        double tmp[] = {std::stod(temperature.at(i)), std::stod(humidity.at(i))};
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < 10; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

BENCHMARK(BM_KMEANS_2DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(3)->ReportAggregatesOnly(true);

#endif //BMLC_BENCHMARK_H
