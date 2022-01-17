#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//力扣 1608
int cmp(const void*e1, const void* e2)
{
	if (*(int*)e1 >= *(int*)e2)
		return 1;
	else
		return 0;
}
int specialArray(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int i = 0;
	for (i = 0; i <= nums[numsSize - 1]; i++)
	{
		int j = 0;
		int count = 0;
		for (; j<numsSize; j++)
		{
			if (nums[j] >= i)
				count++;
		}
		if (count == i)
			return i;
	}
	return -1;
}

//力扣 剑指offor二 032
int cnt1[26];
int cnt2[26];
bool isAnagram(char * s, char * t)
{
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	int len1 = strlen(s);
	int len2 = strlen(t);
	if (len1 != len2)
		return false;
	int i = 0;
	for (i = 0; i<len1; i++)
	{
		int j = s[i] - 'a';
		cnt1[j]++;
	}
	for (i = 0; i<len2; i++)
	{
		int j = t[i] - 'a';
		cnt2[j]++;
	}
	for (i = 0; i<26; i++)
	if (cnt1[i] != cnt2[i])
		return false;
	for (i = 0; i<len1; i++)
	{
		if (s[i] != t[i])
			return true;
	}
	return false;
}
//超时写法：
// bool isAnagram(char * s, char * t)
// {
//    int len1=strlen(s);
//    int len2=strlen(t);
//    if(len1!=len2)
//    return false;
//    int i =0;
//    int count1=0;
//    int count2=0;
//    for(i=0;i<len1;i++)
//    {
//        int j=0;
//       for(j=0;j<len2;j++)
//       {
//         if(s[i]==t[j])
//       {
//           t[j]=-2;
//           count1++;
//           if(i==j)
//           count2++;
//           break;
//       }
//       }
//    }
//    if(count1!=len1||count2==len1)
//    return false;
//    return true;
// }

int main()
{
	return 0;
}