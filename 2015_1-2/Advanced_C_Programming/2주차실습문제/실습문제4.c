// C프로그래밍 2주차 실습문제4

#include <stdio.h>

void main()
{
	int n1=10, n2=20, n3;
	int *p;

	printf("n1: %d\n", n1);
	printf("n2: %d\n", n2);
	
	p=&n3; // p가 n3의 주소를 가리킴
	*p=n1+n2; // p가 가리키는 주소의 값(n3의 값)에 n1+n2를 입력
	
	printf("n1+n2: %d\n", n3); // n3 출력
}