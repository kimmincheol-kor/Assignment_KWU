/* C ���α׷���
   2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ��̴�
{
	int x=5; //x�� 5�� ����

	printf("x�� �ʱⰪ : %d\n", x); //x�� 5�̴�
	printf("1. x = %d\n", ++x); //x�� 6�̵Ǿ� ��µȴ�.
	printf("2. x = %d\n", x--); //x�� 6������� > 5�� �ȴ�
	printf("3. x = %d\n", --x); //x�� 4�εǾ� ��µȴ�
	printf("4. x = %d\n", x++); //x�� 4����µǰ� 5���ȴ�
	printf("5. x = %d\n", x--); //x�� 5�� ��µǰ� 4���ȴ�
	printf("x�� ���� �� : %d\n\n", x); //x�� 4�� ��µȴ�
	
	return 0;
}