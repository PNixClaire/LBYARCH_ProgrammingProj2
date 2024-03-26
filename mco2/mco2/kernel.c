#include <stdio.h>
#include <stdlib.h>

double dotProdC(double* a, double* b, int n) {
	double sdot = 0.0; //store final answer

	for (int i = 0; i < n; i++)
		sdot += a[i] * b[i]; //each A element * every B element then total

	return sdot;
}

extern double dotProdC(double* a, double* b, int n);

//C program to call both kernels 
int main() {

	//might do something so we can set the length and then randomize the elements
	int n = 0; //vector length
	double a[] = {};
	double b[] = {};

	double kernelC = dotProdC(A, B, n);

	double kernelAsm = dotProdAsm(A, B, n);


	return 0;
}