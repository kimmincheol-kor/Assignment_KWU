/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int x=2; // 0010
	int y=6; // 0110
	int z=20; // 10100

	printf("%d^%d = %d\n", x, z>>1, x<<9); // z>>1=10 , x<<9=1024
	printf("%d x %d = %d\n", y>>1, z>>2, (y>>1)*(z>>2)); // z>>2=5, y>>1=3
	printf("%d x %d = %d\n", x<<1, z>>1, (x<<1)*(z>>1)); // x<<1=4, z>>1=10

	return 0;
}