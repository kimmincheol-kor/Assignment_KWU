/* C ���α׷���
   2���� �ǽ� */

#include <stdio.h>

int main(void)
{
    int x=1;
	int y=3;
	

	printf("%d ���ϱ� %d�� %d�Դϴ�.\n", ++x, y++, x+y); // x�� 2���Ǽ� ��µǰ� y�� 3���� ��µ��� 4���ȴ�
	printf("%d ���� %d�� %d�Դϴ�.\n\n", ++y, x++, x); // y�� 5���Ǽ� ��µǰ� x�� 2�� ��µǰ� 3�̵ȴ�

	return 0;
}