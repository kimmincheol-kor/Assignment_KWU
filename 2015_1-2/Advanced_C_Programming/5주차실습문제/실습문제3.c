// ���C���α׷��� �ǽ�����3

#include <stdio.h>

void calc(int score[3][3])
{
	int a;
	int totalE=0, totalM=0;
	
	printf("%-12s %-8s %-8s\n", "�й�", "����", "����");
	for(a=0; a<3; a++)
	{
		printf("%-12d %-8d %-8d \n", score[a][0], score[a][1], score[a][2]);
		
		totalE+=score[a][1];
		totalM+=score[a][2];
	}

	printf("���� ���: %.6f\n", (double)totalE/3);
	printf("���� ���: %.6f\n", (double)totalM/3);
}

void main()
{
	int score[3][3];
	int i;

	for(i=0; i<3; i++) // ������ �й�,����,���� �Է�.
	{
		printf("�й�: ");
		scanf("%d", &score[i][0]); // �й� �Է�
		fflush(stdin);

		while(1) // �������� �Է�
		{
			printf("��������<0~100>: ");
			scanf("%d", &score[i][1]);
			fflush(stdin);

			if((score[i][1]>100)||(score[i][1]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		while(1) // �������� �Է�
		{
			printf("��������<0~100>: ");
			scanf("%d", &score[i][2]);
			fflush(stdin);
			
			if((score[i][2]>100)||(score[i][2]<0))
				printf("score error<0~100>\n");
			else
				break;
		}
	}

	calc(score); // calc �Լ� ����

}