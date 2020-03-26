// C프로그래밍 14주차 실습문제2 

#include <stdio.h>

void addORsub(int (*arr1)[3], int (*arr2)[3], int flag);// 더하기 혹은 빼기 함수 선언
void multiply(int (*arr1)[3], int (*arr2)[3]); // 곱셈 함수 선언

int main()
{
	int arrA[3][3]={0};
	int arrB[3][3]={0};
	int i=0, j=0;

	printf("행력 A 입력:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &arrA[i][j]); // 행렬A 입력
		}
	}
	printf("\n");

	printf("행력 B 입력:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &arrB[i][j]); // 행렬B 입력
		}
	}
	printf("\n");

	addORsub(arrA, arrB, '+'); // 더하기 함수 실행
	addORsub(arrA, arrB, '-'); // 빼기 함수 실행
	multiply(arrA, arrB); // 곱하기 함수 실행

	return 0;
}

void addORsub(int (*arr1)[3], int (*arr2)[3], int flag)
{
	int a,b;
	
	if(flag=='+') // flag에 +가 입력되면 덧셈실행
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
	
	if(flag=='-') // flag에 - 가 입력되면 빼기 실행
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
	
	for(a=0; a<3; a++) // 열단위
		{
			printf("<");
			
				for(b=0; b<3; b++) // 행단위
				{
					sum=0; // sum값 초기화
					for(c=0; c<3; c++) // 하나단위
					{
					sum+=arr1[a][c]*arr2[c][b]; // 3x3 행렬의 곱셈은 3번의 곱한값을 더해줘야됨 그값 = sum
					}
					printf("%3d ", sum); // 각각더해진 값 3개리를 더한값 sum 출력
				}
			printf(" >");
			printf("\n");
		}
		printf("\n");
}