#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

Node *pHead=NULL;

void Push()
{
	Node *pNew;
	Node *pWork=pHead;

	pNew=(Node *)malloc(sizeof(Node));

	printf("���� �Է�: ");
	scanf("%d", &pNew->num);

	if(pHead==NULL) // ù ���� ����.
	{
		pHead=pNew;
		pNew->next=NULL;
	}
	else // �ι�° ���Ժ��� ����
	{
		pWork=pHead;

		pHead=pNew; // �Ǿ��� ���ο� ����.
		pNew->next=pWork; // ���ο� ������ ������ ���� pHead
		
		while(1)
		{
			if(pWork->next == NULL) // NULL�� �ٷ� �� ���� ã��
			{
				break;
			}
			else
				pWork=pWork->next; // pWork�� next�� NULL�� �ƴ϶�� pWork�� pWork�� ������ ����Ŵ
		}

		pWork->next=NULL; // pWork => NULL
	}
}

Node *Pop()
{
	Node *pPop=pHead;
	Node *pPrev=NULL; // �ʿ����

	if(pPop==NULL)
		return NULL;
	else
	{
		pHead=pPop->next; // pPop => pHead
		return pPop; // pPop�� �����Ͽ� pPop ����
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
	printf("NULL\n\n");
}

void free_linkedlist()
{
	Node *pTemp;

	while(pHead != NULL)
	{
		pTemp=pHead;
		pHead=pHead->next;

		free(pTemp);
	} // �Ǿ��� �� ����
}

void main()
{
	int n;
	Node *pTemp;

	while(1)
	{
		puts("1. PUSH\n2. POP");
		printf("�Է�(����: -1): ");
		scanf("%d", &n);

		if(n==1) Push();
		else if (n==2)
		{
			if((pTemp=Pop())==NULL) // pTemp=Pop()�� ��ȯ���� ���ÿ� pTemp==NULL �̸� ����.
			{
				puts("��尡 �����ϴ�.\n");
				continue;
			}
			printf("%d�� �������ϴ�!\n", pTemp->num); // �Ǿ��� �� : pTemp
			free(pTemp);
		}
		else if (n == -1) break;
		else
		{
			puts("�߸��� �Է��Դϴ�.\n");
			continue;
		}
		Print();
	}
	free_linkedlist();
}
