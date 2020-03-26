// 고급C프 11주차 실습문제5

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
		printf("양의 정수를 입력하세요(종료: -1): ");
		scanf("%d", &n);

		if( n == -1) break;

		pNew=(Node *)malloc(sizeof(Node)); // 메모리 할당
		pNew->num=n; // n값 입력
		pNew->next=pHead; // pNew의 next는 pHead
		pHead=pNew; // pHead 는 pNew 이다
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

	while(node!=NULL) // 하나씩 삭제
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