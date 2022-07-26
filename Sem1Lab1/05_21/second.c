/*
 * Вводить числа, пока не будет введен ноль.
 * Определять количество цифр в числе,
 * выводить надпись «одна цифра», «две цифры» и т.п.
 */

#include <stdio.h>

int
main(void)
{
	unsigned buffer, counter, result = -1;

	while (result != 0) {
		fputs("input number: ", stdout);
		scanf("%u", &result);
		counter = 0;
		buffer = result;
		getchar();

		do {
			buffer /= 10;
			++counter;
		} while (buffer > 0);

		switch (counter) {
		case 1:
			puts("one digit");
			break;
		case 2:
			puts("two digits");
			break;
		case 3:
			puts("three digits");
			break;
		case 4:
			puts("four digits");
			break;
		case 5:
			puts("five digits");
			break;
		case 6:
			puts("six digits");
			break;
		default:
			puts("more than six digits");
		}
	}

	return 0;
}
