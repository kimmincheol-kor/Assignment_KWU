// C ���α׷��� 13���� �ǽ�����

#include <stdio.h>

void get_array(int *arr, int i);
void prt_array(int *arr, int i); 


int main()
{
	int a[5];

	get_array(a, 5); //get�迭�Լ� ȣ��
	prt_array(a, 5); //prt�迭�Լ� ȣ��

	return 0;
}

void get_array(int *arr, int i) // �迭���� �޴� �Լ� get
{
	int j;
	printf("Enter 5 values, after each value press enter\n");
	
	for(j=0; j<i; j++)
	{
		scanf("%d", &arr[j]); // �迭�� �Է�
	}
}

void prt_array(int *arr, int i) // �迭���� �ּҰ��� ����
{
	int k;
	printf("Printing all values\n");
	
	for(k=0; k<i; k++)
	{
		printf("%d\n", arr[k]); // �迭�� ���
	}
}