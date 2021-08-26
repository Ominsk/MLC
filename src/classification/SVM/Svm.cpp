//
// Created by mini on 26.08.21.
//

#include "Svm.h"
#include <iostream>
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

int main() {
    double *X[200] = {0};
    double  Y[200] = {0};
    Svm svm;

    linearBinaryClass(X, Y, 200, 0, 20, 0.8, 0, 2);

    svm.fit(X, Y, 200, 2);
    double pred[] = {10, 10};
    std::cout << svm.predict((double *) pred) << std::endl;
}
