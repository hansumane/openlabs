/*
 * Ввести число k (от 0 до 9).
 * Вводить пятизначные числа, при выводе удалять все цифры равные k.
 * Например при k = 0 число 10045 преобразуется в 145.
 * * *
 * Прямолинейное решение, то есть просто удаляем совпадающий символ.
 */

#include <stdio.h>
#include <string.h>
#define SIZE 64

int
main(void)
{
	char buffer[SIZE];
	unsigned k, input;
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

		snprintf(buffer, SIZE, "%u", input);
		for (size_t i = 0; i < strlen(buffer); ++i)
			if (k != buffer[i] - '0')
				/*
				 * k - это число от 0 до 9, а buffer[i] - символ,
				 * который содержит цифру, то есть значение в диапазоне
				 * от '0' до '9', соответственно,
				 * '0' - '0' = 0
				 * '1' - '0' = 1 и так далее.
				 */
				putchar(buffer[i]);
		putchar('\n');
	}

	return 0;
}
