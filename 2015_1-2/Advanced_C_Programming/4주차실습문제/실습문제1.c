// C 프로그래밍 4주차 실습문제1

#include <stdio.h>

void main()
{
	int num=5;
	int *pNum;
	int **dpNum;

	pNum=&num; // pNum은 num의 주소값을 가리킨다.
	dpNum=&pNum; // dpNum은 pNum의 주소값을 가리킨다.
	       
	printf("num addr: %p\n", *dpNum);
	printf("pNum addr: %p\n", dpNum);
	printf("dpNum addr: %p\n", &dpNum);
	printf("num: %d\n", **dpNum);

	printf("num addr: %p\n", &num);
	printf("pNum addr: %p\n", &pNum);
	printf("dpNum addr: %p\n", &dpNum);
}