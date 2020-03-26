/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	char ch1='A';
	char ch2='Z';
	char ch3='a';
	char ch4='z'; // 문자로 선언
	
	printf("A부터 Z까지의 아스키 코드 값 : %d ~ %d\n", ch1, ch2); // %c로 출력하면 문자로, %d로 출력하면 문자가 정수로 출력된다
	printf("a부터 z까지의 아스키 코드 값 : %d ~ %d\n", ch3, ch4); // 마찬가지

	return 0;

}