// C���α׷��� 12���� �ǽ�����

#include <stdio.h>

void gopagi(int *num) // ���ϱ� �Լ����� �ּҰ��� �Էµ� �迭���� ���� ������ �ٲٱ����ؼ�
{
	int *point=num; // point�� �ּҰ��� num

	*point*=2; // ���°��� �ּҿ� ����ִ� ������ x2
}

int main()
{
	int five[5];
	int i,k,j;
	int size=sizeof(five)/sizeof(int);

	printf(">> �ټ� ���� ���� �Է�: ");
	for(i=0; i<size; i++) // five �迭�� 5���� ���� �Է�
	{
		scanf("%d", &five[i]);
	}

	for(k=0; k<size; k++) 
	{
		gopagi(&five[k]); //five �迭�� ��� �ּҰ��� ���ϱ� �Լ��� �Է�
	}

	printf(">> ���<x2>: ");

	for(j=0; j<size; j++)
	{
		printf("%d ", five[j]); // five �迭�� ��簪 �ٽ� ���
	}

	printf("\n");

	return 0;
}