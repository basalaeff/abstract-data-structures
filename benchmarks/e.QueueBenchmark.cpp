#include <benchmark/benchmark.h>

#include "../src/e.Queue/e.Queue.hpp"

// ============================================================================
// e1.push
// ============================================================================

static void BM_QueuePush(benchmark::State& state) {
  for (auto _ : state) {
    Queue<int> queue;

    for (int i = 0; i < state.range(0); ++i) {
      queue.push(i);
    }

    benchmark::DoNotOptimize(queue);
  }
}

BENCHMARK(BM_QueuePush)->Arg(100)->Arg(1000)->Arg(10000);

// ============================================================================
// e2.pop
// ============================================================================

static void BM_QueuePop(benchmark::State& state) {
  for (auto _ : state) {
    Queue<int> queue;

    state.PauseTiming();
    for (int i = 0; i < state.range(0); ++i) {
      queue.push(i);
    }
    state.ResumeTiming();

    for (int i = 0; i < state.range(0); ++i) {
      queue.pop();
    }

    benchmark::DoNotOptimize(queue);
  }
}

BENCHMARK(BM_QueuePop)->Arg(100)->Arg(1000)->Arg(10000);

BENCHMARK_MAIN();
