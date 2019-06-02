// File: test.cpp
//
// A test file for testing for memory leakage
// The test is expected to pass since do_some_work()
// always return 0. do_some_work() do not deallocate
// the memory it allocates. This should be detected by
// valgrind
#include "leaky_implementation.hpp"

int main(){
   int return_code = do_some_work();
 
   return return_code;
}
