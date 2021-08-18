//
// Created by mini on 18.08.21.
//


#include <vector>
#include <iostream>

#include "kmeansIntrinsic.h"
#include "../../../dataset/csv.h"

int main() {
    csv data("../../../../weatherHistory.csv");

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
    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};
    kmeans.fit(x, 3, SIZE, DIMENSION);
    blackhole += kmeans.predict((double *)pred);

    std::cout << blackhole << std::endl;
}