// File: leaky_implementation
//
// Example in C++ which do not release used memory
#include "leaky_implementation.hpp"

int do_some_work() {
   // we allocate an array
   double *my_array = new double[1000];

   // do some work
   //
   // we forget to deallocate it
   // delete [] my_array;
   // Now we remember
   delete [] my_array;
   
   return 0;
}

