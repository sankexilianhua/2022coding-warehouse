#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int process(char* res, char* des, int i, int k)
{
	int j = i;
	for (; j >= 0; j--)
	{
		if (res[j] == ' ')
		{
			break;
		}
	}
	j++;
	for (; j<i; j++)
	{
		des[k++] = res[j];
	}
	des[k++] = ' ';
	return k;
}
char * sortSentence(char * s)
{
	int len = strlen(s);
	char* ans = (char*)malloc(sizeof(char)* 201);
	ans[0] = ' ';
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i<len; i++)
	{
		ans[i + 1] = s[i];
	}
	for (i = 1; i <= 9; i++)
	{
		int flag = 1;
		for (j = 0; j <= len; j++)
		{
			char ch = i + '0';
			if (ans[j] == ch)
			{
				//printf("%d\n",j);
				k = process(ans, s, j, k);
				printf("%s\n", s);
				flag = 0;
			}
		}
		if (flag != 0)
			break;
	}
	s[k - 1] = '\0';
	return s;
}


int main()
{
	char s[] = "is2 sentence4 This1 a3";
	sortSentence(s);
	return 0;
}

