// ���ڿ��� ����

#include <stdio.h>
#include <string.h>
char * strcpy(char * dest, const char * src);

void main()
{
	char str1[32]={"sososososo"};
	char str2[32]={"hohohohohoho"};

	strcpy(str2, str1); // str1�� ���ڿ��� str2�� ����

	printf("%s\n", str1);
	printf("%s\n", str2);
}