//
// Created by mini on 26.08.21.
//

#ifndef BMLC_SVM_H
#define BMLC_SVM_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>
class Svm {
private:
    double * w;
    double intercept = 0;
    double n_classes;

    double dot(double * a, double * b, int size) {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += a[i] * b[i];
        }

        return result;
    }

public:

    void fit(double ** X, double * Y, int size, int n_classes) {
        fit(X, Y, 40, 100000, size, n_classes);
    }

    void fit(double ** x, double * y, double reg_parm, int epochs, int size, int n_classes) {
        this->n_classes = n_classes;
        w = new double[n_classes];

        for (int i = 0; i < n_classes; ++i) {
            w[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            if (std::abs(y[i]) != 1) throw std::invalid_argument( "class should be either 1 or -1");
        }


        for (int epoch = 1; epoch < epochs; ++epoch) {
            double learning_rate = 1/epoch;
            for (int i = 0; i < size; ++i) {
                if (y[i] * dot(x[i], w, n_classes) < 1) {
                    for (int j = 0; j < n_classes; ++j) {
                        w[j] = (1-learning_rate) * w[j] + learning_rate * reg_parm * y[i] * x[i][j];
                    }
                } else {
                    for (int j = 0; j < n_classes; ++j) {
                        w[j] = (1-learning_rate) * w[j];
                    }
                }
            }
        }
    }

    int predict(double * x) {
        double result = dot(x, w, this->n_classes);
        return (result > 0) - (result < 0);
    }
};


#endif //BMLC_SVM_H
