/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num;
	
    printf("2의 보수로 부호 바꾸기\n");
	printf("입력 : ");
	scanf("%d", &num); // num에 숫자입력.

	num=~num; //num을 ~연산
	num=num+1; // ~연산된 num에 +1
	
	printf("결과 : %d\n", num); // 결과 프린트

	return 0;
}