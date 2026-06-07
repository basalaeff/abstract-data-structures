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
    "src/*.cpp" "src/*.hpp" "src/*.tpp"
)

add_custom_target(format
    COMMAND clang-format -i ${FORMAT_FILES}
    COMMENT "Formatting code"
)
