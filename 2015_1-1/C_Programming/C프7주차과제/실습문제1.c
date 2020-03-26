/* C 프로그래밍
   7주차 실습 */

#include <stdio.h>

int main(void)
{
	char one;

	printf("알파벳 입력: ");
	scanf("%c", &one); //one 값 입력

	if(one<='Z'&&one>='A') // one의 크기가 A보다크고 Z보다작다면 = one이 대문자라면 실행
	    {one+=' '; // 공백은 아스키코드표에서 32 에 해당
	     printf("대소문자 변경 : %c \n", one);}
	else // one이 대문자가 아니라면
		if(one>='a'&&one<='z') // one이 소문자 라면 실행
			{one-=' ';
	         printf("대소문자 변경 : %c \n", one);}
		else // one이 소문자가 아니라면 실행 = 대문자도 아니고, 소문자도 아니다 = 알파벳이 아니다
			printf("대소문자 변경 : 알파벳이 아닙니다\n");

     return 0;
}