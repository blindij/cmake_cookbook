// File:hello_world.cpp
//
#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello(){
#ifdef IS_INTEL_CXX_COMPILER
    // only compiled when the Intel compiler is selected
    // such a compiler will not compile the other branches
    return std::string("Hello from Intel compiler!");
#elif IS_GNU_CXX_COMPILER
    // only compile when the GNU Compiler is selected
    // such a comiler will not compile the other branches
    return std::string("Hello from GNU compiler!");
#elif IS_PGI_CXX_COMPILER
    // only compile when the PGI Compiler is selected
    // such a compiler will not compile the other branches
    return std::string("Hello from PGI compiler!");
#elif IS_XL_CXX_COMPILER
    // only compile when the XL Compiler is selected
    // such a compiler will not compile the other branches
    return std::string("Hello from XL compiler!");
#else
    return std::string("Hello unknown compiler - have we met before?");
#endif
}

int main(){
    std::cout << say_hello() << std::endl;
    std::cout << "compiler name is " COMPILER_NAME << std::endl;
    return EXIT_SUCCESS;
}