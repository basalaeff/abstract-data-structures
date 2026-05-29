#include <benchmark/benchmark.h>

#include "../src/b.SinglyLinkedList/b.SinglyLinkedList.hpp"

// ============================================================================
// b1.addToHead
// ============================================================================

static void BM_SLListAddToHead(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

        for (int i = 0; i < state.range(0); ++i) {
            list.addToHead(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_SLListAddToHead)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b2.addToTail
// ============================================================================

static void BM_SLListAddToTail(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

        for (int i = 0; i < state.range(0); ++i) {
            list.addToTail(i);
        }

        benchmark::DoNotOptimize(list);
    }
}

BENCHMARK(BM_SLListAddToTail)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b3.removeFromHead
// ============================================================================

static void BM_SLListRemoveFromHead(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;
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

BENCHMARK(BM_SLListRemoveFromHead)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b4.removeFromTail
// ============================================================================

static void BM_SLListRemoveFromTail(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;
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

BENCHMARK(BM_SLListRemoveFromTail)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b5.insertBefore
// ============================================================================

static void BM_SLListInsertBefore(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;
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

BENCHMARK(BM_SLListInsertBefore)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b6.insertAfter
// ============================================================================

static void BM_SLListInsertAfter(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;
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

BENCHMARK(BM_SLListInsertAfter)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b7.removeBefore
// ============================================================================

static void BM_SLListRemoveBefore(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

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

BENCHMARK(BM_SLListRemoveBefore)
    ->Arg(100);
    // ->Arg(1000)
    // ->Arg(10000);

// ============================================================================
// b8.removeAfter
// ============================================================================

static void BM_SLListRemoveAfter(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

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

BENCHMARK(BM_SLListRemoveAfter)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);


// ============================================================================
// b9.searchByValue
// ============================================================================

static void BM_SLListSearchByValue(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

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

BENCHMARK(BM_SLListSearchByValue)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(10000);

// ============================================================================
// b10.removeByValue
// ============================================================================

static void BM_SLListRemoveByValue(benchmark::State& state) {
    for (auto _ : state) {
        SinglyLinkedList<int> list;

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

BENCHMARK(BM_SLListRemoveByValue)
    ->Arg(100)
    // ->Arg(1000)
    // ->Arg(10000);
BENCHMARK_MAIN();