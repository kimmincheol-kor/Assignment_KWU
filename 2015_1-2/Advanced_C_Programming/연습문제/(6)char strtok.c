// ���ڿ��� ���ڷ� �ڸ���

#include <stdio.h>
#include <string.h>

int main()
{
	char *tok;
	char str[]="you are good boy";

	tok=strtok(str, " "); // str�� " "�� ��������

	while(tok)
	{
		printf("%s\n", tok);
		tok=strtok(NULL, " "); // ������ ���� ������. " " �� ��������
	}
}