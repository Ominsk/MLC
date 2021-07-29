# Benchmark C++ Machine learning algorithms
Compare scalar and vector implementation (with pragma) of different machine
learning algorithm. We use these results to have a comparison with the
new Java Vector API that utilize vectorized instruction (parallel) to speed up computation.


## How to run
### Dependencies
The benchmark utilize [google benchmark](https://github.com/google/benchmark),
you need to install on your machine following their guidelines.
### Run Benchmark
execute code without vector optimization
```
g++ linear_regression.cpp -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -o out
./out
```
To run the code with vector optimization you need to include the `-O3` flag.
```
g++ vector_linear_regression.cpp -O3 -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -o out
./out
```