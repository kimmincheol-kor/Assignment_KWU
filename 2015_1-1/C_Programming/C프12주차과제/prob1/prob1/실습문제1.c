// C프로그래밍 12주차 실습문제

#include <stdio.h>

void gopagi(int *num) // 곱하기 함수에는 주소값이 입력됨 배열안의 값을 완전히 바꾸기위해서
{
	int *point=num; // point의 주소값은 num

	*point*=2; // 들어온값의 주소에 들어있는 변수에 x2
}

int main()
{
	int five[5];
	int i,k,j;
	int size=sizeof(five)/sizeof(int);

	printf(">> 다섯 개의 정수 입력: ");
	for(i=0; i<size; i++) // five 배열에 5가지 숫자 입력
	{
		scanf("%d", &five[i]);
	}

	for(k=0; k<size; k++) 
	{
		gopagi(&five[k]); //five 배열의 모든 주소값을 곱하기 함수에 입력
	}

	printf(">> 결과<x2>: ");

	for(j=0; j<size; j++)
	{
		printf("%d ", five[j]); // five 배열의 모든값 다시 출력
	}

	printf("\n");

	return 0;
}