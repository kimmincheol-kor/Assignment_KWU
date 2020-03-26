// C 프로그래밍 4주차 실습문제4

#include <stdio.h>

void swap(int ***dpA, int ***dpB);

void main()
{
	int a,b;
	int *pA, *pB;
	int **dpA, **dpB;

	pA=&a;
	pB=&b;
	dpA=&pA;
	dpB=&pB;

	// dpA -> pA -> a
	// pA는 a의 주소를 가리키고, *pA 는 그 주소의 값이다.
	// *dpA 는 pA의 주소이고, **dpA는 pA의 값이다.

	printf("입력: ");
	scanf("%d %d", *dpA, *dpB); // *dpA 는 pA의 주소이고 pA는 a를 가리킨다.

	swap(&dpA, &dpB); // pA와 pB의 주소값을 함수에 대입
	
	printf("swap: %d %d\n", **dpA, **dpB); // a 와 b 의 값을 출력
}

void swap(int * **tpA, int ***tpB)
{
	int *temp=**tpA; // temp의 값은 dpA의 값

	**tpA=**tpB;
	**tpB=temp; // 서로의 값을 바꿔줌.
}