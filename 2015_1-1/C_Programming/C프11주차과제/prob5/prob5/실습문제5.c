/* C���α׷��� 11���� �ǽ� */

#include <stdio.h>

int Tree(int num)// ���� num
{
	int a,b,c=1,d,e,f;
	
	for(a=1; a<=num; a++) // ���̸�ŭ �ݺ�.
	{
		for(d=(num-a); d>0; d--) // �����Է�, ������ ���Ҵٰ� �۾������ϱ⶧���� num1-a ���ϸ� a�� Ŀ���Ƿ� �����Է¼��� �پ���
		{
			printf(" ");
		}

		
		for(b=1; b<=c; b++) //�����Է�
		{
			printf("* ");
		}

		printf("\n");
		c++;// ���� �������� ���� 1���� �� �ԷµǾ�ߵ�
	}
}

int main()
{
	int height;
	int i,j,k;

	printf("���� �Է�: ");
	scanf("%d", &height);

	Tree(height);

	return 0;
}