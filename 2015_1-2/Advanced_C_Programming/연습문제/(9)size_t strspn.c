// ���ڿ����� ������ ���ڵ�� ������ �ʱ� ���ڿ��� ���̸� �˻�

#include <stdio.h>
#include <string.h>

int main()
{
	char *str="they are good boy";

	printf("%d\n", strspn(str, "eyht")); // str �迭���� ���ڿ� eyht�� ��ġ�ϴ� ���̸� �˻�

	return 0;
}