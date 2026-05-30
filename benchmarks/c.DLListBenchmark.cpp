#include <benchmark/benchmark.h>

#include "../src/c.DoublyLinkedList/c.DoublyLinkedList.hpp"

// ============================================================================
// c1.addToHead
// ============================================================================

static void BM_DLListAddToHead(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        for (int i = 0; i < state.range(0); ++i) {
            list.addToHead(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListAddToHead)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// c2.addToTail
// ============================================================================

static void BM_DLListAddToTail(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListAddToTail)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// c3.removeFromHead
// ============================================================================

static void BM_DLListRemoveFromHead(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;
        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) {
            list.addToHead(i);
        }
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            list.removeFromHead();
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListRemoveFromHead)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// c4.removeFromTail
// ============================================================================

static void BM_DLListRemoveFromTail(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;
        state.PauseTiming();

        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }

        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            list.removeFromTail();
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListRemoveFromTail)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b5.insertBefore
// ============================================================================

static void BM_DLListInsertBefore(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;
        state.PauseTiming();
        list.addToHead(0);
        int t = 0;
        state.ResumeTiming();

        for (int i = 1; i < state.range(0); ++i) {
            list.insertBefore(t, i);
            t++;
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListInsertBefore)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// c6.insertAfter
// ============================================================================

static void BM_DLListInsertAfter(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;
        state.PauseTiming();
        list.addToTail(0);
        int t = 0;
        state.ResumeTiming();

        for (int i = 1; i < state.range(0); ++i) {
            list.insertAfter(t, i);
            t++;
        }

        benchmark::DoNotOptimize(list);
    }
}

// BENCHMARK(BM_DLListInsertAfter)
//     ->Arg(100)
//     ->Arg(1000)
//     ->Arg(10000);

// ============================================================================
// c7.removeBefore
// ============================================================================

static void BM_DLListRemoveBefore(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }
        state.ResumeTiming();

        for (int i = 1; i < state.range(0); ++i) {
            list.removeBefore(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListRemoveBefore)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// c8.removeAfter
// ============================================================================

static void BM_DLListRemoveAfter(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }
        state.ResumeTiming();

        for (int i = state.range(0) - 2; i >= 0; --i) {
            list.removeAfter(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListRemoveAfter)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);


// ============================================================================
// b9.searchByValue
// ============================================================================

static void BM_DLListSearchByValue(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            benchmark::DoNotOptimize(list.searchByValue(i));
        }
    }
}

BENCHMARK(BM_DLListSearchByValue)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b10.removeByValue
// ============================================================================

static void BM_DLListRemoveByValue(benchmark::State& state) {
    for (auto _ : state) {
        DoublyLinkedList<int> list;

        state.PauseTiming();
        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }
        state.ResumeTiming();

        for (int i = 0; i < state.range(0); ++i) {
            list.removeByValue(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_DLListRemoveByValue)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

BENCHMARK_MAIN();