// 문자열에서 지정된 문자들로 구성된 초기 문자열의 길이를 검색

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="they are good boy";

	printf("%d\n", strspn(str, "eyht")); // str 배열에서 문자열 eyht와 일치하는 길이를 검색

	return 0;
}