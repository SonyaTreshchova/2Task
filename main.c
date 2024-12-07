#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "matrix.h"
#include "task.h"

#define INPUT_FILE_NAME "data.dat"

int main(void)
{
	int i;
	int j;
	int n;
	int iter;
	int rezult;
	int inputMode;
	double eps = 1e-10;
	double inv1;
	double inv2;
	double* a = NULL;
	double* values = NULL;
	FILE* fin = NULL;
	clock_t t;

    printf("Введите N: ");
	scanf("%d", &n);

    if (n < 1)
	{
		printf("Некорректное N!\n");
		return -4;
	}

    a = (double*)malloc(n * n * sizeof(double));
	values = (double*)malloc(n * sizeof(double));

	if (!(a && values))
	{
		printf("Не достаточно памяти!\n");

		if (a)
			free(a);
		if (values)
			free(values);
		return -5;
	}

	rezult = InputMatrix(n, a);

	printf("\nМатрица A:\n");
	PrintMatrix(n, a);
	printf("\n");

	//printf("Считаем...\n");

	inv1 = 0.0;
	inv2 = 0.0;
	for (i = 0; i < n; ++i)
	{
		inv1 -= a[i * n + i];
		for (j = 0; j < n; ++j)
			inv2 -= a[i * n + j] * a[j * n + i];
	}

	t = clock();
	FindValues(n, a, values, eps, &iter);
	t = clock() - t;

	for (i = 0; i < n; ++i)
	{
		inv1 += values[i];
		inv2 += values[i] * values[i];
	}

	printf("\nЗначения:\n");
	PrintVector(n, values);
	printf("\n");

	printf("Время\t= %.2f sec.\n", (double)t / CLOCKS_PER_SEC);
	printf("Действия\t= %d\n\n", iter);

	printf("Sum(x_i) - Sum(a_i)\t\t= %g\n", inv1);
	//printf("Sum(x_i ^ 2) - Sum(a_ij * a_ji)\t= %g\n", inv2);

	free(a);
	free(values);

	return 0;
}