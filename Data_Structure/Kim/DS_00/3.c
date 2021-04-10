#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
struct person
{
	char name[9];	// 이름
	char gender[3];	// 성별
	int age;		// 나이
};

int main()
{
	FILE *fp;
	char c;
	// 네 명의 사용자 정보를 구조체 변수에 저장하기
	struct person human[4];
	int i = 0, old = 0;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		exit(1);
	}
	fscanf_s(fp, "%s %s %d", human[i].name, sizeof(human[i].name), &human[i].gender, sizeof(human[i].gender), &human[i].age);
	//fscanf_s(fp, "%c", &c, 1);
	do {
		i++;
		fscanf_s(fp, "%s %s %d", human[i].name, sizeof(human[i].name), &human[i].gender, sizeof(human[i].gender), &human[i].age);
		//fscanf_s(fp, "%c", &c, 1);
		if (human[old].age < human[i].age)
			old = i;

	} while (!feof(fp));


	printf(" 이름   성별	나이 \n");
	printf("======================\n");
	for (i = 0; i < 4; i++)
		printf("%s\t %s\t %2d\n", human[i].name, human[i].gender, human[i].age);
	printf("======================\n\n");
	printf(" << 최고령 정보 >>\n\n");
	printf(" %s\t %s\t %2d\n\n", human[old].name, human[old].gender, human[old].age);

	fclose(fp);
	return 0;
}