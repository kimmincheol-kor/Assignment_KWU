// C ���α׷��� 4���� �ǽ�����2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int dice1, dice2;
	int total[6][6]={0,};
	int i,j;
	srand((unsigned)time(NULL)); // �������� ���ට���� �ٲ���ְ�

	for(i=0; i<1000; i++)
	{
	dice1=rand()%6+1; // dice1�� 1~6�߿� �ϳ��� ��
	dice2=rand()%6+1;

	total[dice1-1][dice2-1]+=1; // �迭�� 0~5 ���� �̹Ƿ� dice-1 ĭ�� ����Ƚ�� +1
	}

	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			printf("%d %d: %d\n", i+1, j+1, total[i][j]); // ��Ż�� ���
		}
	}



}