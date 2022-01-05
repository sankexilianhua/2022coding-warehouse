#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���� 2089
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int)*numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	int j = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (target == nums[i])
			ans[j++] = i;
	}
	*returnSize = j;
	return ans;
}