#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	char a[10][30], (*p1)[30], (*p2)[30],mid[30];
	int i, j;
	printf("请输入十个姓名");
	for (i = 0; i<10; i++)
		gets(a[i]);
	for (int i = 0; i < 10; i++)
	{
		p1 = a[i];
		for (int j = i + 1; j < 10; j++)
		{
			p2 = a[j];
			int res = strcmp(p1, p2);
			if (res >= 0)
			{
				strcpy(mid, p1);
				strcpy(p1,p2);
				strcpy(p2, mid);
			}
			else
			{
				strcpy(mid, p2);
				strcpy(p2, p1);
				strcpy(p1, mid);
			}
		}
	}
	for (i = 0; i<10; i++)
	{
		puts(a[i]);
	}
	return 0;
}