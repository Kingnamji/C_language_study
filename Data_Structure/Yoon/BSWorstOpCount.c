#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0; // 탐색 대상의 시작 인덱스 값
	int last = len - 1; // 탐색 대상의 마지막 인덱스 값
	int mid;
	int opCount = 0; // 연산 횟수를 기록

	while (first <= last)
	{
		mid = (first + last) / 2; // 탐색 대상의 중앙을 찾는다.

		if (target == ar[mid]) // 중앙에 저장된 것이 타겟이라면
		{
			return mid; // 탐색 완료
		}
		else // 타겟이 아니라면 탐색 대상을 반으로 줄인다.
		{
			if (target < ar[mid])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		opCount += 1; // 비교연산 횟수 1회 증가
	}
	printf("비교연산횟수 : %d \n", opCount); // 탐색실패 시 연산횟수 출력
	return -1; // 찾지 못했을 때 반환값
}


int main(void)
{
	int arr1[500] = { 0, }; // 모든 요소 0으로 초기화
	int arr2[5000] = { 0, }; // 모든 요소 0으로 초기화
	int arr3[50000] = { 0, }; // 모든 요소 0으로 초기화
	int idx;

	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n\n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n\n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n\n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	return 0;
}