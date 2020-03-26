// C 프로그래밍 13주차 실습문제

#include <stdio.h>

void ShowOddOrEven(int *arr, int a, int b); // 짝수인지홀수인지 구분하는 함수

int main()
{
	int arr[10];
	int i;

	printf("총 10개의 정수 입력\n");
	for(i=0; i<10; i++)
	{
		printf("입력: ");
		scanf("%d", &arr[i]);
	} // arr 배열에 정수 10개 입력

	printf("홀수 출력: ");
	ShowOddOrEven(arr, 10, 1); // 배열입력, 크기입력, 홀수는 1 입력

	printf("\n");

	printf("짝수 출력: ");
	ShowOddOrEven(arr, 10, 0); // 짝수는 마지막에 0 입력

	printf("\n");

	return 0;
}

void ShowOddOrEven(int *arr, int size, int flag)
{
	int i,j,k;
	if(flag==1){ // flag값이 1이라면 = 홀수를 출력
	for(i=0; i<size; i++)
	{
		if(arr[i]%2==1) // 2로나눈 나머지가 1 = 홀수
			printf("%d, ", arr[i]);
	}
	}

	if(flag==0){ // flag값이 0이면 = 짝수를 출력
	for(i=0; i<size; i++)
	{
		if(arr[i]%2==0) // 2로나누어떨어짐.
			printf("%d, ", arr[i]);
	}
	}

}