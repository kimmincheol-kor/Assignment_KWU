/* C ���α׷���
   2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num1=0x7B, num2=0xFF, num3=052, num4=037; //0x�� �����ϸ� 16����, 0���� �����ϸ� 8����
	
	
	printf("16���� 7B�� 10���� ���� �� : %d\n", num1); //0x7B�� ����Ʈ
	printf("16���� FF�� 10���� ���� �� : %d\n", num2); //0xFF
	printf("8���� 52�� 10���� ���� �� : %d\n", num3); //052
	printf("8���� 37�� 10���� ���� �� : %d\n", num4); //037

	return 0;
}