#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//СІПл 1403
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
int mysum1(int* arr, int i)
{
	int j = 0;
	int sum = 0;
	for (j = 0; j<i; j++)
	{
		sum += arr[j];
	}
	return sum;
}
int mysum2(int*arr, int numsSize, int i)
{
	int sum = 0;
	for (; i<numsSize; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int* minSubsequence(int* nums, int numsSize, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int)*numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = numsSize - 1;
	int k = 0;
	for (; i >= 0; i--)
	{
		int sum1 = mysum1(nums, i);
		int sum2 = mysum2(nums, numsSize, i);
		if (sum2>sum1)
		{
			*returnSize = numsSize - i;
			int j = 0;
			for (; numsSize - 1 >= i; numsSize--)
				ans[k++] = nums[numsSize - 1];
			break;
		}
	}
	return ans;
}
//СІПл  1200
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	int min = abs(arr[0] - arr[1]);
	for (i = 0; i<arrSize - 1; i++)
	{
		int dis = abs(arr[i] - arr[i + 1]);
		if (dis<min)
			min = dis;
	}
	int count = 0;
	for (i = 0; i<arrSize - 1; i++)
	if (abs(arr[i] - arr[i + 1]) == min)
		count++;
	int** ans = (int**)malloc(sizeof(int*)*count);
	*returnColumnSizes = (int*)malloc(sizeof(int)* count);
	for (i = 0; i<count; i++)
	{
		(*returnColumnSizes)[i] = 2;
		ans[i] = (int*)malloc(sizeof(int)* 2);
	}
	int k = 0;
	for (i = 0; i<arrSize - 1; i++)
	{
		int dis = abs(arr[i] - arr[i + 1]);
		if (dis == min)
		{
			ans[k][0] = arr[i];
			ans[k][1] = arr[i + 1];
			k++;
		}
	}
	*returnSize = count;
	printf("%d", ans[0][1]);
	return ans;
}