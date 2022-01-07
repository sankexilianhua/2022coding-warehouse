#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//СІПл 1051
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int heightChecker(int* heights, int heightsSize)
{
	int i = 0;
	int* arr = (int*)malloc(sizeof(int)*heightsSize);
	for (i = 0; i<heightsSize; i++)
		arr[i] = heights[i];
	qsort(heights, heightsSize, sizeof(int), cmp);
	int count = 0;
	for (i = 0; i<heightsSize; i++)
	if (arr[i] != heights[i])
		count++;
	return count;
}

//СІПл  1460
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize)
{
	if (targetSize != arrSize)
		return false;
	int i = 0;
	qsort(target, targetSize, sizeof(int), cmp);
	qsort(arr, arrSize, sizeof(int), cmp);
	for (i = 0; i<arrSize; i++)
	if (arr[i] != target[i])
		return false;
	return true;
}