/* C 프로그래밍
    2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num;
	int num2=1100;// 1달러=1100원으로 입력
	

	printf("달러화 금액 입력 : ");
	scanf("%d", &num); // num의 숫자를 지정해줌

	
	printf("달러화 %d달러는 %d원입니다.", num, num*num2); //입력한 num 에 환율 1100원을 곱해줌

	return 0;
}