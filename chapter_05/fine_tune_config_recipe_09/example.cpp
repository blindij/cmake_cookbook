#include <iostream>
#ifdef HAVE_MPI
#include <mpi.h>
#endif

int main() {
#ifdef HAVE_MPI
   // Initialize MPI
   MPI_Init(NULL, NULL);

   // query and print the rank
   int rank;
   MPI COMM_rank(MPI_COMM_WORLD, &rank);
   std::cout << "hello from rank " << rank << std::endl;

   // Finalize MPI
   MPI_Finalize();
#else
   std::cout << "Hello from sequential binary" << std::endl;
#endif /* HAVE_MPI */
   return 0;
}
