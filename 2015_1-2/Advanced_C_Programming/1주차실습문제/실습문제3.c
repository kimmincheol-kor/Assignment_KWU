// C 프로그래밍 1주차 실습문제3

#include <stdio.h>

int factorial(int n); // 팩토리얼 함수 선언

int main()
{
	int num;
	while(1){

	printf("입력: ");
	scanf("%d", &num); // 숫자 입력받음
	
	
	if(num>0) // 양수를 입력받으면,
		{printf("%d!: %d\n",num ,factorial(num)); // 팩토리얼함수에 num 입력
		break;}
	else
		printf("다시 입력하세요.\n");
	}


}

int factorial(int n)
{
	if(n<=1)
		return 1; // 입력받은수가 1이거나 작으면 반환값은 1
	else
		return n*factorial(n-1); // 재귀함수!!
}