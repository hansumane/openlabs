/*
 * Ввести с клавиатуры X и m, вычислить S,
 * выдать сообщение об ошибке, если m < 0 или X = 0
 * S = 
 *        2 * m + 1
 *          ---        1
 *          \        -----
 *          /        i * X
 *          ---
 *       i = 1, 3, 5, ...
 */

#include <stdio.h>

int
main(void)
{
	int m;
	double X, S = 0.0;

	fputs("input m: ", stdout);
	scanf("%d", &m);
	getchar();
	if (m < 0) {
		fputs("must satisfy: m >= 0\n", stderr);
		return 1;
	}

	fputs("input X: ", stdout);
	scanf("%lf", &X);
	getchar();
	if (X == 0.0) {
		fputs("must satisfy: X != 0\n", stderr);
		return 2;
	}

	for (int i = 1; i <= 2 * m + 1; i += 2)
		S += 1 / (i * X);
	printf("result: S = %lf\n", S);

	return 0;
}
