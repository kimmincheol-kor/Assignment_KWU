#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

Node *pHead=NULL;

void Push(int n)
{
	Node *pWork = pHead;
	Node *pNew;

	pNew=(Node *)malloc(sizeof(Node));
	pNew->num=n;

	if(pHead==NULL) // ù ���� ����.
	{
		pHead=pNew;
		pNew->next=NULL;
	}
	else // �ι�° ���Ժ��� ����
	{
		pWork=pHead;
		
		while(1)
		{
			if(pWork->next == NULL) // NULL�� �ٷ� �� ���� ã��
			{
				break;
			}
			else
				pWork=pWork->next; // pWork�� next�� NULL�� �ƴ϶�� pWork�� pWork�� ������ ����Ŵ
		}

		pWork->next=pNew;
		pNew->next=NULL;
	}
}

void Print()
{
	Node *pWork=pHead; // pWork�� ù��°�� ����Ŵ

	while(pWork != NULL) // NULL�� �ƴϸ� �ݺ�
	{
		printf("%d -> ", pWork->num);
		pWork=pWork->next; // �������� ����Ŵ
	}

	printf("�Ḯ��!\n");
	
	while(pHead != NULL) // �޸� ����
	{
		pWork=pHead; // pHead�� ����Ŵ
		pHead=pHead->next; // pHead�� ��ġ ����
		free(pWork); // pWork �ʱ�ȭ
	}
}

void main()
{
	int n, cnt=0;

	puts("����Ų���31");
	puts("===============");

	while(1)
	{
		printf("<����: %d> �Է�<1~3>: ", cnt);
		scanf("%d", &n);

		// ���� ó��
		if(n>3 || n<1) // 1~3 �Է�
			printf("�߸��� �Է��Դϴ�.\n\n");
		else if((cnt!=30) && ((cnt+n)>=31)) // 30�� �ƴ� �� ���� �ٷ� 31�� �������ϵ���
			printf("�߸��� �Է��Դϴ�.\n\n");
		else if((cnt+n)>31) // 31���� ũ�� �ȵ�
			printf("�߸��� �Է��Դϴ�.\n\n");
		else if((cnt==30)&&(n==1)) // 30���� ���� 1�� �Է��ϸ� ����
		{
			Push(n); 
			printf("31!!!!!\n");
			break;
		}
		else
		{
			Push(n);
			cnt+=n;
		}
	}
	Print(); // ���
}