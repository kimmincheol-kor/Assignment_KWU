// ���ڿ����� ������ ���ڵ��� �ִ� ��ġ�� ���ڿ� �����͸� ��ȯ

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="good boy is good";

	printf("%s\n", strpbrk(str,"is"));

	return 0;
}