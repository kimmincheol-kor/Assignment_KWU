// C���α׷��� 14���� �ǽ�����4

#include <stdio.h>

void swap(int *n1, int *n2);
void bubble_sort(int arr[][2], int cnt, int flag);
void print_arr(int arr[][2])
	{
		int i=0;
		for(i=0; i<9; i++)
			printf(" %d %d\n", arr[i][0], arr[i][1]);
	}

int main()
{
	int arr[9][2]={ {1,3}, {3,3}, {2,1}, {3,2}, {2,3}, {3,1}, {1,2}, {2,2}, {1,1} };
	int i=0;

	printf(">> ���� �迭\n");
	print_arr(arr);

	printf(">> ����: 1�ܰ�\n");
	bubble_sort(arr, 9, 1); // 2���� �������� ����
	print_arr(arr);

	printf(">> ����: 2�ܰ�\n");
	bubble_sort(arr, 9, 0); // 1���� �������� ����
	print_arr(arr);

	return 0;
}

void swap(int *n1, int *n2) // swap �Լ�
{
	int point1=*n1;
	int point2=*n2;

	*n1=point2;
	*n2=point1;
}

void bubble_sort(int arr[][2], int cnt, int flag) // �����Ʈ �Լ�
{
	int i,j,k;
	for(i=0; i<cnt; i++)
	{
			for(j=0; j<cnt-1; j++)
		{
			if(arr[j][flag]>arr[j+1][flag])
			{
				swap(&arr[j][1], &arr[j+1][1]);
				swap(&arr[j][0], &arr[j+1][0]);
			}
		}
	}
}