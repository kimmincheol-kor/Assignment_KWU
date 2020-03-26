/* C 프로그래밍
    5주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int year;
	int ronaldo; // 년 이랑 호날두 선언및 초기화

    printf("연도를 입력하세요 : ");
	scanf("%d", &year); // 년 입력
	
	ronaldo=((year%4)==0&&(year%100)!=0)||(year%400==0); // 호날두는 4로 나눈나머지가 0 이고, 100으로 나눈나머지가 0이 아니거나 , 400으로 나눈 나머지가 0일때 1로 출력된다

	printf("%d년의 윤년 여부 : %d\n", year, ronaldo); 
	printf("<윤년이면 1, 아니면 0>\n");

	return 0; // 호날두 계산하면서 저희과 09학번 이동준 선배님께 배웠습니다.
}