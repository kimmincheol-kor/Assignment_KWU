// C ���α׷��� 2���� �ǽ�����1

#include <stdio.h>

void main()
{
	int i=10;
	int *p;
	p=&i; // p�� ����Ű�� �� = i �� �ּ�

	printf("i�� �ּ�: %d\n", &i);
	printf("i�� ��: %d\n", i);
	printf("p�� ����Ű�� �ּ�: %d\n", p);
	printf("*p�� ��: %d\n", *p);
}