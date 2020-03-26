// C���α׷��� 14���� �ǽ�����2 

#include <stdio.h>

void addORsub(int (*arr1)[3], int (*arr2)[3], int flag);// ���ϱ� Ȥ�� ���� �Լ� ����
void multiply(int (*arr1)[3], int (*arr2)[3]); // ���� �Լ� ����

int main()
{
	int arrA[3][3]={0};
	int arrB[3][3]={0};
	int i=0, j=0;

	printf("��� A �Է�:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &arrA[i][j]); // ���A �Է�
		}
	}
	printf("\n");

	printf("��� B �Է�:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &arrB[i][j]); // ���B �Է�
		}
	}
	printf("\n");

	addORsub(arrA, arrB, '+'); // ���ϱ� �Լ� ����
	addORsub(arrA, arrB, '-'); // ���� �Լ� ����
	multiply(arrA, arrB); // ���ϱ� �Լ� ����

	return 0;
}

void addORsub(int (*arr1)[3], int (*arr2)[3], int flag)
{
	int a,b;
	
	if(flag=='+') // flag�� +�� �ԷµǸ� ��������
	{
		printf("A + B =\n");

		for(a=0; a<3; a++)
		{
			printf("<");
				for(b=0; b<3; b++)
				{
				
					printf("%3d ", arr1[a][b]+arr2[a][b]); 
				
				}
			printf(" >");
			printf("\n");
		}
		printf("\n");
	}
	
	if(flag=='-') // flag�� - �� �ԷµǸ� ���� ����
	{
		printf("A - B =\n");
		
		for(a=0; a<3; a++)
		{
			printf("<");
				for(b=0; b<3; b++)
				{
				printf("%3d ", arr1[a][b]-arr2[a][b]);
				}
			printf(" >");
			printf("\n");
		}
		printf("\n");
	}
}

void multiply(int (*arr1)[3], int (*arr2)[3])
{
	int a,b,c;
	int sum=0;
	
	printf("A x B =\n");
	
	for(a=0; a<3; a++) // ������
		{
			printf("<");
			
				for(b=0; b<3; b++) // �����
				{
					sum=0; // sum�� �ʱ�ȭ
					for(c=0; c<3; c++) // �ϳ�����
					{
					sum+=arr1[a][c]*arr2[c][b]; // 3x3 ����� ������ 3���� ���Ѱ��� ������ߵ� �װ� = sum
					}
					printf("%3d ", sum); // ���������� �� 3������ ���Ѱ� sum ���
				}
			printf(" >");
			printf("\n");
		}
		printf("\n");
}