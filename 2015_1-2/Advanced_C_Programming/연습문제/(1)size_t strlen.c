// ���ڿ��� ũ�⸦ ��ȯ.

#include <stdio.h>
#include <string.h>
size_t strlen(const char *str); // �ι��ڴ� ���̿� ���� X

void main()
{
	char str[32]={"ssss"};

	printf("str �迭�� ũ�� : %u \n", strlen(str)); // �迭�� ũ�� ���
}