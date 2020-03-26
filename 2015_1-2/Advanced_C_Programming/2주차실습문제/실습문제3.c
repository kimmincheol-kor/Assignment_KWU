// C 프로그래밍 2주차 실습문제3

#include <stdio.h>

void main()
{
	char str[32];
	char *p; // char 형식의 포인터 선언

	printf("입력: ");
	gets(str); // str배열에 문장입력

	printf("결과: ");
	
	p = str; // p는 str배열을 가리킨다. 배열의 첫번째 주소를 가리킴.
	printf("%s", p); // p가 가리키는 주소(배열의 첫글자)부터 null값이 들어있는 주소(빈 주소)까지의 값들을 출력

	printf("\n");
}