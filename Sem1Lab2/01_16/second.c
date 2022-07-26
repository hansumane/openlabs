/*
 * Дана целочисленная матрица 8x8.
 * Найти сумму элементов в заштрихованной области.
 * Сформировать одномерный массив, состоящий из сумм элементов нечетных столбцов.
 * [1 0 0 0 0 0 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 0 0 0 0 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 0 0 0 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 1 0 0 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 1 1 0 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 1 1 1 0 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 1 1 1 1 0]   [1 0 1 0 1 0 1 0]
 * [1 1 1 1 1 1 1 1]   [1 0 1 0 1 0 1 0]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const size_t N = 8;
static const size_t T = N / 2 + N % 2;

int
findsum(int matrix[N][N])
{
	int sum = 0;
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j <= i; ++j)
			sum += matrix[i][j];
	return sum;
}

void
formarray(int array[N * T], int matrix[N][N])
{
	size_t index = 0;
	for (size_t j = 0; j < N; j += 2)
		for (size_t i = 0; i < N; ++i)
			array[index++] = matrix[i][j];
}

int
main(void)
{
	srand(time(NULL));

	int matrix[N][N];
	int array[N * T];

	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			matrix[i][j] = rand() % 90 + 10;
			printf("%d, ", matrix[i][j]);
		}
		puts("\b\b ");
	}
	printf("sum: %d\n", findsum(matrix));

	fputs("arr: ", stdout);
	formarray(array, matrix);
	for (size_t i = 0; i < N * T; ++i)
		printf("%d, ", array[i]);
	puts("\b\b ");

	return 0;
}
