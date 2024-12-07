#include <stdio.h>
#include <math.h>

#include "matrix.h"

#define MAX_OUTPUT_SIZE 20

static double f(int i, int j, int n)
{
	if (i == j) {
		if (i == n-1) {
			return n;
		}
		return 1;
	}
	if (i == n-1) {
		return j + 1.0;
	}
	if (j == n-1) {
		return i + 1.0;
	}
	return 0;
}

int InputMatrix(int n, double* a)
{
	int i;
	int j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			a[i * n + j] = f(i, j, n);

	return 0;
}

void PrintMatrix(int n, double* a)
{
	int i;
	int j;
	int nPrint;

	nPrint = (n > MAX_OUTPUT_SIZE) ? MAX_OUTPUT_SIZE : n;

	for (i = 0; i < nPrint; ++i)
	{
		printf("| ");
		for (j = 0; j < nPrint; ++j)
			printf("%10.3g ", a[i * n + j]);
		printf("|\n");
	}
}

void PrintVector(int n, double* x)
{
	int i;
	int nPrint;

	nPrint = (n > MAX_OUTPUT_SIZE) ? MAX_OUTPUT_SIZE : n;

	for (i = 0; i < nPrint; ++i)
		printf("%10.3g ", x[i]);
	printf("\n");
}
