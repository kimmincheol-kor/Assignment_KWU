/* C 프로그래밍
    2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num1, num2; // 넘버1 넘버2 선언
	printf("첫 번째 정수 입력 : ");
	scanf("%d", &num1); //넘버1 입력
	printf("두 번째 정수 입력 : ");
	scanf("%D", &num2); //넘버2 입력

	/* 사칙연산 만들기 */
	
	printf("%d + %d = %d\n", num1, num2, num1+num2);
	printf("%d - %d = %d\n", num1, num2, num1-num2);
	printf("%d x %d = %d\n", num1, num2, num1*num2);
	printf("%d / %d = %d\n", num1, num2, num1/num2);

	return 0;
}