/* C 프로그래밍
	2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int x=5;
	int y=10;
	int z=2000; // x,y,z에 각각 5,10,2000 대입

	printf("%d년은 을미년입니다 \n", x+y+z); // 2015=x+y+z
	
	printf("\n%d더하기 %d은 %d입니다 \n", x, y, x+y); // 15=x+y
	
	printf("\n어린이날은 %d년도에 제정되었습니다 \n", z-y-y-x); //1975=z-y-y-x=2000-25

	return 0;
}