#include<stdio.h>

int main()
{
	int num1, num2;

	printf("����1 �Է�: ");
	scanf("%d", &num1);

	printf("����2 �Է�: ");
	scanf("%d", &num2);

	if(num1%num2==0)
		printf("%d��<��> %d�� ����Դϴ�\n", num2, num1);
	else
		printf("%d��<��> %d�� ����� �ƴմϴ�\n", num2, num1);

	return 0;
}