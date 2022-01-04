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
//СІПл 888
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int find(int*arr1, int*arr2, int arr1size, int arr2size, int dig1, int dig2)
{
	int flag1 = 0;
	int flag2 = 0;
	int left1 = 0;
	int right1 = arr1size;
	int left2 = 0;
	int right2 = arr2size;
	while (left1 <= right1)
	{
		int mid = (left1 + right1) / 2;
		if (arr1[mid] == dig1)
		{
			flag1 = 1;
			break;
		}
		if (arr1[mid]>dig1)
			right1 = mid - 1;
		if (arr1[mid]<dig1)
			left1 = mid + 1;
	}
	while (left2 <= right2)
	{
		int mid = (left2 + right2) / 2;
		if (arr2[mid] == dig2)
		{
			flag2 = 1;
			break;
		}
		if (arr2[mid]>dig2)
			right2 = mid - 1;
		if (arr2[mid]<dig2)
			left2 = mid + 1;
	}
	if (flag1 == 1 && flag2 == 1)
		return 0;
	else
		return 1;
}
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return  1;
	else
		return 0;
}
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int)* 2);
	int i = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i<aliceSizesSize; i++)
		sum1 += aliceSizes[i];
	for (i = 0; i<bobSizesSize; i++)
		sum2 += bobSizes[i];
	int dig1 = abs((sum1 + sum2) / 2 - sum1) + 1;
	int dig2 = 1;
	int flag = 1;
	qsort(aliceSizes, aliceSizesSize, sizeof(int), cmp);
	qsort(bobSizes, bobSizesSize, sizeof(int), cmp);
	for (; flag != 0;)
	{
		if (sum1<sum2)
			flag = find(aliceSizes, bobSizes, aliceSizesSize, bobSizesSize, dig2, dig1);
		else
			flag = find(bobSizes, aliceSizes, bobSizesSize, aliceSizesSize, dig2, dig1);
		dig1++;
		dig2++;
	}
	if (sum1<sum2)
	{
		ans[0] = dig2 - 1;
		ans[1] = dig1 - 1;
	}
	else
	{
		ans[1] = dig2 - 1;
		ans[0] = dig1 - 1;
	}
	*returnSize = 2;
	return ans;
}