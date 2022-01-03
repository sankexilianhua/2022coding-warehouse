#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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
	printf("%d", nums[0]);
	int i = 0;
	int max = 1;
	for (i = 1; i<numsSize; i++)
	{
		if (nums[i] != nums[i - 1])
			max = 1;
		if (nums[i] == nums[i - 1])
			max++;
		if (max>numsSize / 2)
		{
			return nums[i];
		}
	}
	return 0;
}