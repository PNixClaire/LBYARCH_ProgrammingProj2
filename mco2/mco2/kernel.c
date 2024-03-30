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

extern double dotProdAsm(double *a, double* b,int n);  //EXTERN CALL HERE

int main() {
	int n = 8; //vector length
	//double a[n] = {};
	double *a = (double*) malloc(n * sizeof(double));
	//double b[n] = {};
	double *b = (double*)malloc(n * sizeof(double));
	int kernel; 

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


	printf("[1] Kernel.c [2] Kernel.asm \n Choose a Kernel to run: ");
	scanf_s("%d", &kernel);

	if (kernel == 1) {
		double kernelC = dotProdC(a, b, n);
		printf("\n%lf", kernelC);
	}
	else if (kernel == 2) {
		double kernelAsm = dotProdAsm(a, b, n); //INSERT ASSEMBLY CALL HERE
		printf("\n%lf", kernelAsm);
	}

	free(a);
	free(b);
	
	return 0;
}