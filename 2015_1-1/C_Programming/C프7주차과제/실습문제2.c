/* C ���α׷���
   7���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int one;
	int two;
	int three;
	
	int min;
	int min2; //�߰� ���� ����
	
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d %d", &one, &two, &three);

	min=one>two ? two : one; // min �� ���� ���߿� ���� ��.
	min2=min>three ? three : min; // min2 �� ������ min �߿� ������ = ���� ������

	printf("���� ���� �� : %d\n", min2); // min2 ���

	return 0;
}