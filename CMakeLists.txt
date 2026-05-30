cmake_minimum_required(VERSION 3.28.3)
project(DBMS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_COLOR_DIAGNOSTICS ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# ====================== Main ======================

add_executable(dbms src/main.cpp)
target_include_directories(dbms PRIVATE src)

# ====================== Formatting ======================

file(GLOB_RECURSE FORMAT_FILES
    "src/*.cpp" "src/*.hpp" "src/*.tpp" "test/*.cpp"
)

add_custom_target(format
    COMMAND clang-format -i ${FORMAT_FILES}
    COMMENT "Formatting code"
)

# ====================== Tests ======================

find_package(GTest REQUIRED)

enable_testing()

add_executable(ArrayTests
    test/a.ArrayTest.cpp
)

add_executable(SLListTests
    test/b.SLListTest.cpp
)

add_executable(DLListTests
    test/c.DLListTest.cpp
)

add_executable(StackTests
    test/d.StackTest.cpp
)

add_executable(QueueTests
    test/e.QueueTest.cpp
)

add_executable(CBTreeTests
    test/f.CBTreeTest.cpp
)

target_include_directories(ArrayTests PRIVATE src)
target_include_directories(SLListTests PRIVATE src)
target_include_directories(DLListTests PRIVATE src)
target_include_directories(StackTests PRIVATE src)
target_include_directories(QueueTests PRIVATE src)
target_include_directories(CBTreeTests PRIVATE src)

target_link_libraries(ArrayTests
    GTest::gtest
    GTest::gtest_main
)
target_link_libraries(SLListTests
    GTest::gtest
    GTest::gtest_main
)
target_link_libraries(DLListTests
    GTest::gtest
    GTest::gtest_main
)

target_link_libraries(StackTests
    GTest::gtest
    GTest::gtest_main
)

target_link_libraries(QueueTests
    GTest::gtest
    GTest::gtest_main
)

target_link_libraries(CBTreeTests
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME ArrayTests COMMAND ArrayTests)
add_test(NAME SLListTests COMMAND SLListTests)
add_test(NAME DLListTests COMMAND DLListTests)
add_test(NAME StackTests COMMAND StackTests)
add_test(NAME QueueTests COMMAND QueueTests)
add_test(NAME CBTreeTests COMMAND CBTreeTests)

add_custom_target(tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ArrayTests SLListTests DLListTests StackTests QueueTests CBTreeTests
)

# ====================== Coverage ======================
function(enable_coverage target_name)
    if(ENABLE_COVERAGE)
        target_compile_options(${target_name} PRIVATE
            --coverage
            -O0
            -g
        )

        target_link_options(${target_name} PRIVATE
            --coverage
        )
    endif()
endfunction()

enable_coverage(ArrayTests)
enable_coverage(SLListTests)
enable_coverage(DLListTests)
enable_coverage(StackTests)
enable_coverage(QueueTests)
enable_coverage(CBTreeTests)

find_program(LCOV lcov)
find_program(GENHTML genhtml)

if(LCOV AND GENHTML)
    add_custom_target(coverage
        # 1. Запуск тестов
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure

        # 2. Сбор покрытия
        COMMAND ${LCOV}
                --capture
                --directory ${CMAKE_BINARY_DIR}
                --output-file ${CMAKE_BINARY_DIR}/coverage.info
                --ignore-errors mismatch,unused,source

        # 3. Фильтрация (паттерны БЕЗ кавычек!)
        COMMAND ${LCOV}
                --remove ${CMAKE_BINARY_DIR}/coverage.info
                /usr/*
                */gtest/*
                */gmock/*
                */test/*
                --output-file ${CMAKE_BINARY_DIR}/coverage.info
                --ignore-errors unused,mismatch,source

        # 4. Генерация HTML
        COMMAND ${GENHTML}
                ${CMAKE_BINARY_DIR}/coverage.info
                --output-directory ${CMAKE_BINARY_DIR}/coverage_report
                --ignore-errors source

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating coverage report"
        VERBATIM
    )
endif()

# ====================== Benchmark ======================

find_package(benchmark REQUIRED)

add_executable(ArrayBenchmark
    benchmarks/a.ArrayBenchmark.cpp
)

add_executable(SLListBenchmark
    benchmarks/b.SLListBenchmark.cpp
)

add_executable(DLListBenchmark
    benchmarks/c.DLListBenchmark.cpp
)

add_executable(StackBenchmark
    benchmarks/d.StackBenchmark.cpp
)

add_executable(QueueBenchmark
    benchmarks/e.QueueBenchmark.cpp
)

add_executable(CBTreeBenchmark
    benchmarks/f.CBTreeBenchmark.cpp
)

target_include_directories(ArrayBenchmark PRIVATE src)
target_include_directories(SLListBenchmark PRIVATE src)
target_include_directories(DLListBenchmark PRIVATE src)
target_include_directories(StackBenchmark PRIVATE src)
target_include_directories(QueueBenchmark PRIVATE src)
target_include_directories(CBTreeBenchmark PRIVATE src)

target_link_libraries(ArrayBenchmark
    benchmark::benchmark
    pthread
)

target_link_libraries(SLListBenchmark
    benchmark::benchmark
    pthread
)

target_link_libraries(DLListBenchmark
    benchmark::benchmark
    pthread
)

target_link_libraries(StackBenchmark
    benchmark::benchmark
    pthread
)

target_link_libraries(QueueBenchmark
    benchmark::benchmark
    pthread
)

target_link_libraries(CBTreeBenchmark
    benchmark::benchmark
    pthread
)

target_compile_options(ArrayBenchmark PRIVATE -O2)
target_compile_options(SLListBenchmark PRIVATE -O2)
target_compile_options(DLListBenchmark PRIVATE -O2)
target_compile_options(StackBenchmark PRIVATE -O2)
target_compile_options(QueueBenchmark PRIVATE -O2)
target_compile_options(CBTreeBenchmark PRIVATE -O2)

add_custom_target(benchmarks
    COMMAND ArrayBenchmark
    COMMAND SLListBenchmark
    COMMAND DLListBenchmark
    COMMAND StackBenchmark
    COMMAND QueueBenchmark
    COMMAND CBTreeBenchmark
    DEPENDS ArrayBenchmark SLListBenchmark DLListBenchmark StackBenchmark QueueBenchmark CBTreeBenchmark
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running benchmarks"
)