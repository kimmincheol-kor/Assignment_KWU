// C 프로그래밍 2주차 실습문제1

#include <stdio.h>

void main()
{
	int i=10;
	int *p;
	p=&i; // p가 가리키는 것 = i 의 주소

	printf("i의 주소: %d\n", &i);
	printf("i의 값: %d\n", i);
	printf("p가 가리키는 주소: %d\n", p);
	printf("*p의 값: %d\n", *p);
}