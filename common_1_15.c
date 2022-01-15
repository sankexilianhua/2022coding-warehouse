#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//力扣 1491
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
double trimMean(int* arr, int arrSize)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	int j = arrSize*0.05;
	int i = j;
	int sum = 0;
	for (; i<arrSize - j; i++)
		sum += arr[i];
	double ret = sum*1.0 / (arrSize - 2 * j);
	return ret;
}

//力扣 LCS 02
int cmp(const void*e1, const void*e2)
{
	if (*(int*)e1 <= *(int*)e2)
		return 1;
	else
		return 0;
}
int cnt[1001];
int halfQuestions(int* questions, int questionsSize)
{
	memset(cnt, 0, sizeof(cnt));
	int i = 0;
	for (i = 0; i<questionsSize; i++)
		cnt[questions[i]]++;
	int count = 0;
	int sum = 0;
	int j = questionsSize / 2;
	qsort(cnt, 1001, sizeof(int), cmp);
	for (i = 0; i<1001; i++)
	{
		sum += cnt[i];
		if (sum >= j)
			return i + 1;
	}
	return 0;
}
//力扣 面试题01.02
bool CheckPermutation(char* s1, char* s2)
{
	int len1 = strlen(s1);
	int len = strlen(s2);
	if (len1 != len)
		return false;
	for (int i = 0; i <= len; i++)
	{
		int j = 0;
		for (; j <= len; j++)
		if (s1[j] == s2[i])
		{
			s1[j] = -1;
			break;
		}
		if (j == len + 1)
			return false;
	}
	return true;
}
