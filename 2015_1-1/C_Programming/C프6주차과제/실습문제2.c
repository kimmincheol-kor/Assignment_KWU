/* C ���α׷���
    6���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int kim;
	int park;
	int lee=1; // �������� 0 �� �Ǵ°� �����ϱ����� 1���� ����

	printf("Input : ");
	scanf("%d", &kim);

	for(park=1; kim>=park; park++) // ���� 1�� �ʱ�ȭ��Ű��; ���� �躸�� �۰ų� ������ ��ɹ� ����; ��ɹ��� ������ �ڿ� 1�� ������
	{
		lee*=park; //(����)��X�� = (���ο�)�� => 1x2x3x.......xN = N!
    }
	
	printf("%d! = %d\n", kim, lee); // ���⼭ lee �� ��Ӱ����� ������

	return 0;
}