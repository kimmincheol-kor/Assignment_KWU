/* C ���α׷���
    2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num1, num2; //�ѹ�1�� �ѹ�2�� ����
	int result1;

	printf("�� ���� ���� �Է� : ");
	scanf("%d %d", &num1, &num2);// �ѹ�1 �ѹ�2 �Է�

	result1=(num1==num2); //result ����
    printf("��� : %d\n", result1);

	return 0;
}