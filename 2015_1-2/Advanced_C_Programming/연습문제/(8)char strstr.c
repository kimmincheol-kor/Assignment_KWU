// 문자열에서 임의의 문자열의 위치를 검색

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="we are good boy";

	printf("%s\n", strstr(str, "good")); // str에서 good 문자열을 찾아 포인터를 반환

	return 0;
}