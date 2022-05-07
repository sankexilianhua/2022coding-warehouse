#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int numIdenticalPairs(int* nums, int numsSize)
{
	int ans = 0;
	int hash[101];
	memset(hash, 0, sizeof(hash));
	for (int j = 0; j<numsSize; j++)
	{
		ans += hash[nums[j]];
		++hash[nums[j]];
	}
	return ans;
}
int main()
{
	int arr[] = { 1, 2, 3, 1, 1, 3 };
	numIdenticalPairs(arr, 6);
	return 0;
}