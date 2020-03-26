/* C프로그래밍 11주차 실습문제 */

#include <stdio.h>

void swap(int *num1, int *num2);

int main()
{
    int n1, n2;
	printf("Input n1: ");
	scanf("%d", &n1); //n1 입력
	printf("Input n2: ");
	scanf("%d", &n2); //n2 입력

	swap(&n1,&n2); // swap 함수 호출, 입력값은 n1과 n2의 주소값
	
	printf("--- swap 함수 실행 ---\n");
	printf("Output n1: %d\n", n1);
	printf("Output n2: %d\n", n2);

	return 0;
}

void swap(int *num1, int *num2)
{
	int point1=*num1;//포인트1의 값은 num1의 주소값
	int point2=*num2;//포인트2의 값은 num2의 주소값

	*num1=point2; //num1의 주소값은 포인트2의 값
	*num2=point1; //num2의 주소값은 포인트1의 값
}