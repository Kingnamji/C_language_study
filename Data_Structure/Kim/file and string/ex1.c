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
	char input[80];
	char* delimiter = " ";
	char* next_str;
	char* tok = NULL;

	gets_s(input, sizeof(input));
	tok = strtok_s(input, delimiter, &next_str);
	printf("tok = %s, next_str = %s\n", tok, next_str);
	if (!strcmp(tok, "push"))
	{
		sscanf_s(input + strlen(tok) + 1, "%d%s", &student.id, student.name, sizeof(student.name));
		printf("student.id = %d\n", student.id);
		printf("student.id = %s\n", student.name);
	}
	else
		printf("not push");
}