// 문자열을 비교

#include <stdio.h>
#include <string.h>
int strcmp(const char *s1, const char *s2);

void main()
{
	printf("%d\n", strcmp("abcd","abcd"));
	printf("%d\n", strcmp("abcd","abcc"));
	printf("%d\n", strcmp("abcd","abbc"));
	printf("%d\n", strcmp("abcd","aabc"));
	printf("%d\n", strcmp("abcd","abcde"));

	// s1 이 더크면 1 반환, 더 작으면 -1 반환, 같으면 0 반환
}