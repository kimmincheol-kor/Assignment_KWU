// ���ڿ��� ��

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

	// s1 �� ��ũ�� 1 ��ȯ, �� ������ -1 ��ȯ, ������ 0 ��ȯ
}