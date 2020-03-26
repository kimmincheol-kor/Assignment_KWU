/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	double rad;
	double area;
	double pie=3.14; // 8바이트크기의 실수값을 출력하는 더블
	
	printf("원의 반지름을 입력하세요 : ");
	scanf("%lf", &rad); // 반지름을 입력, %lf는 10진수 방식의 부동소수점 실수.

	area=rad*rad*pie; // 원의넓이 area=반지름제곱*3.14
	printf("원의 넓이는 %.2f입니다\n",area); // 최종값 %.2f 는 소수점 둘째자리 까지만 표시함을 의미

	return 0;
}