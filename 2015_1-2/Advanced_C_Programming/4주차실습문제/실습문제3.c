// C 프로그래밍 4주차 실습문제3

#include <stdio.h>

void main()
{
	char name[3][16];
	int score[3][3];
	int i;

	for(i=0; i<3; i++) // 이름, 점수 입력
	{
		printf("%d번 이름: ", i+1);
		gets(name[i]);
		fflush(stdin);

		while(1)
		{
		printf("국어 점수<0-100>: ");
		scanf("%d", &score[i][0]);
		fflush(stdin);

		if((score[i][0]>100)||(score[i][0]<0))
			printf("점수를 다시 확인하세요\n");
		else
			break;
		}

		while(1)
		{
		printf("영어 점수<0-100>: ");
		scanf("%d", &score[i][1]);
		fflush(stdin);

		if((score[i][1]>100)||(score[i][1]<0))
			printf("점수를 다시 확인하세요\n");
		else
			break;
		}

		while(1)
		{
		printf("수학 점수<0-100>: ");
		scanf("%d", &score[i][2]);
		fflush(stdin);

		if((score[i][2]>100)||(score[i][2]<0))
			printf("점수를 다시 확인하세요\n");
		else
			break;
		}
	}

	printf("\n");

	printf("%-8s %-8s %-8s %-8s\n", "이름","국어","영어","수학");
	for(i=0; i<3; i++)
	{
		printf("%-8s %-8d %-8d %-8d\n", name[i], score[i][0], score[i][1], score[i][2]);
	}
}