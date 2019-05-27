// File: CxxLAPACK.hpp
//
// Interface file for doing name mangling
#ifndef CXXLAPACK_HPP
#define CXXLAPACK_HPP
#include "fc_mangle.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int DGESV(int *, int *, double *, int *, int *,  double *, int *, int *);

#ifdef __cplusplus
}
#endif

int C_DGESV(int n, int nrhs, double *a, int lda, int *ipiv, double *b, int ldb);

#endif // end CXXLAPACK_HPP
