#include <benchmark/benchmark.h>

#include "../src/a.Array/a.Array.hpp"

// ============================================================================
// a1.addToTheEnd
// ============================================================================

static void BM_ArrayAddToEnd(benchmark::State& state) {
    for (auto _ : state) {
        Array<int> arr(state.range(0));

        for (int i = 0; i < state.range(0); ++i) {
            arr.addToTheEnd(i);
        }

        benchmark::DoNotOptimize(arr);
    }
}

BENCHMARK(BM_ArrayAddToEnd)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// a2.addToTheIndex
// ============================================================================

static void BM_ArrayAddToIndex(benchmark::State& state) {
    for (auto _ : state) {
        Array<int> arr(state.range(0) + 1);

        for (int i = 0; i < state.range(0); ++i) {
            arr.addToTheEnd(i);
        }

        arr.addToTheIndex(state.range(0) / 2, 999);

        benchmark::DoNotOptimize(arr);
    }
}

BENCHMARK(BM_ArrayAddToIndex)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// a3.get
// ============================================================================

static void BM_ArrayGet(benchmark::State& state) {
    Array<int> arr(state.range(0));

    for (int i = 0; i < state.range(0); ++i) {
        arr.addToTheEnd(i);
    }

    for (auto _ : state) {
        benchmark::DoNotOptimize(
            arr.get(state.range(0) / 2)
        );
    }
}

BENCHMARK(BM_ArrayGet)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// a4.removeByIndex
// ============================================================================

static void BM_ArrayRemoveByIndex(benchmark::State& state) {
    for (auto _ : state) {
        Array<int> arr(state.range(0));

        for (int i = 0; i < state.range(0); ++i) {
            arr.addToTheEnd(i);
        }

        arr.removeByIndex(state.range(0) / 2);

        benchmark::DoNotOptimize(arr);
    }
}

BENCHMARK(BM_ArrayRemoveByIndex)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// a5.replaceByIndex
// ============================================================================

static void BM_ArrayReplaceByIndex(benchmark::State& state) {
    for (auto _ : state) {
        Array<int> arr(state.range(0));

        for (int i = 0; i < state.range(0); ++i) {
            arr.addToTheEnd(i);
        }

        arr.replaceByIndex(state.range(0) / 2, 404);

        benchmark::DoNotOptimize(arr);
    }
}

BENCHMARK(BM_ArrayReplaceByIndex)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// a6.length
// ============================================================================

static void BM_ArrayLength(benchmark::State& state) {
    Array<int> arr(state.range(0));

    for (int i = 0; i < state.range(0); ++i) {
        arr.addToTheEnd(i);
    }

    for (auto _ : state) {
        benchmark::DoNotOptimize(arr.length());
    }
}

BENCHMARK(BM_ArrayLength)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

BENCHMARK_MAIN();