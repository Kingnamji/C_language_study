#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct{
	char name[20];
	int  age;
	int salary;
} humanBeing;

int humansEqual( humanBeing *person1, humanBeing *person2)
{
	if( strcmp(person1->name, person2->name))
		return FALSE;

	if( person1->age != person2->age )
		return FALSE;

	if( person1->salary != person2->salary )
		return FALSE;
	
	return TRUE;
}

void main(void)
{
	humanBeing person1, person2;

	printf("Input person1's name, age, salary :\n");
	gets_s(person1.name, (unsigned)sizeof(person1.name));
	scanf_s("%d", &person1.age);
	scanf_s("%d", &person1.salary);
	
	getchar(); // 입력 버퍼 비우기

	printf("Input person2's name, age, salary :\n");
	gets_s(person2.name, (unsigned)sizeof(person2.name));
	scanf_s("%d", &person2.age);
	scanf_s("%d", &person2.salary);

	if( humansEqual( &person1, &person2 ))
		printf("The two human beings are the same\n");
	else
		printf("The two human beings are not the same\n");
}
