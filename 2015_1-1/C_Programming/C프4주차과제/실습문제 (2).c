/* C ���α׷���
   4���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	
	long long int x;
	long long int y;
	long long int z; //ũ�Ⱑ 8����Ʈ�� �������� ����ϴ� �շ� 
	
	printf("�й��� �Է��ϼ��� : ");
	scanf("%lld", &x); // x�� �й� �Է�
	
	y=x*2; // �й�x2
	z=x*x; // �й� ����
	
	printf("�й� x 2 = %lld\n",y); // �й�x2 ��� %lld �� �շ��� ���, ��ȣ�ִ� 10���� ������ ����Ҷ� ���δ�.
	
	printf("�й��� ������ ��� = %lld\n",z); // �й������� ���

	return 0;
}