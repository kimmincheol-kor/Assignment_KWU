/* C 프로그래밍
    2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num1, num2; //넘버1과 넘버2의 선언
	int result1;

	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &num1, &num2);// 넘버1 넘버2 입력

	result1=(num1==num2); //result 지정
    printf("결과 : %d\n", result1);

	return 0;
}