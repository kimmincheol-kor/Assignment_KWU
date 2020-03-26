/* C 프로그래밍
   7주차 실습 */

#include <stdio.h>

int main(void)
{
	int one;
	int two;
	int three;
	
	int min;
	int min2; //중간 계산용 선언
	
	printf("세 개의 정수 입력 : ");
	scanf("%d %d %d", &one, &two, &three);

	min=one>two ? two : one; // min 은 원과 투중에 작은 값.
	min2=min>three ? three : min; // min2 는 쓰리와 min 중에 작은값 = 제일 작은값

	printf("가장 작은 값 : %d\n", min2); // min2 출력

	return 0;
}