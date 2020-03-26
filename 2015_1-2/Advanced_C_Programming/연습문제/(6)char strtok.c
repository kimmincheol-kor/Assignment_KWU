// 문자열을 문자로 자르기

#include <stdio.h>
#include <string.h>

int main()
{
	char *tok;
	char str[]="you are good boy";

	tok=strtok(str, " "); // str을 " "을 기준으로

	while(tok)
	{
		printf("%s\n", tok);
		tok=strtok(NULL, " "); // 이전의 기억된 곳부터. " " 를 기준으로
	}
}