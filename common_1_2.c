#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int slip(int*arr, int j, int n)
//{
//	if (j >= n - 1)
//		return n - 1;
//	while (arr[j] == arr[j + 1] && j<n - 1)
//	{
//		j++;
//	}
//	return j;
//}
//int cmp(void*e1, void*e2)
//{
//	if (*(int*)e1 >= *(int*)e2)
//		return 1;
//	else
//		return 0;
//}
//int findLHS(int* nums, int numsSize)
//{
//	qsort(nums, numsSize, sizeof(int), cmp);
//	int i = 0;
//	int max = 0;
//	for (; i<numsSize - 1;)
//	{
//		int j = i;
//		j = slip(nums, j, numsSize);
//		j++;
//		int tmp = j;
//		j = slip(nums, j, numsSize);
//		if (j - i + 1>max&&nums[j] - nums[i] == 1)
//			max = j - i + 1;
//		i = tmp;
//		if (j == numsSize - 1)
//			break;
//	}
//	return max;
//}
int slip(int*arr, int j, int n)
{
	if (j >= n - 1)
		return n - 1;
	while (j<n - 1 && arr[j] == arr[j + 1])
	{
		j++;
	}
	return j;
}
int cmp(void*e1, void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int findLHS(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	int max = 0;
	for (; i<numsSize - 1;)
	{
		int j = i;
		j = slip(nums, j, numsSize);
		j++;
		int tmp = j;
		j = slip(nums, j, numsSize);
		if (j - i + 1>max&&nums[j] - nums[i] == 1)
			max = j - i + 1;
		i = tmp;
		if (j == numsSize - 1)
			break;
	}
	return max;
}
int main()
{
	int nums[]= { 1, 1, 1, 1, 1, 1, 1, 1 };
	int n = 8;
	int max=findLHS(nums, n);
	printf("%d",max);
	system("pause");
	return 0;
}