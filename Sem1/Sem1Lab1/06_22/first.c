/*
 * Для целого числа k от 1 до 130 вывести фразу «Мне k лет»,
 * учитывая при этом, что при некоторых значениях k
 * слово «лет» надо заменить словом «год» или «года»
 */

#include <stdio.h>

int
main(void)
{
	for (unsigned k = 1; k <= 130; ++k) {
		printf("Мне %u ", k);
		switch (k % 10) {
		case 1:
			if ((k / 10) % 10 == 1)
				/* skip down */;
			else {
				puts("год");
				break;
			}
		case 2:
		case 3:
		case 4:
			if ((k / 10) % 10 == 1)
				/* skip down */;
			else {
				puts("года");
				break;
			}
		default:
			puts("лет");
		}
	}

	return 0;
}
