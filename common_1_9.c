#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//СІПл 88
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 <= *(int*)e2)
		return 0;
	else
		return 1;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m;
	int j = 0;
	while (i<m + n)
	{
		nums1[i] = nums2[j];
		i++;
		j++;
	}
	qsort(nums1, m + n, sizeof(int), cmp);
}