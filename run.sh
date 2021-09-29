# cmake build commands for gtest
# from https://google.github.io/googletest/quickstart-cmake.html

# -S <path-to-source>          = Explicitly specify a source directory.
# -B <path-to-build>           = Explicitly specify a build directory.
cmake -DCMAKE_CXX_COMPILER=clang++ -S . -B build

# --build <dir>                = Build a CMake-generated project binary tree.
cmake --build build

pushd build; ctest; popd
