// C 프로그래밍 13주차 실습문제

#include <stdio.h>

void reverse(int *arr);
void swap(int *n1, int *n2);

int main()
{
	int arr[10];
	int i=0;

	printf("10개의 정수 입력\n>> ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
	} // 10개의 정수를 입력받음
	
	reverse(arr); // 리버스함수에서 저장된 정수의 순서를 뒤바꿈

	printf(">> ");
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}

void reverse(int *arr) // 배열의 주소값 입력
{
	int i;

	for(i=0; i<5; i++)
	{
		swap(&arr[i], &arr[9-i]); // 첫번째와 마지막, 두번째와 뒤에서 두번째, 이렇게 바꿔줌. 5번 반복이면 다바뀜
	}
}

void swap(int *n1, int *n2) // swap 함수 = 두 수의 값을 서로 바꿔줌
{
	int temp=*n1;

	*n1=*n2;
	*n2=temp;
}