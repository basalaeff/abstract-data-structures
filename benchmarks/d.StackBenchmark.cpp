#include <benchmark/benchmark.h>

#include "../src/d.Stack/d.Stack.hpp"

// ============================================================================
// d1.push
// ============================================================================

static void BM_StackPush(benchmark::State& state) {
  for (auto _ : state) {
    Stack<int> stack;

    for (int i = 0; i < state.range(0); ++i) {
      stack.push(i);
    }

    benchmark::DoNotOptimize(stack);
  }
}

BENCHMARK(BM_StackPush)->Arg(100)->Arg(1000)->Arg(10000);

// ============================================================================
// d2.pop
// ============================================================================

static void BM_StackPop(benchmark::State& state) {
  for (auto _ : state) {
    Stack<int> stack;

    state.PauseTiming();
    for (int i = 0; i < state.range(0); ++i) {
      stack.push(i);
    }
    state.ResumeTiming();

    for (int i = 0; i < state.range(0); ++i) {
      stack.pop();
    }

    benchmark::DoNotOptimize(stack);
  }
}

BENCHMARK(BM_StackPop)->Arg(100)->Arg(1000)->Arg(10000);

BENCHMARK_MAIN();
