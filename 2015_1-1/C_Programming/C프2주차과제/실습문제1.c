/* C ���α׷���
    2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num1=3, num2=1, num3=2; //����num1,2,3�� ���� �� �ʱ�ȭ
	printf("%d x %d = %d \n", num1, num2, num1*num2); //3x1=3
	printf("%d x %d = %d \n", num1, num3, num1*num3); //3x2=6
	printf("%d x %d = %d \n", num1, num1, num1*num1); //3x3=9

	return 0;
}