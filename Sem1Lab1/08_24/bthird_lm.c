/*
 * Ввести число k (от 0 до 9).
 * Вводить пятизначные числа, при выводе удалять все цифры равные k.
 * Например, при k = 0 число 10045 преобразуется в 145.
 * * *
 * Решение с использованием встроенных библиотечных
 * математических функций log10() и pow()
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	unsigned n, k, input;
	fputs("input k: ", stdout);
	scanf("%u", &k);
	getchar();

	if (k > 9u) {
		fputs("wrong input! must satisfy: k >= 0 and k <= 9\n", stderr);
		return 1;
	}

	for (;;) {
		fputs("input number: (0 to exit) ", stdout);
		scanf("%u", &input);
		getchar();

		if (input == 0u)
			break;

		for (int i = (int)log10((double)input); i >= 0; --i)
			/*
			 * Вычисляем целое i такое, что 10^i <= input < 10^(i + 1)
			 * Например, i от 10045 = 4, так как 10^4 = 10000.
			 */
			if ((n = (unsigned)((double)input / pow(10.0, (double)i)) % 10u) != k)
				/*
				 * В цикле перебираем все цифры n числа input,
				 * от самой старшей к самой младшей, и проверяем,
				 * чтобы эта цифра не равнялась k.
				 */
				printf("%u", n);
		putchar('\n');
	}

	return 0;
}
