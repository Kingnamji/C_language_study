#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20
typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

void main()
{
	element student;
	char tok[10];

	scanf_s("%s%d%s", tok, sizeof(tok), &student.id, student.name, sizeof(student.name));
		
	if (!strcmp(tok, "push"))
	{
		printf("student.id = %d\n", student.id);
		printf("student.id = %s\n", student.name);
	}
	else
		printf("not push");
}