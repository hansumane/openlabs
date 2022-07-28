/*
 * Определить название числа от 0 до 10, например,
 * при вводе числа 5 писать «пять», если число >10,
 * писать «число должно быть меньше 10»
 */

#include <stdio.h>

int
main(void)
{
	unsigned number;
	fputs("input number: ", stdout);
	scanf("%u", &number);
	getchar();

	switch (number) {
	case 0:
		puts("zero");
		break;
	case 1:
		puts("one");
		break;
	case 2:
		puts("two");
		break;
	case 3:
		puts("three");
		break;
	case 4:
		puts("four");
		break;
	case 5:
		puts("five");
		break;
	case 6:
		puts("six");
		break;
	case 7:
		puts("seven");
		break;
	case 8:
		puts("eight");
		break;
	case 9:
		puts("nine");
		break;
	default:
		puts("number must satisfy: 0 <= number < 10");
		return 1;
	}

	return 0;
}
