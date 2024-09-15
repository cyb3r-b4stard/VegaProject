#include <benchmark/benchmark.h>
#include "fact.h"

static void BM_UnoptimizedFactorial(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(factorial(100));
    }
}

static void BM_OptimizedFactorial(benchmark::State& state) {
    for (auto _ : state) {
        factorial(100);
    }
}

BENCHMARK(BM_OptimizedFactorial);
BENCHMARK(BM_UnoptimizedFactorial);