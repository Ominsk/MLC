//
// Created by mini on 15.08.21.
//

#ifndef BMLC_KMEANS_H
#define BMLC_KMEANS_H

#include <iostream>
template <typename X>
class Kmeans {
private:
    int size;
    int dimension;
    int n_cluster;
    X ** distanceMatrix;
    X ** centroids;
    int * cluster_ids;

    void fixedCentroid(X ** x) {
        int dist = this->size / this->n_cluster;
        int centroid = 0;
        for (int i = 0; i < this-> n_cluster; i++) {
            this->centroids[i] = x[centroid];
            centroid += dist;
        }
    }

    void recomputeCentroid(X ** x, X ** centroids) {

        X ** medeoids = new X *[this->n_cluster];

        for (int i = 0; i < this->n_cluster; ++i) {
            medeoids[i] = new X[this->dimension];
        }
        int * cluster_sizes = new int[n_cluster];

        for (int i = 0; i < n_cluster ; i++) {
           cluster_sizes[i] = 0;
        }

        for (int i = 0; i < this->size; i++) {
            cluster_sizes[cluster_ids[i]] += 1;
        }


        for (int i = 0; i < this->n_cluster; ++i) {
            for (int j = 0; j < this->size; j++) {
                if (i == this->cluster_ids[j]) {
                    for (int k = 0; k < this->dimension; k++) {
                        medeoids[i][k] += x[j][k] / cluster_sizes[i];
                    }
                }
            }
        }

        X ** medeoidDistanceMatrix = new X *[this->n_cluster];
        for (int i = 0; i < n_cluster; ++i) {
            medeoidDistanceMatrix[i] = new X[this->size];
        }

        l2HorizontalMatrix(x, medeoids, medeoidDistanceMatrix);


        for (int i = 0; i < this->n_cluster; ++i) {
            X min_dist = 1000;
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

    X euclideanDistance(X * x, X * y) {
        X dist = 0;
        for (int i = 0; i < this->dimension; i++) {

            dist += (x[i] - y[i]) * (x[i] - y[i]);
        }

        return dist;

    }

    void l2Matrix(X ** x, X ** centroids, X ** distanceMatrix) {
        for(int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->n_cluster; j++) {

                distanceMatrix[i][j] = euclideanDistance(centroids[j], x[i]);
            }
        }
    }

    void l2HorizontalMatrix(X ** x, X ** medeoids, X ** distanceMatrix) {

        for(int i = 0; i < this->n_cluster; i++) {
            for (int j = 0; j < this->size; j++) {
                distanceMatrix[i][j] = euclideanDistance(medeoids[i], x[j]);

            }
        }
    }

public:
    void fit(X ** x, const int n_cluster, const int size, const int dimension) {
        this->n_cluster = n_cluster;
        this->size = size;
        this->dimension = dimension;

        this->distanceMatrix = new X *[size];
        for (int i = 0; i < size; i++) {
            this->distanceMatrix[i] = new X[n_cluster];
        }

        this->centroids = new X * [n_cluster];
        for (int i = 0; i < n_cluster; ++i) {
            this->centroids[i] = new X[dimension];
        }

        this->cluster_ids = new int[size];

        fixedCentroid(x);

        while (true) {
            bool converged = true;

            l2Matrix(x, this->centroids, this->distanceMatrix);

            for (int i = 0; i < this->size; ++i) {
                X min = distanceMatrix[i][0];
                int min_pos = 0;


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
//            this->centroids = new_centroids;

            if (converged) break;
        }




        for (int i = 0; i < size; i++) {
            delete []  this->distanceMatrix[i];
        }
        delete [] this->distanceMatrix;

//        for (int i = 0; i < n_cluster; ++i) {
//            delete [] this->centroids[i];
//        }
//        delete [] this->centroids;
        delete [] this->cluster_ids;
    }

    int predict( X * x) {
        int cluster_id = 0;
        X min = 100000000000000;
        for (int i = 0; i < n_cluster; i++) {
            if (euclideanDistance(x, centroids[i]) < min) {
                min = euclideanDistance(x, centroids[i]);
                cluster_id = i;
            }
        }

        return cluster_id;
    }

    X ** getCentroids() {
        return centroids;
    }
};


#endif //BMLC_KMEANS_H
