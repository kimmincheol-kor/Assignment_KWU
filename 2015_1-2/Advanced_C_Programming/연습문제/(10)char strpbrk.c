// 문자열에서 지정된 문자들이 있는 위치의 문자열 포인터를 반환

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="good boy is good";

	printf("%s\n", strpbrk(str,"is"));

	return 0;
}