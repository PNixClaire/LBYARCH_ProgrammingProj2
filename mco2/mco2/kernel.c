#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

double dotProdC(double* a, double* b, int n) {
	double sdot = 0.0; //store final answer

	for (int i = 0; i < n; i++)
		sdot += a[i] * b[i]; //each A element * every B element then total

	return sdot;
}

//extern void asmhello(); CALL THE ASM FUNCITION HERE

int main() {
	int n = 8; //vector length
	//double a[n] = {};
	double *a = malloc(n * sizeof(double));
	//double b[n] = {};
	double *b = malloc(n * sizeof(double));


	a[0] = 2.0;
	a[1] = 2.0;
	a[2] = 2.0;
	a[3] = 2.0;
	a[4] = 2.0;
	a[5] = 2.0;
	a[6] = 2.0;
	a[7] = 2.0;

	b[0] = 2.0;
	b[1] = 4.0;
	b[2] = 6.0;
	b[3] = 8.0;
	b[4] = 10.0;
	b[5] = 12.0;
	b[6] = 14.0;
	b[7] = 16.0;

	// asmhello();  INSERT  ASSEMBLY FUNCTION HERE
	double kernelC = dotProdC(a, b, n);
	printf("%lf", kernelC);

	//double kernelAsm = dotProdAsm(a, b, n);
	
	return 0;
}