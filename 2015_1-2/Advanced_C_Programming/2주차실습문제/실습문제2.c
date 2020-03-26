// C 프로그래밍 2주차 실습문제2

#include <stdio.h>

void main()
{
	int i=10;
	int *p=&i; // p 는 i의 주소를 가리킨다

	printf("연산 전: %d\n", *p); // p가 가리키는 주소값 출력
	(*p)++; // *p++ 를 하면 포인터연산이 되어 다음 주소의 값(이상한값)을 출력
	printf("연산 후: %d\n", *p);

}
