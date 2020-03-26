// C 프로그래밍 1주차 실습문제1

#include <stdio.h>

int main()
{
	int num;

	while(1) // -1이 입력될때까지 반복.
	{
	printf("입력<종료:-1>: ");
	scanf("%d", &num);

	if(num>0){ // 양수만 받음
	if(num%2==0)
		printf("짝수입니다.\n");
	else
		printf("홀수입니다.\n");}
	else if(num==-1) // -1 을 받으면 종료
		break;
	else // 양수도 -1 도 아닌 수를 입력 받으면 재입력.
		printf("다시 입력하세요.\n");
	}
}