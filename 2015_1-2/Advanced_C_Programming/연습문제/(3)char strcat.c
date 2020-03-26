// 문자열에 문자열을 덧붙임

#include <stdio.h>
#include <string.h>
char * strcat(char *dest, const char *src);

void main()
{
	char str1[32]={"hohohohoho"};
	char str2[32]={"kokokokoko"};

	strcat(str1, str2); // str1 뒤에 str2를 덧붙임

	printf("%s\n", str1);
	printf("%s\n", str2);
}