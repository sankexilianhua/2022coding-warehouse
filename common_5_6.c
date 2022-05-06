#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int longestBeautifulSubstring(char * word)
//{
//	//printf("%d %d %d %d %d",'a'-'a','e'-'a','i'-'a','o'-'a','u'-'a');
//	int len = strlen(word);
//	int i = 0, j = 0;
//	int maxlen = 0;
//	int hash[26];
//	memset(hash, 0, sizeof(hash));
//	++hash[word[0] - 'a'];
//	//printf("%c",word[len-1]);
//	while (j<len - 1)
//	{
//		int flag = 1;
//		++j;
//		++hash[word[j] - 'a'];
//		if (word[j] != word[j - 1])
//		{
//			switch (word[j])
//			{
//			case 'a':
//				if (word[j - 1] != 'a')
//					flag = 0;
//				break;
//			case 'e':
//				if (word[j - 1] != 'a')
//					flag = 0;
//				break;
//			case 'i':
//				if (word[j - 1] != 'e')
//					flag = 0;
//				break;
//			case 'o':
//				if (word[j - 1] != 'i')
//					flag = 0;
//				break;
//			case 'u':
//				if (word[j - 1] != 'o')
//					flag = 0;
//				break;
//			}
//		}
//		if (hash[0] && hash[4] && hash[8] && hash[14] && hash[20] && flag)
//			maxlen = j - i + 1;
//		if (flag == 0)
//		{
//			for (int i = 0; i <= j; i++)
//				--hash[word[i] - 'a'];
//		}
//	}
//	return maxlen;
//}

int longestBeautifulSubstring(char * word)
{
	//printf("%d %d %d %d %d",'a'-'a','e'-'a','i'-'a','o'-'a','u'-'a');
	int len = strlen(word);
	int i = 0, j = 0;
	int maxlen = 0;
	int hash[26];
	memset(hash, 0, sizeof(hash));
	++hash[word[0] - 'a'];
	//printf("%c",word[len-1]);
	while (j<len - 1)
	{
		int flag = 1;
		++j;
		++hash[word[j] - 'a'];
		if (word[j] != word[j - 1])
		{
			if (word[j] - word[j - 1]<0)
			{
				flag = 0;
				break;
			}
			// switch(word[j])
			// {
			//     case 'a':
			//     if(word[j-1]!='a')
			//     flag=0;
			//     break;
			//     case 'e':
			//     if(word[j-1]!='a')
			//     flag=0;
			//     break;
			//     case 'i':
			//     if(word[j-1]!='e')
			//     flag=0;
			//     break;
			//     case 'o':
			//     if(word[j-1]!='i')
			//     flag=0;
			//     break;
			//     case 'u':
			//     if(word[j-1]!='o')
			//     flag=0;
			//     break;
			// }
		}
		if (hash[0] && hash[4] && hash[8] && hash[14] && hash[20] && flag)
			maxlen = j - i + 1;
		if (flag == 0)
		{
			for (; i<j; i++)
				--hash[word[i] - 'a'];
		}
	}
	return maxlen;
}
int main()
{
	char s[] ="aeiaaioaaaaeiiiiouuuooaauuaeiu";
	longestBeautifulSubstring(s);
	return 0;
}