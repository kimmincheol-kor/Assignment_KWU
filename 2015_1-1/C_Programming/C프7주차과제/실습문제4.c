  /* C 프로그래밍
   7주차 실습 */

#include <stdio.h>

int main(void)
{
	int usa;
	int best=0;

    while(1) //break 나올때까지 무한 반복
	{
		printf("양의 정수 입력 : ");
		scanf("%d", &usa); //usa값 입력

		if(usa<0)
			{continue;} // usa가 음수이면 다시 while문 실행
		
		best+=usa; // best = best + usa

		if(usa==0)
			{printf("종료");
		     printf("\n");
				break;} // usa가 0 이면 종료

		printf("누적 합 : %d\n", best);
	}
}