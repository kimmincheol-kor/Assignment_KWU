// 고급C프 11주차 실습문제4

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
	free(pNew);

	printf("NULL\n");
}