#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void reverse(char**ans, int j, int k)
{
	int left = 0;
	int right = k - 1;
	while (left<right)
	{
		int tmp = ans[j][left];
		ans[j][left] = ans[j][right];
		ans[j][right] = tmp;
		left++;
		right--;
	}
}
void process(char**ans, int i, int j)
{
	int k = 0;
	int tmp = i;
	switch (i)
	{
	case 1:
		ans[j] = "Gold Medal";
		break;
	case 2:
		ans[j] = "Silver Medal";
		break;
	case 3:
		ans[j] = "Bronze Medal";
		break;
	default:
		//process2(ans,i,j);
		while (tmp)
		{
			char ch = tmp % 10 + '0';
			tmp /= 10;
			ans[j][k++] = ch;
		}
		ans[j][k] = '\0';
		reverse(ans, j, k);
		break;
	}
}
int cmp(void*e1, void*e2)
{
	if (*(int*)e1 <= *(int*)e2)
		return 1;
	else
		return 0;
}
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize)
{
	char** ans = (char**)malloc(sizeof(char*)*scoreSize);
	int i = 0;
	for (i = 0; i<scoreSize; i++)
	{
		ans[i] = (char*)malloc(sizeof(char)* 16);
	}
	*returnSize = scoreSize;
	int arr[scoreSize];
	for (i = 0; i<scoreSize; i++)
		arr[i] = score[i];
	qsort(arr, scoreSize, sizeof(int), cmp);
	//printf("%d",arr[0]);
	for (i = 0; i<scoreSize; i++)
	{
		int j = 0;
		for (j = 0; j<scoreSize; j++)
		{
			if (arr[i] == score[j])
			{
				process(ans, i + 1, j);
				break;
			}
		}
	}

	return ans;
}
int main()
{

	return 0;
}