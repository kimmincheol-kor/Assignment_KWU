/* C ���α׷���
	2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int x=5;
	int y=10;
	int z=2000; // x,y,z�� ���� 5,10,2000 ����

	printf("%d���� ���̳��Դϴ� \n", x+y+z); // 2015=x+y+z
	
	printf("\n%d���ϱ� %d�� %d�Դϴ� \n", x, y, x+y); // 15=x+y
	
	printf("\n��̳��� %d�⵵�� �����Ǿ����ϴ� \n", z-y-y-x); //1975=z-y-y-x=2000-25

	return 0;
}