/* C ���α׷���
   4���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	double rad;
	double area;
	double pie=3.14; // 8����Ʈũ���� �Ǽ����� ����ϴ� ����
	
	printf("���� �������� �Է��ϼ��� : ");
	scanf("%lf", &rad); // �������� �Է�, %lf�� 10���� ����� �ε��Ҽ��� �Ǽ�.

	area=rad*rad*pie; // ���ǳ��� area=����������*3.14
	printf("���� ���̴� %.2f�Դϴ�\n",area); // ������ %.2f �� �Ҽ��� ��°�ڸ� ������ ǥ������ �ǹ�

	return 0;
}