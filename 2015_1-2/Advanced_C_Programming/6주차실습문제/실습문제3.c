// 고급C프 6주차 실습문제3

#include <stdio.h>
#include <string.h>

void main()
{
	char text1[50];
	char text2[50];
	char space[1]={' '};

	printf("문자열1: ");
	gets(text1);

	printf("문자열2: ");
	gets(text2);

	strncat(text1, space, 1); // 공백 추가
	strcat(text1, text2); // text1 text2

	printf("문자열1 + 문자열2: %s\n", text1);
}