/* C���α׷��� 11���� �ǽ����� */

#include <stdio.h>

void swap(int *num1, int *num2);

int main()
{
    int n1, n2;
	printf("Input n1: ");
	scanf("%d", &n1); //n1 �Է�
	printf("Input n2: ");
	scanf("%d", &n2); //n2 �Է�

	swap(&n1,&n2); // swap �Լ� ȣ��, �Է°��� n1�� n2�� �ּҰ�
	
	printf("--- swap �Լ� ���� ---\n");
	printf("Output n1: %d\n", n1);
	printf("Output n2: %d\n", n2);

	return 0;
}

void swap(int *num1, int *num2)
{
	int point1=*num1;//����Ʈ1�� ���� num1�� �ּҰ�
	int point2=*num2;//����Ʈ2�� ���� num2�� �ּҰ�

	*num1=point2; //num1�� �ּҰ��� ����Ʈ2�� ��
	*num2=point1; //num2�� �ּҰ��� ����Ʈ1�� ��
}