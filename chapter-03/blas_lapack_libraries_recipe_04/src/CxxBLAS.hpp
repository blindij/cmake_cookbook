// File: CxxBLAS.hpp
//
// Interface file for doing name mangling. The functions C_DSCAL
// and C_GESV will be called from another language
#ifndef CXXBLAS_HPP
#define CXXBLAS_HPP
#include "fc_mangle.h"
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif

extern void DSCAL(int *n, double *alpha, double *vec, int *inc);

#ifdef __cplusplus
}
#endif

void C_DSCAL(size_t length, double alpha, double *vec, int inc);

#endif // end of CXXBLAS_HPP
