// 문자열의 크기를 반환.

#include <stdio.h>
#include <string.h>
size_t strlen(const char *str); // 널문자는 길이에 포함 X

void main()
{
	char str[32]={"ssss"};

	printf("str 배열의 크기 : %u \n", strlen(str)); // 배열의 크기 출력
}