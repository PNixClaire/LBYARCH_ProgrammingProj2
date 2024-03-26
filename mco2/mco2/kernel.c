#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

double dotProd(double* a, double* b, int n) {
	double sdot = 0.0; //final value
	int i;

	for (i = 0; i < n; i++) {
		sdot += a[i] * b[i]; //multiply each element in A to each element in B then total
	}

	return sdot;
}