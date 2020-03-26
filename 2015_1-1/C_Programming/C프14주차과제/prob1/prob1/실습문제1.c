// C프로그래밍 14주차 실습문제1

#include <stdio.h>

int main()
{
	int arrA[2][4]={0};
	int arrB[4][2]={0};
	int i=0, j=0;

	printf("행렬 A 입력:\n");
	for(i=0; i<2; i++)
	{
		for(j=0;j<4; j++)
		{
			scanf("%d", &arrA[i][j]); // arrA에 값 입력
		}
	}

	printf("\n");

	printf("행력 B:\n");
	for(i=0; i<4; i++)
	{
		for(j=0;j<2; j++)
		{
			arrB[i][j]=arrA[j][i]; // 행렬A의 a행 b열을 행렬B의 b행 a열에 입력 = transpose
			printf("%d ", arrB[i][j]); //행렬B 출력
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}