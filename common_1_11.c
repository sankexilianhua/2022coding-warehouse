#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//力扣 1636
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int hash[201];
int cmp(const void*e1, const void*e2)
{
	int i = *(int*)e1 + 100;
	int j = *(int*)e2 + 100;
	if (hash[i]>hash[j])
		return 1;
	else if (hash[i]<hash[j])
		return -1;
	else
	{
		if (*(int*)e1 <= *(int*)e2)
			return 1;
		else
			return 0;
	}
}
int* frequencySort(int* nums, int numsSize, int* returnSize)
{
	memset(hash, 0, sizeof(hash));
	int i = 0;
	for (i = 0; i<numsSize; i++)
	{
		hash[nums[i] + 100]++;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = numsSize;
	return nums;
}

//力扣 1710
int cmp(void*e1, void*e2)
{
	int*arr1 = *(int**)e1;
	int*arr2 = *(int**)e2;
	if (arr1[1] <= arr2[1])
		return 1;
	else
		return 0;
}
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize)
{
	int row = boxTypesSize;
	//int col=*boxTypesColSize;
	int i = 0;
	int sum = 0;
	qsort(boxTypes, boxTypesSize, sizeof(int*), cmp);
	for (i = 0; i<row; i++)
	{
		if (truckSize)
		{
			if (truckSize >= boxTypes[i][0])
			{
				truckSize -= boxTypes[i][0];
				sum += boxTypes[i][0] * boxTypes[i][1];
			}
			else
			{
				sum += truckSize*boxTypes[i][1];
				truckSize = 0;
			}
		}
	}
	return sum;
}
//力扣 剑指offer 39
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int majorityElement(int* nums, int numsSize)
{
	if (numsSize == 1)
		return nums[0];
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	int count = 1;
	for (i = 0; i<numsSize - 1; i++)
	{
		count++;
		if (count>numsSize / 2)
			return nums[i + 1];
		if (nums[i] != nums[i + 1])
			count = 1;
	}
	return 0;
}