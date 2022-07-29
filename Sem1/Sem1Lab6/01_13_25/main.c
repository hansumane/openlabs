#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef BUFSIZ
	#define CHDEF \
		(fputs("\nWarning! Changed default definitions!\n\n", stderr))
	#undef BUFSIZ
#endif /* BUFSIZ */
#define BUFSIZ 256

typedef struct student {
	char *sn;  /* surname */
	char *nm;  /* name */
	char *cr;  /* curriculum */
	int gn;    /* group number */
} student_t;

typedef struct student_container {
	student_t *arr;
	size_t sz;
} student_arr_t;

void
usafgetl(char **string, size_t famount, char *desc)
{
	printf("Input %s: ", desc);
	fgets(*string, famount, stdin);
	if ((*string)[strlen(*string) - 1] == '\n')
		(*string)[strlen(*string) - 1] = 0;
}

void
student_print(student_arr_t *studarr)
{
	printf("%-20s | %-20s | %s\n%s\n",
	       "Surname",
	       "Name",
	       "Group",
	       "---------------------+----------------------+----------");
	for (size_t i = 0; i < studarr->sz; ++i)
		printf("%-20s | %-20s | %s-%d\n",
		       studarr->arr[i].sn,
		       studarr->arr[i].nm,
		       studarr->arr[i].cr,
		       studarr->arr[i].gn);
	putchar('\n');
}

void
student_print_cr(student_arr_t *studarr)
{
	char *buffer = (char *)malloc(BUFSIZ * sizeof(char));
	usafgetl(&buffer, BUFSIZ, "curriculum");

	printf("%-20s | %-20s | %s\n%s\n",
	       "Surname",
	       "Name",
	       "Group number",
	       "---------------------+----------------------+-----------------");
	for (size_t i = 0; i < studarr->sz; ++i)
		if (!strcmp(buffer, studarr->arr[i].cr))
			printf("%-20s | %-20s | %d\n",
			       studarr->arr[i].sn,
			       studarr->arr[i].nm,
			       studarr->arr[i].gn);

	putchar('\n');
	free(buffer);
}

void
student_print_gr(student_arr_t *studarr)
{
	int group;
	char *buffer = (char *)malloc(BUFSIZ * sizeof(char));
	usafgetl(&buffer, BUFSIZ, "curriculum");
	fputs("Input group number: ", stdout);
	scanf("%d", &group);
	getchar();

	printf("%-20s | %-20s\n%s\n",
	       "Surname",
	       "Name",
	       "---------------------+----------------------");
	for (size_t i = 0; i < studarr->sz; ++i)
		if (!strcmp(buffer, studarr->arr[i].cr)
		    && group == studarr->arr[i].gn)
			printf("%-20s | %-20s\n",
			       studarr->arr[i].sn,
			       studarr->arr[i].nm);

	putchar('\n');
	free(buffer);
}

void
student_add(student_arr_t *studarr)
{
	char *buffer = (char *)malloc(BUFSIZ * sizeof(char));

	studarr->arr = (student_t *)realloc(studarr->arr, ++(studarr->sz) * sizeof(student_t));

	usafgetl(&buffer, BUFSIZ, "surname");
	studarr->arr[studarr->sz - 1].sn =
		(char *)calloc(strlen(buffer) + 1, sizeof(char));
	strcpy(studarr->arr[studarr->sz - 1].sn, buffer);

	usafgetl(&buffer, BUFSIZ, "name");
	studarr->arr[studarr->sz - 1].nm =
		(char *)calloc(strlen(buffer) + 1, sizeof(char));
	strcpy(studarr->arr[studarr->sz - 1].nm, buffer);

	usafgetl(&buffer, BUFSIZ, "curriculum");
	studarr->arr[studarr->sz - 1].cr =
		(char *)calloc(strlen(buffer) + 1, sizeof(char));
	strcpy(studarr->arr[studarr->sz - 1].cr, buffer);

	fputs("Input group number: ", stdout);
	scanf("%d", &studarr->arr[studarr->sz - 1].gn);
	getchar();

	puts("Successfully added new entry!\n");
	free(buffer);
}

void
student_sort(student_arr_t *studarr)
{
	student_t student_buffer;

	for (size_t i = 0; i < studarr->sz - 1; ++i)
		for (size_t j = 0; j < studarr->sz - 1 - i; ++j)
			if (strcmp(studarr->arr[j].sn, studarr->arr[j + 1].sn) > 0
			    || (strcmp(studarr->arr[j].sn, studarr->arr[j + 1].sn) == 0
			    && strcmp(studarr->arr[j].nm, studarr->arr[j + 1].nm) > 0)) {
				student_buffer = studarr->arr[j];
				studarr->arr[j] = studarr->arr[j + 1];
				studarr->arr[j + 1] = student_buffer;
			}
}
				

void
student_free(student_arr_t *studarr)
{
	for (size_t i = 0; i < studarr->sz; ++i) {
		free(studarr->arr[i].sn);
		free(studarr->arr[i].nm);
		free(studarr->arr[i].cr);
	}
	free(studarr->arr);
	studarr->arr = NULL;
	studarr->sz = 0;
	puts("\nSuccessfully cleaned memory and exiting...");
}

int
main(void)
{
#ifdef CHDEF
	CHDEF;
#endif
	char option = 0;
	student_arr_t array;
	array.sz = 0;
	array.arr = (student_t *)calloc(array.sz, sizeof(student_t));

	for (;;) {
		switch(option) {
		case '0':
			goto END;
		case '1':
			student_add(&array);
			break;
		case '2':
			student_print(&array);
			break;
		case '3':
			student_print_cr(&array);
			break;
		case '4':
			student_sort(&array);
			student_print_gr(&array);
			break;
		default:
			fputs("Help: 0 - exit\n"
			      "      1 - add\n"
			      "      2 - print\n"
			      "      3 - print by curriculum\n"
			      "      4 - sort and print by group\n", stdout);
		}
		fputs("Input command: ", stdout);
		scanf("%c", &option);
		getchar();
	}

END:
	student_free(&array);

	return 0;
}
