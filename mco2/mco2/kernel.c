#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


double randomDouble(double min, double max) {
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

double dotProdC(double* a, double* b, int n) {
	double sdot = 0.0; //store final answer

	for (int i = 0; i < n; i++)
		sdot += a[i] * b[i]; //each A element * every B element then total

	return sdot;
}

//extern void asmhello();  EXTERN CALL HERE

int main() {
	int n = 8; //vector length
	//double a[n] = {};
	double *a = malloc(n * sizeof(double));
	//double b[n] = {};
	double *b = malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {
		a[i] = 2.0;
	};

	for (int i = 0; i < n; i++) {
		b[i] = randomDouble(0.0, 10.0); 
	}

	for (int i = 0; i < n; i++) {
		printf("%lf ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%lf ", b[i]);
	}
	printf("\n");

	double kernelC = dotProdC(a, b, n);
	printf("\n%lf", kernelC);

	//double kernelAsm = dotProdAsm(a, b, n); INSERT ASSEMBLY CALL HERE
	
	return 0;
}