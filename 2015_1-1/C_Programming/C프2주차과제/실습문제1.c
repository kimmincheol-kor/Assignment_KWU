/* C 프로그래밍
    2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num1=3, num2=1, num3=2; //변수num1,2,3의 선언 및 초기화
	printf("%d x %d = %d \n", num1, num2, num1*num2); //3x1=3
	printf("%d x %d = %d \n", num1, num3, num1*num3); //3x2=6
	printf("%d x %d = %d \n", num1, num1, num1*num1); //3x3=9

	return 0;
}