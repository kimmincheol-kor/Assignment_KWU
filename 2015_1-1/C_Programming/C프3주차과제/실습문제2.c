/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num1=0x7B, num2=0xFF, num3=052, num4=037; //0x로 시작하면 16진수, 0으로 시작하면 8진수
	
	
	printf("16진수 7B의 10진수 정수 값 : %d\n", num1); //0x7B를 프린트
	printf("16진수 FF의 10진수 정수 값 : %d\n", num2); //0xFF
	printf("8진수 52의 10진수 정수 값 : %d\n", num3); //052
	printf("8진수 37의 10진수 정수 값 : %d\n", num4); //037

	return 0;
}