#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//力扣 1051
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

//力扣  1460
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

//力扣 剑指offer2 075
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void exchange(int*arr, int i, int* pk)
{
	int tmp = 0;
	tmp = arr[i];
	arr[i] = arr[*pk];
	arr[*pk] = tmp;
	(*pk)++;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	//int*ans=(int*)malloc(sizeof(int)*arr1Size);
	*returnSize = arr1Size;
	int i = 0;
	int k = 0;
	for (i = 0; i<arr2Size; i++)
	{
		int j = 0;
		for (j = 0; j<arr1Size; j++)
		{
			if (arr1[j] == arr2[i])
			{
				exchange(arr1, j, &k);
			}
		}
	}
	if (k<arr1Size)
	{
		int j = k;
		int i = k;
		for (; j<arr1Size; j++)
		{
			for (i = k; i<arr1Size - 1; i++)
			{
				if (arr1[i]>arr1[i + 1])
				{
					int tmp = arr1[i];
					arr1[i] = arr1[i + 1];
					arr1[i + 1] = tmp;
				}
			}
		}
	}
	return arr1;
}