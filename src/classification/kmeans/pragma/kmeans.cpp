//
// Created by mini on 15.08.21.
//
#include <iostream>
#include "kmeans.h"
#include <string>
#include "../../../dataset/csv.h"
#include "kmeans.h"

int main() {
    int SIZE = 18;
    int DIMENSION = 2;

    //    double * x[SIZE];
    volatile double blackhole = 0;
    //
    //
    //    for (int i = 0; i < SIZE; ++i) {
    //        double tmp[] = {std::stod(temperature.at(i)), std::stod(humidity.at(i))};
    //        x[i] = (double *) tmp;
    //    }

    double *x[SIZE];
    double dataset[SIZE][2] = {{0, 0}, {0, 1},{0, 2},{1, 0},{1, 1},{1, 2},{2, 0},{2, 1},{2, 2},{5, 5},{5, 6},{5, 7},{6, 5},{6, 6},{6, 7},{7, 5},{7, 6},{7, 7}};

    for (int i = 0; i < SIZE; ++i) {
        x[i] = (double *) &(dataset[i]);
    }
    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    kmeans.fit(x, 2, SIZE, DIMENSION);
    blackhole += kmeans.predict((double *)pred);

    std::cout << blackhole << std::endl;

}