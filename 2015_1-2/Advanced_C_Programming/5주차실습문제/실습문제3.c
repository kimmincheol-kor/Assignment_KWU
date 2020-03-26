// 고급C프로그래밍 실습문제3

#include <stdio.h>

void calc(int score[3][3])
{
	int a;
	int totalE=0, totalM=0;
	
	printf("%-12s %-8s %-8s\n", "학번", "영어", "수학");
	for(a=0; a<3; a++)
	{
		printf("%-12d %-8d %-8d \n", score[a][0], score[a][1], score[a][2]);
		
		totalE+=score[a][1];
		totalM+=score[a][2];
	}

	printf("영어 평균: %.6f\n", (double)totalE/3);
	printf("수학 평균: %.6f\n", (double)totalM/3);
}

void main()
{
	int score[3][3];
	int i;

	for(i=0; i<3; i++) // 세명의 학번,영어,수학 입력.
	{
		printf("학번: ");
		scanf("%d", &score[i][0]); // 학번 입력
		fflush(stdin);

		while(1) // 영어점수 입력
		{
			printf("영어점수<0~100>: ");
			scanf("%d", &score[i][1]);
			fflush(stdin);

			if((score[i][1]>100)||(score[i][1]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		while(1) // 수학점수 입력
		{
			printf("수학점수<0~100>: ");
			scanf("%d", &score[i][2]);
			fflush(stdin);
			
			if((score[i][2]>100)||(score[i][2]<0))
				printf("score error<0~100>\n");
			else
				break;
		}
	}

	calc(score); // calc 함수 실행

}