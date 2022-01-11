#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//СІПл 1636
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