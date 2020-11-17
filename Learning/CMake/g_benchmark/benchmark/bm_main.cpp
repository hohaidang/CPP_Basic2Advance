#include "main.cpp"
#include <benchmark/benchmark.h>
#include <chrono>
#include <string>

static void BM_StringComparision(benchmark::State &state) {
  for (auto _ : state) {
    StringComparision(state.range(0)); // get parameter of Arg
  }
}

// Register the function as a benchmark
// BENCHMARK(BM_StringComparision)->Arg(10000)->Arg(40000); // input parameter
BENCHMARK(BM_StringComparision)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 20); // from 2^10 * 2 to 2^20 * 2

static void BM_Increment(benchmark::State &state) {
	for(auto _ : state) {
		Increment(state.range(0));
	}
}
BENCHMARK(BM_Increment)->RangeMultiplier(2)->Range(1 << 8, 1 << 10);

// Run benchmark
BENCHMARK_MAIN();