#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//СІПл628
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int max(int i, int j)
{
	return i>j ? i : j;
}
int maximumProduct(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int max1 = nums[0] * nums[1] * nums[numsSize - 1];
	int max2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[0];
	max2 = max(max1, max2);
	int max3 = nums[0] * nums[1] * nums[2];
	max3 = max(max2, max3);
	int max4 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
	max4 = max(max3, max4);
	return max4;
}
//СІПл