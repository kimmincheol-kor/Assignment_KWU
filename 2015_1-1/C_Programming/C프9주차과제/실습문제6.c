/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>

int Tree(char ch1, int num1) // ���� ch1, ���� num1
{
	int a,b,c=1,d,e,f;
	
	for(a=1; a<=num1; a++) // ���̸�ŭ �ݺ�.
	{
		for(d=(num1-a); d>0; d--) // �����Է�, ������ ���Ҵٰ� �۾������ϱ⶧���� num1-a ���ϸ� a�� Ŀ���Ƿ� �����Է¼��� �پ���
		{
			printf(" ");
		}

		
		for(b=1; b<=c; b++) //�����Է�
		{
			printf("%c", ch1);
		}

		printf("\n");
		c+=2; // ���� �������� ���� 2���� �� �ԷµǾ�ߵ�
	}
}


int main()
{
	char ch;
	int num=0;

	printf("���� �Է� : ");
	scanf("%c", &ch);
	printf("���� �Է� : ");
	scanf("%d", &num);
	Tree(ch, num);

	return 0;
}

