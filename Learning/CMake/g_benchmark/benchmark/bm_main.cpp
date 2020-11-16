#include <benchmark/benchmark.h>
#include <main.hpp>

static void BM_StringCreation(benchmark::State& state) {
	std::cout << "HelloWorld" << main_val << data_k;

	for(auto _ : state)
		std::string empty_string;
}

// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
// static void BM_StringCopy(benchmark::State& state) {

// 	for(auto _ : state)
// 		printVector(arr);
// }

// BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();
