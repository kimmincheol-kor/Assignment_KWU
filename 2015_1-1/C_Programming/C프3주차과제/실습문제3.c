/* C ���α׷���
   2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num1, num2; // num1�� num2�� �޸� �Ҵ�

	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &num1, &num2); //num1�� num2�� �����Է�

	printf("�� ���� AND ���� ��� : %d\n", num1&num2); //AND ���� &
	printf("�� ���� OR ���� ��� : %d\n", num1|num2); // OR ���� |
	printf("�� ���� XOR ���� ��� : %d\n", num1^num2); // XOR ���� ^

	return 0;
}