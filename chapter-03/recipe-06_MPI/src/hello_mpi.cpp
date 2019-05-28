// File: hello_mpi.cpp
//
// Example MPI-program, initializes the library and print process name
#include <iostream>
#include <mpi.h>

int main(int argc, char **argv){
   // Initialize the MPI environment
   MPI_Init(NULL,NULL);

   // Get the number of process
   int world_size;
   MPI_Comm_size(MPI_COMM_WORLD, &world_size);

   // Get the rank of the process
   int world_rank;
   MPI_Comm_rank(MPI_COMM_WORLD, &world_size);

   // Get the rank  of the process
   char processor_name[MPI_MAX_PROCESSOR_NAME];
   int name_len;
   MPI_Get_processor_name(processor_name, &name_len);

   // Print off a hello world message
   std::cout << "Hello world from processor " << processor_name
             << ", rank " << world_rank << " out of " << world_size
             << " processors" << std::endl;

   // End the MPI environment
   MPI_Finalize();
}
