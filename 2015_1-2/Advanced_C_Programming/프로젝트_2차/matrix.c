#include <stdio.h>

void sum(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // 덧셈
{
	int sz1, sz2;
	int i,j;

	while(1)
	{
		printf("행렬2 크기<2~10>: ");
		scanf("%d%d", &sz1, &sz2);
		fflush(stdin);
	if( sz1<2 || sz1>10 || sz2<2 || sz2>10 )
		printf("행렬의 크기가 잘못되었습니다.\n");
	else
		break;
	}
	
	

	printf("행렬2 입력: \n");
		for(i=0; i<sz1; i++) // 행렬2 입력
		{
			for(j=0; j<sz2; j++)
			{
				scanf("%lf", &hang2[i][j]);
			}
		}

	if( sz1!=size1 || sz2!=size2 )
		{
		printf("두 행렬의 크기가 다릅니다.\n");
		return;
		}

	printf("행렬 덧셈 결과\n");
		for(i=0; i<sz1; i++) // 행렬2 입력
		{
			for(j=0; j<sz2; j++)
			{
				printf("%8.2f ", hang1[i][j]+hang2[i][j]);
			}
			printf("\n");
		}


}

void sub(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // 뺄셈
{
	int sz1, sz2;
	int i,j;
	while(1)
	{
		printf("행렬2 크기<2~10>: ");
		scanf("%d%d", &sz1, &sz2);
		fflush(stdin);
	if( sz1<2 || sz1>10 || sz2<2 || sz2>10 )
		printf("행렬의 크기가 잘못되었습니다.\n");
	else
		break;
	}
	

	printf("행렬2 입력: \n");
		for(i=0; i<sz1; i++) // 행렬2 입력
		{
			for(j=0; j<sz2; j++)
			{
				scanf("%lf", &hang2[i][j]);
			}
		}

	if( sz1!=size1 || sz2!=size2 )
		{
		printf("두 행렬의 크기가 다릅니다.\n");
		return;
		}

	printf("행렬 뺄셈 결과\n");
		for(i=0; i<sz1; i++) // 행렬2 입력
		{
			for(j=0; j<sz2; j++)
			{
				printf("%8.2f ", hang1[i][j]-hang2[i][j]);
			}
			printf("\n");
		}


}

void mul(double (*hang1)[10], double (*hang2)[10], int size1, int size2)
{
	int a,b,c;
	double sum=0;

	int sz1, sz2;
	int i,j;

	printf("행렬2 크기<2~10>: ");
	scanf("%d%d", &sz1, &sz2);
	fflush(stdin);
	if( size2!=sz1 ){
		printf("곱셈할 수 없는 식입니다.\n");
		return;
	}
	
	else
	{
	printf("행렬2 입력: \n");
	for(i=0; i<sz1; i++) // 행렬2 입력
	{
		for(j=0; j<sz2; j++)
		{
			scanf("%lf", &hang2[i][j]);
		}
	}

	printf("곱셈 결과\n");
	for(a=0; a<sz2; a++) // 열단위
		{
				for(b=0; b<size1; b++) // 행단위
				{
					sum=0; // sum값 초기화
						for(c=0; c<size2; c++) // 하나단위
						{
							sum+=hang1[a][c]*hang2[c][b]; // 3x3 행렬의 곱셈은 3번의 곱한값을 더해줘야됨 그값 = sum
						}
					printf("%8.2f ", sum); // 각각더해진 값 3개리를 더한값 sum 출력
				}
			printf("\n");
		}
	} // if문 종료

}

void rev(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // // 행렬곱셈
{
	double temp;
	double revn;
	int i,j;
	
	if( size1==2 && size2==2 )
	{
		revn=hang1[0][0]*hang1[1][1]-hang1[0][1]*hang1[1][0];
		hang2[0][0]=hang1[1][1]/revn; hang2[0][1]=-hang1[0][1]/revn;
		hang2[1][0]=-hang1[1][0]/revn; hang2[1][1]=hang1[0][0]/revn;

		printf("역행렬 결과\n");
		for(i=0; i<2; i++) // 행렬2 입력
		{
			for(j=0; j<2; j++)
			{
				printf("%8.2f ", hang2[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("2x2 행렬이 아닙니다.\n");
	}

}

void trans(double (*hang1)[10], double (*hang2)[10], int size1, int size2) //전치행렬
{
	double temp;
	int i,j;

	printf("전치[ 결과\n");
	for(i=0; i<size2; i++)
	{
		for(j=0; j<size1; j++)
		{
			temp=hang1[j][i];
			hang2[i][j]=temp;
			printf("%8.2f ", hang2[i][j]);
		}
		printf("\n");
	}
}


void main()
{
	double hang1[10][10];
	double hang2[10][10];
	int what;
	int size1, size2;
	int i,j,k;

	while(1) // 전체 while
	{
		while(1) // 크기입력 while
		{
			printf("행렬1 크기<2~10>: ");
			scanf("%d%d", &size1, &size2);
			fflush(stdin);
			if( size1<2 || size1>10 || size2<2 || size2>10 )
				printf("행렬의 크기가 잘못되었습니다.\n");
			else
				break;
		}

		printf("행렬1 입력: \n");
		for(i=0; i<size1; i++) // 행렬1 입력
		{
			for(j=0; j<size2; j++)
			{
				scanf("%lf", &hang1[i][j]);
			}
		}
		

		while(1) // 연산 입력.
		{
		printf("연산<1:덧셈, 2:뺄셈, 3:곱셈, 4:역행렬, 5:전치행렬>: ");
		scanf("%d", &what);

		if(what>5 || what<1)
			{
			printf("잘못된 선택입니다.\n");
			continue;
			}
		
		else
			{
		switch(what)
			{

			printf("연산<1:덧셈, 2:뺄셈, 3:곱셈, 4:역행렬, 5:전치행렬>: ");
			scanf("%d", &what);

			case 1: // 덧셈
				sum(hang1, hang2, size1, size2);
				break;
	
			case 2: // 뺄셈
				sub(hang1, hang2, size1, size2);
				break;
	
			case 3: // 곱셈
				mul(hang1, hang2, size1, size2);
				break;
	
			case 4: // 역행렬
				rev(hang1, hang2, size1, size2);
				break;

			case 5: // 전치행렬
				trans(hang1, hang2, size1, size2);
				break;

			default: // 갈일없음.
				break;
			
			} // 연산 switch 문 종료
			
			break;

			} // else 문 종료
		


		} // 연산 while 문 종료
	} // 전체 while 종료
} // 메인 함수 종료