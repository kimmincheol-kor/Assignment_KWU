/* C ���α׷���
   4���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int x,y,z;
	int sum; // ������ ����
	double avg; // �Ҽ��� ���� ����
	
	printf("���� : ");
	scanf("%d %d %d",&x,&y,&z); //���� �Է�
	
	sum=x+y+z; // ���� ����� sum�� �Է�(����) 
	avg=(double)sum/3; // ����� ���, double�����(�Ҽ�)
	
	printf("���� : %d\n",sum); //�������
	printf("��� : %.2f\n",avg);//����� �Ҽ���°�ڸ����� ���

	return 0;
}