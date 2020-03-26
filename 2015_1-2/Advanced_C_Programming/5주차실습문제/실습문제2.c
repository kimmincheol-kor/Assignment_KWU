// 고급C프로그래밍 실습문제2

#include <stdio.h>

void main()
{
	int score[3][3];
	int total[2]={0,0};
	int i;

	for(i=0; i<3; i++) // 세명의 학번,영어,수학 입력.
	{
		printf("학번: ");
		scanf("%d", &score[i][0]); // 학번 입력
		fflush(stdin);

		while(1) // 영어 점수 입력
		{
			printf("영어점수<0~100>: ");
			scanf("%d", &score[i][1]);
			fflush(stdin);

			if((score[i][1]>100)||(score[i][1]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		while(1) // 수학 점수 입력
		{
			printf("수학점수<0~100>: ");
			scanf("%d", &score[i][2]);
			fflush(stdin);

			if((score[i][2]>100)||(score[i][2]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		total[0]+=score[i][1]; // 세명의 영어점수의 합
		total[1]+=score[i][2]; // 세명의 수학점수의 합
	}

	printf("%-12s %-8s %-8s\n", "학번", "영어", "수학");
	for(i=0; i<3; i++) // 세명의 학번,영어,수학 출력
	{
		printf("%-12d %-8d %-8d \n", score[i][0], score[i][1], score[i][2]);
	}

	printf("영어 평균: %.6f\n", (double)total[0]/3);
	printf("수학 평균: %.6f\n", (double)total[1]/3); // 평균을 출력, 소수점 여섯번째 자리까지
}