//
// Created by mini on 17.08.21.
//

#ifndef BMLC_BENCHMARK_KMEANS_H
#define BMLC_BENCHMARK_KMEANS_H

#include "../../dataset/csv.h"
#include <vector>
#include <iostream>
#include <benchmark/benchmark.h>
#include "scalar/kmeans.h"
#include "pragma/kmeans.h"
#include "intrinsic/kmeansIntrinsic.h"

#define LIMIT 1000000
#define ITERATIONS 10
#define REPETITIONS 2

static void BM_KMEANS_2DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");

    int SIZE = temperature.size();
    int DIMENSION = 2;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {std::stod(temperature.at(i % SIZE)), std::stod(humidity.at(i % SIZE))};
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}



static void BM_KMEANS_PRAGMA_2DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");

    int SIZE = temperature.size();
    int DIMENSION = 2;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {std::stod(temperature.at(i % SIZE)), std::stod(humidity.at(i % SIZE))};
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}


static void BM_KMEANS_4DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}



static void BM_KMEANS_PRAGMA_4DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_6DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");

    int SIZE = temperature.size();
    int DIMENSION = 6;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}



static void BM_KMEANS_PRAGMA_6DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_7DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");
    std::vector<std::string> pressure = data.getRecords().at("Pressure (millibars)");

    int SIZE = temperature.size();
    int DIMENSION = 7;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE)),
                std::stod(pressure.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}



static void BM_KMEANS_PRAGMA_7DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");
    std::vector<std::string> pressure = data.getRecords().at("Pressure (millibars)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE)),
                std::stod(pressure.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_4DIMESNION_2CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 2, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}





static void BM_KMEANS_PRAGMA_4DIMESNION_2CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 2, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_4DIMESNION_6CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 6, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}





static void BM_KMEANS_PRAGMA_4DIMESNION_6CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 6, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}


static void BM_KMEANS_4DIMESNION_8CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 8, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}





static void BM_KMEANS_PRAGMA_4DIMESNION_8CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 8, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_4DIMESNION_10CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }
    Kmeans<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 10, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}





static void BM_KMEANS_PRAGMA_4DIMESNION_10CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KmeansPragma<double> kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 10, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}


// INTRINSIC
static void BM_KMEANS_INTRINSIC_2DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");

    int SIZE = temperature.size();
    int DIMENSION = 2;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {std::stod(temperature.at(i % SIZE)), std::stod(humidity.at(i % SIZE))};
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_4DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_6DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_7DIMESNION(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");
    std::vector<std::string> loudCover = data.getRecords().at("Loud Cover");
    std::vector<std::string> visibility = data.getRecords().at("Visibility (km)");
    std::vector<std::string> pressure = data.getRecords().at("Pressure (millibars)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE)),
                std::stod(loudCover.at(i % SIZE)),
                std::stod(visibility.at(i % SIZE)),
                std::stod(pressure.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 4, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_4DIMESNION_2CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 2, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_4DIMESNION_6CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 6, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_4DIMESNION_8CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 8, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}

static void BM_KMEANS_INTRINSIC_4DIMESNION_10CLUSTER(benchmark::State& state) {

    csv data("weatherHistory.csv");

    std::vector<std::string> temperature = data.getRecords().at("Temperature (C)");
    std::vector<std::string> humidity = data.getRecords().at("Humidity");
    std::vector<std::string> windSpeed = data.getRecords().at("Wind Speed (km/h)");
    std::vector<std::string> windBearingd = data.getRecords().at("Wind Bearing (degrees)");

    int SIZE = temperature.size();
    int DIMENSION = 4;

    double * x[LIMIT];
    volatile double blackhole = 0;

    for (int i = 0; i < LIMIT; ++i) {
        double tmp[] = {
                std::stod(temperature.at(i % SIZE)),
                std::stod(humidity.at(i % SIZE)),
                std::stod(windSpeed.at(i % SIZE)),
                std::stod(windBearingd.at(i % SIZE))
        };
        x[i] = (double *) tmp;
    }

    KMeansIntrinsic kmeans;

    double pred[] = {15, 0.5};

    for (auto _ : state) {
        for (int i = 0; i < ITERATIONS; ++i) {
            kmeans.fit(x, 10, SIZE, DIMENSION);
            blackhole += kmeans.predict((double *)pred);
        }
    }
}


BENCHMARK(BM_KMEANS_2DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_2DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_2DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_4DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_4DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_4DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_6DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_6DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_6DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_7DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_7DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_7DIMESNION)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_4DIMESNION_2CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_4DIMESNION_2CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_4DIMESNION_2CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_4DIMESNION_6CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_4DIMESNION_6CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_4DIMESNION_6CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_4DIMESNION_8CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_4DIMESNION_8CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_4DIMESNION_8CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_4DIMESNION_10CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_PRAGMA_4DIMESNION_10CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);
BENCHMARK(BM_KMEANS_INTRINSIC_4DIMESNION_10CLUSTER)->Unit(benchmark::kMillisecond)->Repetitions(REPETITIONS)->ReportAggregatesOnly(true);

#endif //BMLC_BENCHMARK_H
