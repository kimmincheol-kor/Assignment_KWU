// C���α׷��� 1���� �ǽ�����5

#include <stdio.h>

void swap(int *a, int *b); //swap �Լ��� ����

int main()
{
	int a,b;

	printf("�Է�: ");
	scanf("%d %d", &a, &b); // a b �Է�

	swap(&a, &b); // ���� ����.

	printf("swap ���: %d %d \n", a, b); // a b ���
}

void swap(int *a, int *b)
{
	int temp;
	temp=*a; 

	*a=*b;
	*b=temp;
}