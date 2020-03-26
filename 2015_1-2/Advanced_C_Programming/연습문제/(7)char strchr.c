// 찾고자 하는 문자가 발견된 첫번째의 포인터를 반환

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="i am good boy";

	printf("%s\n", strchr(str, 'g')); // str에서 처음발견된 g의 포인터를 반환

	return 0;
}