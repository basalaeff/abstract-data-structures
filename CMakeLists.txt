cmake_minimum_required(VERSION 3.28.3)
project(DBMS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_COLOR_DIAGNOSTICS ON)

# ====================== Coverage ======================

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")

    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

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

target_include_directories(ArrayTests PRIVATE src)

target_link_libraries(ArrayTests
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME ArrayTests COMMAND ArrayTests)

add_custom_target(tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ArrayTests
)

# ====================== Coverage ======================
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