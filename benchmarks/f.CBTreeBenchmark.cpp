#include <benchmark/benchmark.h>

#include <sstream>
#include <iostream>

#include "../src/f.CompleteBinaryTree/f.CBTree.hpp"

// ============================================================================
// f1.insert
// ============================================================================

static void BM_TreePush(benchmark::State& state) {
  for (auto _ : state) {
    CBTree<int> tree;

    for (int i = 0; i < state.range(0); ++i) {
      tree.insert(i);
    }

    benchmark::DoNotOptimize(tree);
  }
}

BENCHMARK(BM_TreePush)->Arg(100)->Arg(1000)->Arg(10000);

// ============================================================================
// f2.getValue
// ============================================================================

static void BM_TreeGetValue(benchmark::State& state) {
  for (auto _ : state) {
    CBTree<int> tree;

    state.PauseTiming();
    for (int i = 0; i < state.range(0); ++i) {
      tree.insert(i);
    }

    state.ResumeTiming();

    benchmark::DoNotOptimize(tree.get_value(state.range(0) / 2));
  }
}

BENCHMARK(BM_TreeGetValue)->Arg(50);

// ============================================================================
// F2 ПОИСК ЭЛЕМЕНТА — find_index
// ============================================================================

static void BM_TreeFindIndex(benchmark::State& state) {
  for (auto _ : state) {
    CBTree<int> tree;

    for (int i = 0; i < state.range(0); ++i) {
      tree.insert(i);
    }

    std::ostringstream null_stream;
    std::streambuf* old = std::cout.rdbuf(null_stream.rdbuf());

    tree.find_index(state.range(0) / 2);

    std::cout.rdbuf(old);
    benchmark::ClobberMemory();
  }
}

BENCHMARK(BM_TreeFindIndex)->Arg(100)->Arg(1000)->Arg(10000);

// ============================================================================
// F3 ПРОВЕРКА ДЕРЕВА НА ЗАВЕРШЕННОСТЬ (Complete Binary Tree)
// ============================================================================

static void BM_TreeIsCBT(benchmark::State& state) {
  for (auto _ : state) {
    CBTree<int> tree;

    state.PauseTiming();
    for (int i = 0; i < state.range(0); ++i) {
      tree.insert(i);
    }

    state.ResumeTiming();
    benchmark::DoNotOptimize(tree.isCBT());
  }
}

BENCHMARK(BM_TreeIsCBT)->Arg(50);

BENCHMARK_MAIN();