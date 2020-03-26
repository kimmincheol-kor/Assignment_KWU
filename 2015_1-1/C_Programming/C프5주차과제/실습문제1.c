/* C 프로그래밍
    5주차 실습 */

#include <stdio.h>

int main(void) //main 함수 
{
	int min;
	int chul;
	double jjang; //민철짱 선언및초기화

	printf("첫 번째 정수 입력 : ");
	scanf("%d", &min); // 민 에 입력
	printf("두 번째 정수 입력 : ");
	scanf("%d", &chul); // 철 에 입력

	jjang=(double)min/(double)chul; // 짱은 실수형 나눗셈이므로 더블로 선언했다
	
	printf("%d / %d 의 정수형 나눗셈 결과 : 몫 %d, 나머지 %d\n", min, chul, min/chul, min%chul);
	printf("%d / %d 의 실수형 나눗셈 결과 : %.6f", min, chul, jjang); // 민철은 정수, 짱은 소수 6번째자리 까지 출력

	return 0;// 이건 도움 하나도안받음.
}