/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	char ch1; // 1바이트 크기의 char
	
	printf("알파벳 소문자 입력 : "); 
	scanf("%c",&ch1); // ch1 에 소문자 입력
	
	printf("대문자로 변환 : %c\n",ch1-32); // 소문자를 입력한 ch1에서 32를 빼서 대문자 출력(대소문자 차이 32)

	return 0;
}