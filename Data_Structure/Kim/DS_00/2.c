#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i = 0, data1[10], data2[10], data3[10];
	// data input from file
	FILE *fp;

	fopen_s(&fp, "input-1.txt", "r");
	if (fp == NULL)
	{
		exit(1);
	}
	while (!feof(fp))
		fscanf_s(fp, "%d", &data1[i++]);
	fclose(fp);

	i = 0;
	fopen_s(&fp, "input-2.txt", "r");
	if (fp == NULL)
	{
		exit(1);
	}

	while (!feof(fp))
		fscanf_s(fp, "%d", &data2[i++]);
	fclose(fp);


	for (i = 0; i < 10; i++)
		data3[i] = data1[i] + data2[i];
	printf("input-1.txt : ");
	for (i = 0; i < 10; i++)
		printf("%3d, ", data1[i]);
	printf("\n");
	printf("input-2.txt : ");
	for (i = 0; i < 10; i++)
		printf("%3d, ", data2[i]);
	printf("\n");
	printf("result      : ");
	for (i = 0; i < 10; i++)
		printf("%3d, ", data3[i]);
	printf("\n");

}
