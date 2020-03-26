// ���C�� 11���� �ǽ�����4

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

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
	free(pNew);

	printf("NULL\n");
}