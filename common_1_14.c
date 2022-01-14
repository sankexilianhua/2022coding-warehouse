#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//Á¦¿Û ½£Ö¸offor 03
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int findRepeatNumber(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	for (i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return 0;
}