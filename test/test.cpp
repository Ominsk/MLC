//
// Created by mini on 02.08.21.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../src/LinearRegression/scalar/linear_regression.h"
#include "../src/LinearRegression/intrinsic_vector/integer/integer_intrinsic_vector_linear_regression.h"
#include "../src/LinearRegression/intrinsic_vector/double/double_intrinsic_vector_linear_regression.h"

#define LIMIT 100000

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
}

TEST(ConstantLinearRegressionInt, BasicAssertions) {
    // constant function for integer Linear Regression
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = 1;
    }

    LinearRegression<int> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(0, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(1, linearRegression.predict(5));
    EXPECT_EQ(1, linearRegression.predict(-10));
    EXPECT_EQ(1, linearRegression.predict(92));
}

TEST(PositiveLinearRegressionInt, BasicAssertions) {
    // constant function for integer Linear Regression
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = i + 1;
    }

    LinearRegression<int> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(1, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(6, linearRegression.predict(5));
    EXPECT_EQ(-9, linearRegression.predict(-10));
    EXPECT_EQ(93, linearRegression.predict(92));
}

TEST(NegativeLinearRegressionInt, BasicAssertions) {
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = (i + 1) * -1;
    }

    LinearRegression<int> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(-1, linearRegression.get_slope());
    EXPECT_EQ(-1, linearRegression.get_intercept());

    EXPECT_EQ(-6, linearRegression.predict(5));
    EXPECT_EQ(9, linearRegression.predict(-10));
    EXPECT_EQ(-93, linearRegression.predict(92));
}

TEST(ConstantLinearRegressionDouble, BasicAssertions) {
    // constant function for integer Linear Regression
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = 1;
    }

    LinearRegression<double> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(0, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(1, linearRegression.predict(5));
    EXPECT_EQ(1, linearRegression.predict(-10));
    EXPECT_EQ(1, linearRegression.predict(92));
}

TEST(PositiveLinearRegressionDouble, BasicAssertions) {
    // constant function for integer Linear Regression
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = i + 1;
    }

    LinearRegression<double> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(1, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(6, linearRegression.predict(5));
    EXPECT_EQ(-9, linearRegression.predict(-10));
    EXPECT_EQ(93, linearRegression.predict(92));
}

TEST(NegativeLinearRegressionDouble, BasicAssertions) {
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = (i + 1) * -1;
    }

    LinearRegression<double> linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(-1, linearRegression.get_slope());
    EXPECT_EQ(-1, linearRegression.get_intercept());

    EXPECT_EQ(-6, linearRegression.predict(5));
    EXPECT_EQ(9, linearRegression.predict(-10));
    EXPECT_EQ(-93, linearRegression.predict(92));
}


// INTRINSIC
TEST(ConstantVectorLinearRegressionInt, BasicAssertions) {
    // constant function for integer Linear Regression
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = 1;
    }

    IntVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(0, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(1, linearRegression.predict(5));
    EXPECT_EQ(1, linearRegression.predict(-10));
    EXPECT_EQ(1, linearRegression.predict(92));
}

TEST(PositiveVectorLinearRegressionInt, BasicAssertions) {
    // constant function for integer Linear Regression
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = i + 1;
    }

    IntVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(1, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(6, linearRegression.predict(5));
    EXPECT_EQ(-9, linearRegression.predict(-10));
    EXPECT_EQ(93, linearRegression.predict(92));
}

TEST(NegativeVectorLinearRegressionInt, BasicAssertions) {
    int * x = new int[LIMIT];
    int * y = new int[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = i * -1;
    }

    IntVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);
    EXPECT_EQ(-1, linearRegression.get_slope());
    EXPECT_EQ(0, linearRegression.get_intercept());

    EXPECT_EQ(-5, linearRegression.predict(5));
    EXPECT_EQ(10, linearRegression.predict(-10));
    EXPECT_EQ(-92, linearRegression.predict(92));
}

TEST(ConstantVectorLinearRegressionDouble, BasicAssertions) {
    // constant function for integer Linear Regression
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = 1;
    }

    DoubleVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(0, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(1, linearRegression.predict(5));
    EXPECT_EQ(1, linearRegression.predict(-10));
    EXPECT_EQ(1, linearRegression.predict(92));
}

TEST(PositiveVectorLinearRegressionDouble, BasicAssertions) {
    // constant function for integer Linear Regression
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = i + 1;
    }

    DoubleVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(1, linearRegression.get_slope());
    EXPECT_EQ(1, linearRegression.get_intercept());

    EXPECT_EQ(6, linearRegression.predict(5));
    EXPECT_EQ(-9, linearRegression.predict(-10));
    EXPECT_EQ(93, linearRegression.predict(92));
}

TEST(NegativeVectorLinearRegressionDouble, BasicAssertions) {
    double * x = new double[LIMIT];
    double * y = new double[LIMIT];

    for (int i = 0; i <  LIMIT; ++i) {
        x[i] = i;
        y[i] = (i + 1) * -1;
    }

    DoubleVectorLinearRegression linearRegression{};

    linearRegression.fit(x, y, LIMIT);

    EXPECT_EQ(-1, linearRegression.get_slope());
    EXPECT_EQ(-1, linearRegression.get_intercept());

    EXPECT_EQ(-6, linearRegression.predict(5));
    EXPECT_EQ(9, linearRegression.predict(-10));
    EXPECT_EQ(-93, linearRegression.predict(92));
}
