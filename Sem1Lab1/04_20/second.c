/*
 * Вводить различные символы до тех пор, пока не введен «ENTER».
 * При вводе символа "{" или "}" выводить сообщение "фигурная скобка",
 * при вводе "[" или"]" - "квадратная скобка",
 * при вводе "(" или ")" - "круглая скобка",
 * в остальных случаях - сообщение "не скобка".
 * Для решения задачи можно использовать таблицу кодов ASCII
 */

#include <stdio.h>

int
main(void)
{
	char buffer = 0;
	goto START;

	for (;;) {
		getchar();
START:
		buffer = getchar();
		switch (buffer) {
		case '{':
		case '}':
			puts("curly bracket (brace)");
			break;
		case '[':
		case ']':
			puts("square bracket");
			break;
		case '(':
		case ')':
			puts("round bracket (parenthese)");
			break;
		case '\n':
			puts("ENTER (exit)");
			return 0;
		default:
			puts("not a bracket");
		}
	}

	return 0;
}
