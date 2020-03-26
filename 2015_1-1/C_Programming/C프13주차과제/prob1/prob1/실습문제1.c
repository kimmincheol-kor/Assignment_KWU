// C 프로그래밍 13주차 실습문제

#include <stdio.h>

void get_array(int *arr, int i);
void prt_array(int *arr, int i); 


int main()
{
	int a[5];

	get_array(a, 5); //get배열함수 호출
	prt_array(a, 5); //prt배열함수 호출

	return 0;
}

void get_array(int *arr, int i) // 배열값을 받는 함수 get
{
	int j;
	printf("Enter 5 values, after each value press enter\n");
	
	for(j=0; j<i; j++)
	{
		scanf("%d", &arr[j]); // 배열값 입력
	}
}

void prt_array(int *arr, int i) // 배열값의 주소값을 받음
{
	int k;
	printf("Printing all values\n");
	
	for(k=0; k<i; k++)
	{
		printf("%d\n", arr[k]); // 배열값 출력
	}
}