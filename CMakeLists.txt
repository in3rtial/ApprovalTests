cmake_minimum_required(VERSION 3.14)
project(ApprovalTests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# ApprovalTests.cpp
FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG master)

FetchContent_MakeAvailable(ApprovalTests)


enable_testing()
include(GoogleTest)


add_executable(hello_test src/hello_test.cpp)
target_link_libraries(hello_test gtest_main  ApprovalTests::ApprovalTests)

gtest_discover_tests(hello_test)
