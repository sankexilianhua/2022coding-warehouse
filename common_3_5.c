#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//struct list
//{
//	int num;
//	struct list* next;
//};
//int main()
//{
//	int t = 0;
//	scanf("%d", &t);
//	while (t--)
//	{
//		struct list*head=NULL, *p1=NULL, *p2=NULL;
//		int n;
//		scanf("%d", &n);
//		int i = 1;
//		//��������(������)
//		for (i = 1; i <= n; i++)
//		{
//			if (i == 1)
//			{
//				p1 = p2 = head = (struct list*)malloc(sizeof(struct list));
//				head->num = i;
//			}
//			else
//			{
//				p1 = (struct list*)malloc(sizeof(struct list));
//				p2->next = p1;
//				p2 = p1;
//				p1->num = i;
//			}
//		}
//		p1->next = NULL;
//		//���������ݵĴ���
//		while (n >= 3)
//		{
//			p2 = head;
//			p1 = head;
//			int count = 0;
//			//Ѱ��Ҫ�޳�2�Ľڵ�
//			while (p1->next != NULL)
//			{
//				count++;
//				if (count % 2 == 0)
//				{
//					//���ýڵ��޳�
//					n--;
//					p2->next = p1->next;
//					p1 = p1->next;
//					if (p1->next == NULL)
//						break;
//					count++;
//					p2 = p1;
//					p1 = p1->next;
//
//				}
//				else
//				{
//					p2 = p1;
//					p1 = p1->next;
//				}
//			}
//			count++;
//			//�ж����һ�����ǲ���2�ı���
//			if (count % 2 == 0)
//			{
//				p2->next = NULL;
//				n--;
//			}
//			//2���ж�������
//			//�ж�һ��n�Ƿ��Ѿ�С��3��
//			if (n <= 3)
//			{
//				break;
//			}
//			//count��0
//			count = 0;
//			p2 = head;
//			p1 = head;
//			//����Ҫ�޳�3�Ľڵ�
//			while (p1->next != NULL)
//			{
//				count++;
//				if (count % 3 == 0)
//				{
//					//���ýڵ��޳�
//					n--;
//					p2->next = p1->next;
//					p1 = p1->next;
//					if (p1->next == NULL)
//						break;
//					count++;
//					p2 = p1;
//					p1 = p1->next;
//
//				}
//				else
//				{
//					p2 = p1;
//					p1 = p1->next;
//				}
//			}
//			//�ж�һ�����һ�����ǲ���3�ı���
//			//printf("%d\n",p2->num);
//			count++;
//			if (count % 3 == 0)
//			{
//				p2->next = NULL;
//				n--;
//			}
//			//             p1=p2=head;
//		}
//		//��ѭ�����ӡ
//		p1 = head;
//		while (p1->next != NULL)
//		{
//			printf("%d ", p1->num);
//			p1 = p1->next;
//		}
//		printf("%d\n", p1->num);
//	}
//	return 0;
//}


//#include<stdio.h>
//int cmp(const void*e1, const void*e2)
//{
//	if (*(int*)e1>*(int*)e2)
//		return 1;
//	else if (*(int*)e1 == *(int*)e2)
//		return 0;
//	else
//		return -1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[10];
//	for (i = 0; i<n; i++)
//		scanf("%d", &arr[i]);
//	qsort(arr, n, sizeof(int), cmp);
//	int count = 0;
//	int flag = 0;
//	for (i = 0; i<n - 1; i++)
//	{
//		if (arr[i + 1] - arr[i]>1)
//		{
//			continue;
//			flag++;
//		}
//		else
//		{
//			count++;
//		}
//	}
//	if (arr[n - 1] - arr[n - 2] <= 1)
//		count++;
//	if (flag == n - 2 && arr[n - 1] - arr[n - 2]>1)
//		count = 1;
//	if (n == 1)
//		count = 1;
//	printf("%d", count);
//	return 0;
//}

//#include<stdio.h>
//#include<stdbool.h>
//#include<stdlib.h>
//int cmp(const void*e1, const void*e2)
//{
//	if (*(int*)e1>*(int*)e2)
//		return 1;
//	else if (*(int*)e1 == *(int*)e2)
//		return 0;
//	else
//		return -1;
//}
//int judge(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i<n; i++)
//	{
//		if (arr[i] != 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[2];
//	for (i = 0; i<n; i++)
//		scanf("%d", &arr[i]);
//	qsort(arr, n, sizeof(int), cmp);
//	int count = 0;
//	while (judge(arr, n))
//	{
//		for (i = 0; i<n; i++)
//		{
//			if (arr[i] == 0)
//				continue;
//			int j = 0;
//			for (j = 0; j<n; j++)
//			{
//				if (arr[j] == 0)
//					continue;
//				if (arr[j] - arr[i]>1)
//				{
//					arr[i] = 0;
//					i = j;
//				}
//			}
//			count++;
//			i = 0;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i = 0;
	int arr[n];
	for (i = 0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int j = 0;
	for (j = 1; j<n - 1; j++)
	{
		if (arr[j] == 0)
			break;
	}
	for (i = 0; i<n; i++)
	{
		if (arr[0] == 0)
			continue;
		else
		{
			if (arr[0] == 0)
			{
				if (arr[i] >= i)
					arr[i] = i;
				else
				{
					break;
				}
			}
			else
			{
				if (i == 0)
					continue;
				else
				{
					if (arr[i] >= i)
						arr[i] = i;
					else
						break;
				}
			}
		}
	}
	if (n<2 * i&&j == n - 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}