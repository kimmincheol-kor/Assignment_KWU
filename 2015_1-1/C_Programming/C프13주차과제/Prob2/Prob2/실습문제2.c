// C ���α׷��� 13���� �ǽ�����

#include <stdio.h>

void ShowOddOrEven(int *arr, int a, int b); // ¦������Ȧ������ �����ϴ� �Լ�

int main()
{
	int arr[10];
	int i;

	printf("�� 10���� ���� �Է�\n");
	for(i=0; i<10; i++)
	{
		printf("�Է�: ");
		scanf("%d", &arr[i]);
	} // arr �迭�� ���� 10�� �Է�

	printf("Ȧ�� ���: ");
	ShowOddOrEven(arr, 10, 1); // �迭�Է�, ũ���Է�, Ȧ���� 1 �Է�

	printf("\n");

	printf("¦�� ���: ");
	ShowOddOrEven(arr, 10, 0); // ¦���� �������� 0 �Է�

	printf("\n");

	return 0;
}

void ShowOddOrEven(int *arr, int size, int flag)
{
	int i,j,k;
	if(flag==1){ // flag���� 1�̶�� = Ȧ���� ���
	for(i=0; i<size; i++)
	{
		if(arr[i]%2==1) // 2�γ��� �������� 1 = Ȧ��
			printf("%d, ", arr[i]);
	}
	}

	if(flag==0){ // flag���� 0�̸� = ¦���� ���
	for(i=0; i<size; i++)
	{
		if(arr[i]%2==0) // 2�γ��������.
			printf("%d, ", arr[i]);
	}
	}

}