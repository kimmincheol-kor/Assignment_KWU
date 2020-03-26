// C 프로그래밍 4주차 실습문제2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int dice1, dice2;
	int total[6][6]={0,};
	int i,j;
	srand((unsigned)time(NULL)); // 랜덤값이 실행때마다 바뀔수있게

	for(i=0; i<1000; i++)
	{
	dice1=rand()%6+1; // dice1은 1~6중에 하나가 됨
	dice2=rand()%6+1;

	total[dice1-1][dice2-1]+=1; // 배열은 0~5 까지 이므로 dice-1 칸에 나온횟수 +1
	}

	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			printf("%d %d: %d\n", i+1, j+1, total[i][j]); // 토탈값 출력
		}
	}



}