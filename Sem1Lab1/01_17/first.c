/*
 * Подсчитать площадь круга по введенному с клавиатуры радиусу.
 * Реализовать контроль ошибки ввода, вывод сообщения об ошибке
 * и повторный ввод данных.
 * Ошибка: нулевое и отрицательное значение радиуса.
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	double radius = 0.0l;
	goto START;

	while (radius <= 0.0l) {
		fputs("wrong input! must satisfy: radius > 0\n", stderr);
START:
		fputs("input radius: ", stdout);
		scanf("%lf", &radius);
		getchar();
	}

	printf("result: %lf\n", M_PI * radius * radius);
	return 0;
}
