// C ���α׷��� 2���� �ǽ�����3

#include <stdio.h>

void main()
{
	char str[32];
	char *p; // char ������ ������ ����

	printf("�Է�: ");
	gets(str); // str�迭�� �����Է�

	printf("���: ");
	
	p = str; // p�� str�迭�� ����Ų��. �迭�� ù��° �ּҸ� ����Ŵ.
	printf("%s", p); // p�� ����Ű�� �ּ�(�迭�� ù����)���� null���� ����ִ� �ּ�(�� �ּ�)������ ������ ���

	printf("\n");
}