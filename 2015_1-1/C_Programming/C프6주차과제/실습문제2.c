/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int kim;
	int park;
	int lee=1; // 곱셈에서 0 이 되는걸 방지하기위해 1부터 시작

	printf("Input : ");
	scanf("%d", &kim);

	for(park=1; kim>=park; park++) // 박을 1로 초기화시키고; 박이 김보다 작거나 같으면 명령문 실행; 명령문이 끝난후 박에 1을 더해줌
	{
		lee*=park; //(기존)리X박 = (새로운)리 => 1x2x3x.......xN = N!
    }
	
	printf("%d! = %d\n", kim, lee); // 여기서 lee 는 계속곱해진 최종값

	return 0;
}