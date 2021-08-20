//
// Created by mini on 18.08.21.
//

#ifndef BMLC_KMEANSINTRINSIC_H
#define BMLC_KMEANSINTRINSIC_H

#include <iostream>
#include <cstring>
#include <cfloat>


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
    float * cluster_ids;
    int DOUBLE_SPECIES_LENGTH = 4;
    int INTEGER_SPECIES_LENGTH = 8;

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
        double * cluster_sizes = new double[n_cluster];

        for (int i = 0; i < n_cluster ; i++) {
            cluster_sizes[i] = 0;
        }

        int upperbound = size - (size % (INTEGER_SPECIES_LENGTH));
        int i = 0;
        if (false && n_cluster < INTEGER_SPECIES_LENGTH) { // mask is not optimized therefore skip this loop
            for (; i < upperbound; i += INTEGER_SPECIES_LENGTH) {\
                __m256 points = _mm256_loadu_ps((float *)&cluster_ids[i]);
                 for (int j = 0; j < n_cluster; j++) {
                     __m256 id = _mm256_set1_ps(j);
                     __m256 mask = _mm256_cmp_ps(points, id, _CMP_EQ_OQ); // 0 -> EQ
                     // TODO find way to vectorize this loop <- reduce function
                     #pragma GCC ivdep loop vectorize(enable) interleave(enable)
                     for (int l = 0; l < INTEGER_SPECIES_LENGTH; l++) {
                         if (mask[l] != 0) {
                             cluster_sizes[j] += 1;
                         }
                     }
                }
            }
        }

        for (; i < this->size; i++) {
            cluster_sizes[(int)cluster_ids[i]] += 1;
        }

        upperbound =  dimension - (dimension % (DOUBLE_SPECIES_LENGTH));
        i = 0;
        for (; i < this->n_cluster; ++i) {
            __m256d medeoid = _mm256_setzero_pd();
            int k = 0;
            for(; k < upperbound; k += DOUBLE_SPECIES_LENGTH) {
                for (int j = 0; j < size; j++) {
                    if (i == cluster_ids[i]) {
                        medeoid = _mm256_add_pd(medeoid, _mm256_loadu_pd(&x[j][k]));
                    }
                }


                medeoid = _mm256_div_pd(medeoid, _mm256_set1_pd(cluster_sizes[i]));
                for (int j  = 0; j < DOUBLE_SPECIES_LENGTH; j++) {
                    medeoids[i][k+j] = medeoid[j];
                }
            }

            for (int j = 0; j < this->size; j++) {
                if (i == this->cluster_ids[j]) {
                    for (int dim = k; dim < this->dimension; dim++) {
                        medeoids[i][dim] += x[j][dim] / cluster_sizes[i];
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

            int index = findMinIndex(medeoidDistanceMatrix[i], this->size);
            centroids[i] = x[index];
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

    int findMinIndex(double * data, int sz) {
        int index = 0;
        int i = 0;
        double min = DBL_MAX;

        if (false && DOUBLE_SPECIES_LENGTH < sz) { // mask is not optimized therefore skip this loop
            double * ind = new double[DOUBLE_SPECIES_LENGTH];
            for (int j = 0; j < DOUBLE_SPECIES_LENGTH; j++) {
                ind[j] = j;
            }

            int upperbound = this->size - this->size * DOUBLE_SPECIES_LENGTH;
            __m256d minValues = _mm256_loadu_pd(&data[0]);
            __m256d indices = _mm256_loadu_pd(&ind[0]);
            __m256d currentIndices = indices;
            __m256d increment = _mm256_set1_pd(DOUBLE_SPECIES_LENGTH);
            for (i = DOUBLE_SPECIES_LENGTH; i < upperbound; i+=DOUBLE_SPECIES_LENGTH) {
                __m256d values = _mm256_loadu_pd(&data[i]);
                __m256d less = _mm256_cmp_pd(values, minValues, _CMP_LT_OS);
                minValues = _mm256_blendv_pd(minValues, values, less);
                currentIndices = _mm256_add_pd(currentIndices, increment);
                indices = _mm256_blendv_pd(indices, currentIndices, less);
            }

            for (int j = 0; j < DOUBLE_SPECIES_LENGTH; j++) {
                if (minValues[j] < min) {
                    min = minValues[j];
                    index = j;
                }
            }

            index = indices[index];



        }

        for (; i < sz; ++i) {
            if (data[i] < min) {
                min = data[i];
                index = i;
            }
        }
        return index;
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

        this->cluster_ids = new float [size];

        std::memset(cluster_ids, 0, size * sizeof(float));

        fixedCentroid(x);

        while (true) {
            bool converged = true;

            l2Matrix(x, this->centroids, this->distanceMatrix);

            for (int i = 0; i < this->size; ++i) {
                int current_cluster = cluster_ids[i];
                cluster_ids[i] = findMinIndex(distanceMatrix[i], this->n_cluster);

                if (this->cluster_ids[i] != current_cluster) {
                    converged = false;
                }

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
