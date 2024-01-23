cmake_minimum_required(VERSION 3.0)# cmakeのバージョン指定
enable_language(CXX)# C++を使うよ~
set(CMAKE_CXX_STANDARD 20)# C++20使うよ~
set(CMAKE_CXX_STANDARD_REQUIRED ON)# C++20が必須だよ~
set(CMAKE_CXX_EXTENSIONS OFF)# gnu拡張とか環境依存のよくわからん拡張はいらんぞ
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(func_test)# プロジェクト名をセット

# GoogleTestをダウンロード
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.0.zip
)

# googletestをターゲットとして使えるようにする
FetchContent_MakeAvailable(googletest)

enable_testing()

# TODO 単体テスト名をセット
set(UNIT_TEST_EXECUTABLE_NAME
	contract_test
)

# TODO 単体テスト用ソースをセット
set(UNIT_TEST_SRC
	src/test/test.cpp
  src/test/func.cpp
  src/test/method.cpp
  src/test/template.cpp
)

# 単体テストの定義
add_executable(${UNIT_TEST_EXECUTABLE_NAME} ${UNIT_TEST_SRC})
target_link_libraries(${UNIT_TEST_EXECUTABLE_NAME} PRIVATE gtest_main)

target_compile_features(${UNIT_TEST_EXECUTABLE_NAME} PUBLIC cxx_std_20)
target_compile_options(${UNIT_TEST_EXECUTABLE_NAME} PUBLIC
    $<$<CXX_COMPILER_ID:GNU>: -O3 -Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /W4 >
)

# CTestへ単体テストを登録
include(GoogleTest)
gtest_discover_tests(${UNIT_TEST_EXECUTABLE_NAME})

include_directories(src)
