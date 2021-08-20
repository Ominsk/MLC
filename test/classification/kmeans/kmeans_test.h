//
// Created by mini on 17.08.21.
//

#ifndef BMLC_KMEANS_TEST_H
#define BMLC_KMEANS_TEST_H

#include "../../../src/classification/kmeans/scalar/kmeans.h"
#include "../../../src/classification/kmeans/intrinsic/kmeansIntrinsic.h"

TEST(KMeansBasicScalar, BasicAssertions) {
    // Expect two strings not to be equal.
    Kmeans<double> kmeans;
    double *x[18];
    double dataset[18][2] = {{0, 0}, {0, 1},{0, 2},{1, 0},{1, 1},{1, 2},{2, 0},{2, 1},{2, 2},{5, 5},{5, 6},{5, 7},{6, 5},{6, 6},{6, 7},{7, 5},{7, 6},{7, 7}};

    for (int i = 0; i < 18; ++i) {
        x[i] = (double *) &(dataset[i]);
    }

    kmeans.fit(x, 2, 18, 2);
    double ** centroids = kmeans.getCentroids();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            EXPECT_TRUE(centroids[i][j] == 1 || centroids[i][j] == 6);
        }
    }
}

TEST(KMeansBasicIntrinsic, BasicAssertions) {
    // Expect two strings not to be equal.
    KMeansIntrinsic kmeans;
    double *x[18];
    double dataset[18][2] = {{0, 0}, {0, 1},{0, 2},{1, 0},{1, 1},{1, 2},{2, 0},{2, 1},{2, 2},{5, 5},{5, 6},{5, 7},{6, 5},{6, 6},{6, 7},{7, 5},{7, 6},{7, 7}};

    for (int i = 0; i < 18; ++i) {
        x[i] = (double *) &(dataset[i]);
    }

    kmeans.fit(x, 2, 18, 2);
    double ** centroids = kmeans.getCentroids();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            EXPECT_TRUE(centroids[i][j] == 1 || centroids[i][j] == 6);
        }
    }
}

#endif //BMLC_KMEANS_TEST_H
