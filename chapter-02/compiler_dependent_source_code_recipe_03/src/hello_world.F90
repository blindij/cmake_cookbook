program hello
 implicit none

#ifdef IS_Intel_FORTRAN_COMPILER
    print *, 'Hello Intel compiler!'
#elfi IS_GNU_FORTRAN_COMPILER
    print *, 'Helllo GNU compiler!'
#elfi IS_PGI_FORTRAN_COMPILER
    print *, 'Hello PGI compiler!'
#elfi IS_XL_FORTRAN_COMPILER
    print *, 'Hello XL compiler!'
#else
    print *, 'Hello unknown compiler - have we met before?'
#endif

end program