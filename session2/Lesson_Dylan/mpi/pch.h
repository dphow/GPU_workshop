/* pch.h
 * PreCompiled Header for this lesson
 * Contains the constants, headers, and function prototypes used in other files
 */

#ifndef PCH_H_STENCIL
#define PCH_H_STENCIL

// Define the size of the vectors & matrix
#define V_SIZE 1024
#define M_SIZE V_SIZE*V_SIZE

#define TOPO 4

#define DEFAULT_DOMAIN_SIZE_PER_RANK 256

#define DIR_TOP				0
#define DIR_RIGHT			1
#define DIR_BOTTOM			2
#define DIR_LEFT			3

#define HasNeighbor(neighbors, dir)	(neighbors[dir] != MPI_PROC_NULL)

// Max number of iterations to run the Jacobi algorithm for
#define JACOBI_MAX_ITR 1000
// Convergence tolerance
#define JACOBI_TOLERANCE 1.0E-6F
// Verification tolerance
#define VERIFY_TOL	 1.0E-6F

#define Swap(x,y) {float* temp; temp = x; x = y; y = temp;}

// =======================
// Functions in common.cpp
// =======================
void InitializeMatrixSame(float *array, const int ny, const int nx, const float val, const char *name);
void InitializeMatrixRand(float *array, const int ny, const int nx, const char *name);
void MatrixVerification(float *hostC, float *gpuC, const int ny, const int nx, const float fTolerance);
void PrintMatrix(float *matrix, int ny, int nx);
void copyMatrix(float *src, float *dest, const int ny, const int nx);

// =============
// Host routines
// =============
void LaplaceJacobi_naiveCPU(float *M, const int b, const int ny, const int nx, const int max_itr, const float threshold);

// ==========================
// Device and OpenACC Routines
// ==========================
void LaplaceJacobi_naiveACC(float *M, const int b, const int ny, const int nx, const int max_itr, const float threshold);
#endif // PCH_H_STENCIL