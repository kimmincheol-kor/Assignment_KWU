// C���α׷��� 2���� �ǽ�����4

#include <stdio.h>

void main()
{
	int n1=10, n2=20, n3;
	int *p;

	printf("n1: %d\n", n1);
	printf("n2: %d\n", n2);
	
	p=&n3; // p�� n3�� �ּҸ� ����Ŵ
	*p=n1+n2; // p�� ����Ű�� �ּ��� ��(n3�� ��)�� n1+n2�� �Է�
	
	printf("n1+n2: %d\n", n3); // n3 ���
}