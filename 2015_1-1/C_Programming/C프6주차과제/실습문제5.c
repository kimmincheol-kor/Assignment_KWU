/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int home;

    do // do~while문은 실행후 조건확인
	{
		
		printf("Input : ");
		scanf("%d", &home);

	}while(home!=-1); // home이 -1이 아니면 계속해서 반복 = home이 -1이면 종료
	
	return 0;
}