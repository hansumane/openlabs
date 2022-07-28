/*
 * Вычислить значение x = a * b / с
 * a, b, с  – целые числа, х – вещественное, a, b, с ввести с клавиатуры.
 * Реализовать контроль ошибки ввода, вывод сообщения об ошибке и повторный ввод данных.
 * Ошибка: с=0
 */

#include <stdio.h>

int
main(void)
{
	int a, b, c;
	fputs("input a, b, c separeted by white spaces*: ", stdout);
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	getchar();

	if (c == 0) {
		fputs("wrong input! must satisfy: c != 0\n", stderr);
		return 1;
	}

	printf("result: x = %lf\n", (double)a * b / c);

	return 0;
}
