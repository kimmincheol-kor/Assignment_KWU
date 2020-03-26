// ���C�� 11���� �ǽ�����5

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

void free_linkedlist(Node *node);

void main()
{
	Node *pHead=NULL;
	Node *pNew=NULL;
	Node *pWork=NULL;
	int n=0;

	while(1)
	{
		printf("���� ������ �Է��ϼ���(����: -1): ");
		scanf("%d", &n);

		if( n == -1) break;

		pNew=(Node *)malloc(sizeof(Node)); // �޸� �Ҵ�
		pNew->num=n; // n�� �Է�
		pNew->next=pHead; // pNew�� next�� pHead
		pHead=pNew; // pHead �� pNew �̴�
	}
	pWork=pHead;

	while(pWork!=NULL)
	{
		printf("%d->", pWork->num);
		pWork=pWork->next;
	}
	printf("NULL\n");

	free_linkedlist(pHead);
}

void free_linkedlist(Node *node)
{
	Node *pTemp;

	while(node!=NULL) // �ϳ��� ����
	{
		node=node->next;
		pTemp=node;
		while(pTemp!=NULL)
		{
			printf("%d->", pTemp->num);
			pTemp=pTemp->next;
		}
		printf("NULL\n");
	}
}