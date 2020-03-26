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

	printf("정수 입력: ");
	scanf("%d", &pNew->num);

	if(pHead==NULL) // 첫 숫자 삽입.
	{
		pHead=pNew;
		pNew->next=NULL;
	}
	else // 두번째 삽입부터 적용
	{
		pWork=pHead;

		pHead=pNew; // 맨앞은 새로운 숫자.
		pNew->next=pWork; // 새로운 숫자의 다음은 기존 pHead
		
		while(1)
		{
			if(pWork->next == NULL) // NULL의 바로 앞 숫자 찾기
			{
				break;
			}
			else
				pWork=pWork->next; // pWork의 next가 NULL이 아니라면 pWork는 pWork의 다음을 가리킴
		}

		pWork->next=NULL; // pWork => NULL
	}
}

Node *Pop()
{
	Node *pPop=pHead;
	Node *pPrev=NULL; // 필요없음

	if(pPop==NULL)
		return NULL;
	else
	{
		pHead=pPop->next; // pPop => pHead
		return pPop; // pPop을 리턴하여 pPop 삭제
	}
}

void Print()
{
	Node *pWork=pHead; // pWork는 첫번째를 가리킴

	while(pWork != NULL) // NULL이 아니면 반복
	{
		printf("%d -> ", pWork->num);
		pWork=pWork->next; // 다음것을 가리킴
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
	} // 맨앞의 수 제거
}

void main()
{
	int n;
	Node *pTemp;

	while(1)
	{
		puts("1. PUSH\n2. POP");
		printf("입력(종료: -1): ");
		scanf("%d", &n);

		if(n==1) Push();
		else if (n==2)
		{
			if((pTemp=Pop())==NULL) // pTemp=Pop()의 반환값인 동시에 pTemp==NULL 이면 실행.
			{
				puts("노드가 없습니다.\n");
				continue;
			}
			printf("%d가 빠졌습니다!\n", pTemp->num); // 맨앞의 수 : pTemp
			free(pTemp);
		}
		else if (n == -1) break;
		else
		{
			puts("잘못된 입력입니다.\n");
			continue;
		}
		Print();
	}
	free_linkedlist();
}
