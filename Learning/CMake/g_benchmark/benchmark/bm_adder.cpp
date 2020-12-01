// #include "main.cpp"
#include <benchmark/benchmark.h>
#include <chrono>
#include <string>
#include <memory>
#include <cstdlib>
#include <iostream>

unsigned long Increment(unsigned long n) {
  unsigned long sum = 0;
  for(unsigned long i = 0; i < n; ++i) {
    benchmark::DoNotOptimize(sum++); // force to store memory in either memory or register
    benchmark::ClobberMemory();  // force compilier to perform all pending writes to global memory
  }
  return sum;
}

static void BM_Increment(benchmark::State &state) {
  for(auto _ : state) {
    Increment(state.range(0));
  }
}
BENCHMARK(BM_Increment)->RangeMultiplier(2)->Range(1 << 8, 1 << 10);

// Run benchmark
BENCHMARK_MAIN();