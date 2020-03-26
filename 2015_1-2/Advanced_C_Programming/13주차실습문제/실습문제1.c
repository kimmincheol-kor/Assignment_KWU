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

	if(pHead==NULL) // 첫 숫자 삽입.
	{
		pHead=pNew;
		pNew->next=NULL;
	}
	else // 두번째 삽입부터 적용
	{
		pWork=pHead;
		
		while(1)
		{
			if(pWork->next == NULL) // NULL의 바로 앞 숫자 찾기
			{
				break;
			}
			else
				pWork=pWork->next; // pWork의 next가 NULL이 아니라면 pWork는 pWork의 다음을 가리킴
		}

		pWork->next=pNew;
		pNew->next=NULL;
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

	printf("써리원!\n");
	
	while(pHead != NULL) // 메모리 해제
	{
		pWork=pHead; // pHead를 가리킴
		pHead=pHead->next; // pHead의 위치 변경
		free(pWork); // pWork 초기화
	}
}

void main()
{
	int n, cnt=0;

	puts("베스킨라빈스31");
	puts("===============");

	while(1)
	{
		printf("<현재: %d> 입력<1~3>: ", cnt);
		scanf("%d", &n);

		// 예외 처리
		if(n>3 || n<1) // 1~3 입력
			printf("잘못된 입력입니다.\n\n");
		else if((cnt!=30) && ((cnt+n)>=31)) // 30이 아닌 수 에서 바로 31이 되지못하도록
			printf("잘못된 입력입니다.\n\n");
		else if((cnt+n)>31) // 31보다 크면 안됨
			printf("잘못된 입력입니다.\n\n");
		else if((cnt==30)&&(n==1)) // 30에서 숫자 1을 입력하면 종료
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
	Print(); // 출력
}