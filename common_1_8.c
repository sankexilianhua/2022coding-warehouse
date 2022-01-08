#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//力扣 1122
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void exchange(int*arr, int i, int* pk)
{
	int tmp = 0;
	tmp = arr[i];
	arr[i] = arr[*pk];
	arr[*pk] = tmp;
	(*pk)++;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	//int*ans=(int*)malloc(sizeof(int)*arr1Size);
	*returnSize = arr1Size;
	int i = 0;
	int k = 0;
	for (i = 0; i<arr2Size; i++)
	{
		int j = 0;
		for (j = 0; j<arr1Size; j++)
		{
			if (arr1[j] == arr2[i])
			{
				exchange(arr1, j, &k);
			}
		}
	}
	if (k<arr1Size)
	{
		int j = k;
		int i = k;
		for (; j<arr1Size; j++)
		{
			for (i = k; i<arr1Size - 1; i++)
			{
				if (arr1[i]>arr1[i + 1])
				{
					int tmp = arr1[i];
					arr1[i] = arr1[i + 1];
					arr1[i + 1] = tmp;
				}
			}
		}
	}
	return arr1;
}

//力扣 1030
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int r0;
int c0;
int cmp(void*e1, void*e2)
{
	int* arr1 = *(int**)e1;
	int* arr2 = *(int**)e2;
	if ((abs(arr1[0] - r0) + abs(arr1[1] - c0))>(abs(arr2[0] - r0) + abs(arr2[1] - c0)))
		return 1;
	else
		return 0;
}
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes)
{
	r0 = rCenter;
	c0 = cCenter;
	int**ans = (int**)malloc(sizeof(int*)*(rows*cols));
	*returnColumnSizes = (int*)malloc(sizeof(int)*(rows*cols));
	int i = 0;
	*returnSize = rows*cols;
	for (i = 0; i<rows*cols; i++)
	{
		ans[i] = (int*)malloc(sizeof(int)* 2);
		(*returnColumnSizes)[i] = 2;
	}
	int k = 0;
	for (i = 0; i<rows; i++)
	{
		int j = 0;
		for (j = 0; j<cols; j++)
		{
			ans[k][0] = i;
			ans[k][1] = j;
			k++;
		}
	}
	qsort(ans, rows*cols, sizeof(ans[0]), cmp);
	//冒泡排序过不去，会超时
	// for(k=0;k<rows*cols-1;k++)
	// {
	//     for(i=0;i<rows*cols-1;i++)
	//     {
	//         int e1=abs(ans[i][0]-rCenter)+abs(ans[i][1]-cCenter);
	//         int e2=abs(ans[i+1][0]-rCenter)+abs(ans[i+1][1]-cCenter);
	//         if(e1>e2)
	//         {
	//             int tmp=ans[i][0];
	//             ans[i][0]=ans[i+1][0];
	//             ans[i+1][0]=tmp;
	//             tmp=ans[i][1];
	//             ans[i][1]=ans[i+1][1];
	//             ans[i+1][1]=tmp;
	//         }
	//     }
	// }
	return ans;
}