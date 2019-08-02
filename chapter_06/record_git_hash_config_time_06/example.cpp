#include "version.hpp"
#include <iostream>

int main(void){
   std::cout   << "This code has been configure from version " << GIT_HASH
               << std::endl;
   return 0;
}
