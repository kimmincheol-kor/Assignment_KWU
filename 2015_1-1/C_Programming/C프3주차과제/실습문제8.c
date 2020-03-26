/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int x=7;
	int y=10;

	printf("%d\n%d\n%d\n%d\n%d\n%d\n", x>>2, y>>2, x>>1, (y>>2)<<1, y>>1, (x>>1)<<1);

	/* 7=0111 10=1010
	  1=0001 2=0010 3=0011 4=0100 5=0101 6=0110
	                   */



	return 0;
}