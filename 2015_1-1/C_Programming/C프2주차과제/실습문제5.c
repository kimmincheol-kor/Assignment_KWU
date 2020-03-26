/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수이다
{
	int x=5; //x는 5로 대입

	printf("x의 초기값 : %d\n", x); //x는 5이다
	printf("1. x = %d\n", ++x); //x는 6이되어 출력된다.
	printf("2. x = %d\n", x--); //x는 6으로출력 > 5로 된다
	printf("3. x = %d\n", --x); //x는 4로되어 출력된다
	printf("4. x = %d\n", x++); //x는 4로출력되고 5가된다
	printf("5. x = %d\n", x--); //x는 5로 출력되고 4가된다
	printf("x의 현재 값 : %d\n\n", x); //x는 4로 출력된다
	
	return 0;
}