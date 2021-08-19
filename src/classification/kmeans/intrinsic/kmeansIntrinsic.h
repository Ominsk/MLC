//
// Created by mini on 18.08.21.
//

#ifndef BMLC_KMEANSINTRINSIC_H
#define BMLC_KMEANSINTRINSIC_H

#include <iostream>
#include <cstring>

#ifdef __AVX__
#include <immintrin.h>
#else
#warning AVX is not available. Code will not compile!
#endif

class KMeansIntrinsic {

private:
    int size = 0;
    int dimension = 0;
    int n_cluster = 0;
    double ** distanceMatrix;
    double ** centroids;
    double * cluster_ids;
    int DOUBLE_SPECIES_LENGTH = 4;

    void fixedCentroid(double ** x) {
        int dist = this->size / this->n_cluster;
        int centroid = 0;
        for (int i = 0; i < this-> n_cluster; i++) {
            this->centroids[i] = x[centroid];
            centroid += dist;
        }
    }

    void recomputeCentroid(double ** x, double ** centroids) {

        double ** medeoids = new double *[this->n_cluster];

        for (int i = 0; i < this->n_cluster; ++i) {
            medeoids[i] = new double[this->dimension];
        }
        int * cluster_sizes = new int[n_cluster];

        for (int i = 0; i < n_cluster ; i++) {
            cluster_sizes[i] = 0;
        }

        //TODO vectorize

        int upperbound = size - (size % DOUBLE_SPECIES_LENGTH);
        std::cout << "upperbound: " << upperbound << std::endl;
        if (n_cluster < DOUBLE_SPECIES_LENGTH) {
            for (int i = 0; i < upperbound; i += DOUBLE_SPECIES_LENGTH) {\
                std::cout << "DEBUG: " << i <<  std::endl;
                __m256d points = _mm256_loadu_pd(&this->cluster_ids[i]);
                __m256d id = _mm256_set1_pd(i);
                std::cout << "current id: [";
                for (int k = i ; k < i + 4; k++) {
                    std::cout << id[k] << ", ";
                }
                std::cout << "]" << std::endl;
                std::cout << "cluster ids in vector [";
                for (int k = 0 ; k < 4; k++) {
                    std::cout << points[k] << ", ";
                }
                std::cout << "]" << std::endl;
                 for (int j = 0; j < n_cluster; j++) {
                     __m256d mask = _mm256_cmp_pd(points, id, _CMP_EQ_UQ); // 0 -> EQ
                     for (int l = 0; l < 4; l++) {
                       std::cout <<  ((1 &(long long)mask[l]) | (2 &(long long)mask[l])) << " ";
                     }
                     std::cout << std::endl;
//                     std::cout <<  "Cluster " << j << ": [" <<  << ", " << mask[1] << ", " << mask[2] << ", " << mask[4] << "]" << std::endl;
                }
            }
        }

        for (int i = 0; i < this->size; i++) {
            cluster_sizes[(int)cluster_ids[i]] += 1;
        }

        //TODO vectorize
        for (int i = 0; i < this->n_cluster; ++i) {
            for (int j = 0; j < this->size; j++) {
                if (i == this->cluster_ids[j]) {
                    #pragma GCC ivdep loop vectorize(enable) interleave(enable)
                    for (int k = 0; k < this->dimension; k++) {
                        medeoids[i][k] += x[j][k] / cluster_sizes[i];
                    }
                }
            }
        }

        double ** medeoidDistanceMatrix = new double *[this->n_cluster];
        for (int i = 0; i < n_cluster; ++i) {
            medeoidDistanceMatrix[i] = new double[this->size];
        }

        l2HorizontalMatrix(x, medeoids, medeoidDistanceMatrix);


        for (int i = 0; i < this->n_cluster; ++i) {
            double min_dist = 1000;
            #pragma GCC ivdep loop vectorize(enable) interleave(enable)
            for (int j = 0; j < this->size; ++j) {
                if (medeoidDistanceMatrix[i][j] < min_dist) {
                    min_dist = medeoidDistanceMatrix[i][j];
                    centroids[i] = x[j];
                }
            }
        }



        for (int i = 0; i < this->n_cluster; ++i) {
            delete [] medeoids[i];
        }
        delete [] medeoids;

        for (int i = 0; i < n_cluster; ++i) {
            delete [] medeoidDistanceMatrix[i];
        }
        delete [] medeoidDistanceMatrix;
    }

    double euclideanDistance(double * x, double * y) {
        double dist = 0;

        __m256d xs;
        __m256d ys;
        int i = 0;
        int upperbound = dimension - dimension % DOUBLE_SPECIES_LENGTH;
        for (; i < upperbound; i += DOUBLE_SPECIES_LENGTH) {
            xs = _mm256_loadu_pd(&x[i]);
            ys = _mm256_loadu_pd(&y[i]);

            xs = _mm256_add_pd(xs, ys);
            xs = _mm256_mul_pd(xs, xs);
            for (int j = 0; j < DOUBLE_SPECIES_LENGTH; j++) {
                dist += xs[i];
            }
        }
        for (; i < dimension; i++) {
            dist += (x[i] - y[i]) * (x[i] - y[i]);
        }

        return dist;
    }

    void l2Matrix(double ** x, double ** centroids, double ** distanceMatrix) {
        for(int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->n_cluster; j++) {
                distanceMatrix[i][j] = euclideanDistance(centroids[j], x[i]);
            }
        }
    }

    void l2HorizontalMatrix(double ** x, double ** medeoids, double ** distanceMatrix) {

        for(int i = 0; i < this->n_cluster; i++) {
            for (int j = 0; j < this->size; j++) {
                distanceMatrix[i][j] = euclideanDistance(medeoids[i], x[j]);

            }
        }
    }

public:
    void fit(double ** x, const int n_cluster, const int size, const int dimension) {
        this->n_cluster = n_cluster;
        this->size = size;
        this->dimension = dimension;

        this->distanceMatrix = new double *[size];
        for (int i = 0; i < size; i++) {
            this->distanceMatrix[i] = new double[n_cluster];
        }

        this->centroids = new double * [n_cluster];
        for (int i = 0; i < n_cluster; ++i) {
            this->centroids[i] = new double[dimension];
        }

        this->cluster_ids = new double[size];

        std::memset(cluster_ids, 0, size * sizeof(double));

        fixedCentroid(x);

        while (true) {
            bool converged = true;

            l2Matrix(x, this->centroids, this->distanceMatrix);

            for (int i = 0; i < this->size; ++i) {
                double min = distanceMatrix[i][0];
                double min_pos = 0;

                #pragma GCC ivdep loop vectorize(enable) interleave(enable)
                for (int j = 1; j < this->n_cluster; j++) {
                    if (distanceMatrix[i][j] < min) {
                        min = distanceMatrix[i][j];
                        min_pos = j;
                    }
                }

                if (this->cluster_ids[i] != min_pos) {
                    converged = false;
                }

                this->cluster_ids[i] = min_pos;

            }
            recomputeCentroid(x, this->centroids);

            if (converged) break;
        }




        for (int i = 0; i < size; i++) {
            delete []  this->distanceMatrix[i];
        }
        delete [] this->distanceMatrix;
        delete [] this->cluster_ids;
    }

    int predict( double * x) {
        int cluster_id = 0;
        double min = 10000000000;
        for (int i = 0; i < n_cluster; i++) {
            if (euclideanDistance(x, centroids[i]) < min) {
                min = euclideanDistance(x, centroids[i]);
                cluster_id = i;
            }
        }

        return cluster_id;
    }

    double ** getCentroids() {
        return centroids;
    }
};


#endif //BMLC_KMEANSINTRINSIC_H
