// File: sum_integers.cpp
//
// Simple C++ example, sum the elements of a vector
// and return the sum
#include "sum_integers.hpp"
#include <vector>

int sum_integers(const std::vector<int> integers){
   auto sum = 0;
   for (auto i : integers) {
      sum += i;
   }
   return sum;
}
