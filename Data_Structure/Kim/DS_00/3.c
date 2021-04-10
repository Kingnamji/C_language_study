#include <stdio.h>
#include <stdlib.h>

// ����ü ����
struct person
{
	char name[9];	// �̸�
	char gender[3];	// ����
	int age;		// ����
};

int main()
{
	FILE *fp;
	char c;
	// �� ���� ����� ������ ����ü ������ �����ϱ�
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


	printf(" �̸�   ����	���� \n");
	printf("======================\n");
	for (i = 0; i < 4; i++)
		printf("%s\t %s\t %2d\n", human[i].name, human[i].gender, human[i].age);
	printf("======================\n\n");
	printf(" << �ְ�� ���� >>\n\n");
	printf(" %s\t %s\t %2d\n\n", human[old].name, human[old].gender, human[old].age);

	fclose(fp);
	return 0;
}