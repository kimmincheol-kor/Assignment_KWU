/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void)
{
    int x=1;
	int y=3;
	

	printf("%d 곱하기 %d은 %d입니다.\n", ++x, y++, x+y); // x는 2가되서 출력되고 y는 3으로 출력된후 4가된다
	printf("%d 빼기 %d는 %d입니다.\n\n", ++y, x++, x); // y는 5가되서 출력되고 x는 2로 출력되고 3이된다

	return 0;
}