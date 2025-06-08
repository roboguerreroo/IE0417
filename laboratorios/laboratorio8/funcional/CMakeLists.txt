
cmake_minimum_required(VERSION 3.15)


set(CMAKE_CXX_STANDARD 17)


project(functional_testing)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)


add_executable(funcional test_authentication.cpp)
target_link_libraries(funcional gtest_main gmock_main)

enable_testing()
add_test(NAME funcional COMMAND funcional)