// C ���α׷��� 1���� �ǽ�����3

#include <stdio.h>

int factorial(int n); // ���丮�� �Լ� ����

int main()
{
	int num;
	while(1){

	printf("�Է�: ");
	scanf("%d", &num); // ���� �Է¹���
	
	
	if(num>0) // ����� �Է¹�����,
		{printf("%d!: %d\n",num ,factorial(num)); // ���丮���Լ��� num �Է�
		break;}
	else
		printf("�ٽ� �Է��ϼ���.\n");
	}


}

int factorial(int n)
{
	if(n<=1)
		return 1; // �Է¹������� 1�̰ų� ������ ��ȯ���� 1
	else
		return n*factorial(n-1); // ����Լ�!!
}