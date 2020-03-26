/* C 프로그래밍
   2주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int num1, num2; // num1과 num2에 메모리 할당

	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &num1, &num2); //num1과 num2에 숫자입력

	printf("두 수의 AND 연산 결과 : %d\n", num1&num2); //AND 연산 &
	printf("두 수의 OR 연산 결과 : %d\n", num1|num2); // OR 연산 |
	printf("두 수의 XOR 연산 결과 : %d\n", num1^num2); // XOR 연산 ^

	return 0;
}