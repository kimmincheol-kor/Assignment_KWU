/* C ���α׷���
    2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num1, num2; // �ѹ�1 �ѹ�2 ����
	printf("ù ��° ���� �Է� : ");
	scanf("%d", &num1); //�ѹ�1 �Է�
	printf("�� ��° ���� �Է� : ");
	scanf("%D", &num2); //�ѹ�2 �Է�

	/* ��Ģ���� ����� */
	
	printf("%d + %d = %d\n", num1, num2, num1+num2);
	printf("%d - %d = %d\n", num1, num2, num1-num2);
	printf("%d x %d = %d\n", num1, num2, num1*num2);
	printf("%d / %d = %d\n", num1, num2, num1/num2);

	return 0;
}