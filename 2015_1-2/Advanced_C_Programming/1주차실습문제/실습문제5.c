// C프로그래밍 1주차 실습문제5

#include <stdio.h>

void swap(int *a, int *b); //swap 함수의 선언

int main()
{
	int a,b;

	printf("입력: ");
	scanf("%d %d", &a, &b); // a b 입력

	swap(&a, &b); // 스왑 실행.

	printf("swap 결과: %d %d \n", a, b); // a b 출력
}

void swap(int *a, int *b)
{
	int temp;
	temp=*a; 

	*a=*b;
	*b=temp;
}