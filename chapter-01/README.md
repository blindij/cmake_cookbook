# Recipe 1 and 2
Simple CMakeLists.txt for building a binary based on a C++ source file.

## Recipe 1
```sh
mkdir build
cmake ..
cmake --build . | make 
```

## Recipe 2
```sh
mkdir build
cd build
cmake -G Ninja ..
cmake --build .
```
