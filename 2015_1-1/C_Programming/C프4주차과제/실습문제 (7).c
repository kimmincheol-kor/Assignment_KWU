/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int h,m,s;
	int x;
	
	printf("입력 : ");
	scanf("%d",&x); // x값 입력
	
	h = x/3600; // 1시간=3600초이므로 나눔
	m = x%3600/60; // 3600으로나눈 나머지를 60으로나눔
	s = x%3600%60; // 3600으로나눈 나머지를 60으로 또 나누고 남은값

	printf("%d초는 %d시간 %d분 %d초이다\n", x, h, m, s);// x초= h시간 m분 s초

	return 0;
}