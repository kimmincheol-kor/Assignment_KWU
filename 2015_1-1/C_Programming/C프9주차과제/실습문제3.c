/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>

int sum(int num)
{
	if(num<=1){
		return 1; // ���������� num���� 1�����ִٰ� 1�� �Ǿ����� 1�� ��ȯ => �Լ��ݺ� ����
	}
	else
		return num+sum(num-1);} //sum�Լ��� �� num+sum(num-1) ��ȯ = �ݺ�
}

int main()
{
	int num;

	printf("1���� n������ �� ���ϱ�\n");
	printf("n �Է� : ");
	scanf("%d", &num);
	printf("��� : %d\n", sum(num)); // �Լ� ȣ��

    return 0;
}