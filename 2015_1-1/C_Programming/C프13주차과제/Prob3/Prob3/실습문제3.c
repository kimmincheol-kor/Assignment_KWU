// C ���α׷��� 13���� �ǽ�����

#include <stdio.h>

void reverse(int *arr);
void swap(int *n1, int *n2);

int main()
{
	int arr[10];
	int i=0;

	printf("10���� ���� �Է�\n>> ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
	} // 10���� ������ �Է¹���
	
	reverse(arr); // �������Լ����� ����� ������ ������ �ڹٲ�

	printf(">> ");
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}

void reverse(int *arr) // �迭�� �ּҰ� �Է�
{
	int i;

	for(i=0; i<5; i++)
	{
		swap(&arr[i], &arr[9-i]); // ù��°�� ������, �ι�°�� �ڿ��� �ι�°, �̷��� �ٲ���. 5�� �ݺ��̸� �ٹٲ�
	}
}

void swap(int *n1, int *n2) // swap �Լ� = �� ���� ���� ���� �ٲ���
{
	int temp=*n1;

	*n1=*n2;
	*n2=temp;
}