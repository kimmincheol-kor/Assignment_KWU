// 고급C프 6주차 실습문제1

#include <stdio.h>

int sum(int a, int b){
	return a+b;
}

void main()
{
	int a=10, b=20;

	int(*fptr)(int,int)=sum; // fptr 은 sum 함수를 가리킴
	printf("%d + %d = %d\n", a, b, fptr(a,b));
}