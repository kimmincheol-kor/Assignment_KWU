// C���α׷��� 14���� �ǽ�����1

#include <stdio.h>

int main()
{
	int arrA[2][4]={0};
	int arrB[4][2]={0};
	int i=0, j=0;

	printf("��� A �Է�:\n");
	for(i=0; i<2; i++)
	{
		for(j=0;j<4; j++)
		{
			scanf("%d", &arrA[i][j]); // arrA�� �� �Է�
		}
	}

	printf("\n");

	printf("��� B:\n");
	for(i=0; i<4; i++)
	{
		for(j=0;j<2; j++)
		{
			arrB[i][j]=arrA[j][i]; // ���A�� a�� b���� ���B�� b�� a���� �Է� = transpose
			printf("%d ", arrB[i][j]); //���B ���
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}