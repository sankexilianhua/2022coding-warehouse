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