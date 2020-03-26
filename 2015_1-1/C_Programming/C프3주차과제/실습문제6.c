/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int x=0x1011;
	int y=0x0110;

	printf("%04x\n", (x|y)^x); // x랑 연산해서 0100 을 나오게 1111 을만들자. %04x : 4자리의 16진수로 출력.
	printf("%04x\n", (x|y)^y); // y랑 연산해서 1001 이 나오게 1111 을 만들자.

	return 0;
}