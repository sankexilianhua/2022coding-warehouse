#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * removeOuterParentheses(char * s)
{
	int len = strlen(s);
	char* ans = (char*)calloc(len, sizeof(char));
	char stack[100];
	memset(stack, 0, sizeof(stack));
	int top = -1;
	int size = 0;
	int count = 1;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '(')
			stack[++top] = s[i];
		else if (s[i] == ')')
		{
			if (top != 0)
			{
				ans[size++] = stack[top];
				stack[top--] = 0;
				//ans[size++]=')';
				if (s[i + 1] == ')'&&count != top + 1)
					count++;
				else
				{
					while (count--)
					{
						ans[size++] = ')';
					}
					count = 1;
				}
			}
			else
			{
				stack[top--] = 0;
			}
		}
	}
	while (count--)
	{
		ans[size++] = ')';
	}
	count = 1;
	return ans;
}
int main()
{
	char s[] = "(((((())))))";
	removeOuterParentheses(s);
	return 0;
}