# Benchmark C++ Machine learning algorithms
Compare scalar and vector implementation (with pragma and intel intrinsic) of different machine
learning algorithm. We use these results to have a comparison with the
new Java Vector API that utilize vectorized instruction (parallel) to speed up computation.


## How to run
### Dependencies
The benchmark utilize [google benchmark](https://github.com/google/benchmark),
you need to install on your machine following their guidelines.
### Run Benchmark

#### Cmake 
You can use cmake to crete executable to run both benchmark and tests.
```shell
cmake -S . -B build
cmake --build build
# run tests
cd build && main_test
# run main benchmark
cd build && main
```

#### Shell commands
execute code without vector optimization
```shell
g++ linear_regression.cpp -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -o out
./out
```
To run the code with vector optimization you need to include the `-O3` flag.
```shell
g++ vector_linear_regression.cpp -O3 -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -o out
./out
```

obtain intel assembly
```shell
objdump -M intel -d program
```

