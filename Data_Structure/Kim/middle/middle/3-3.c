#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX_NAME_SIZE 20

typedef struct humanBeing {
	char name[MAX_NAME_SIZE];
	int age;
	int salary;
}humanBeing;

int humansEqual(humanBeing* person1, humanBeing* person2);

int main(void)
{
	humanBeing person1, person2;
	printf("Input person1's name, age, salary :\n");
	gets_s(person1.name, MAX_NAME_SIZE);
	scanf_s("%d", &person1.age);
	scanf_s("%d", &person1.salary);
	getchar(); // 버퍼 비우기

	printf("Input person2's name, age, salary :\n");
	gets_s(person2.name, MAX_NAME_SIZE);
	scanf_s("%d", &person2.age);
	scanf_s("%d", &person2.salary);
	
	if (humansEqual(&person1, &person2)) {
		printf("The two human beings are the same.\n");
	}
	else {
		printf("The two human beings are not the same.\n");
	}


}

int humansEqual(humanBeing* person1, humanBeing* person2) {
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;
	
	return TRUE;
}

