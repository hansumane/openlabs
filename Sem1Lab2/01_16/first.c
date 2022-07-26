/*
 * В массиве Х(N) найти сумму элементов,
 * расположенных после максимального элемента.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../epi.h"

int
main(void)
{
	srand(time(NULL));
	const size_t size = (size_t)(rand() % 6 + 5);
	int array[size], sum = 0, max = MININT, maxpos = -1;

	for (size_t i = 0; i < size; ++i) {
		array[i] = rand() % 90 + 10;
		printf("%d, ", array[i]);
		if (array[i] > max) {
			max = array[i];
			maxpos = i;
		}
	}
	puts("\b\b ");

	for (size_t i = maxpos + 1; i < size; ++i) {
		sum += array[i];
		printf("%d, ", array[i]);
	}
	puts("\b\b ");
	printf("sum: %d\n", sum);

	return 0;
}
