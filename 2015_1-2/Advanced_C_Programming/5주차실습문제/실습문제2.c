// ���C���α׷��� �ǽ�����2

#include <stdio.h>

void main()
{
	int score[3][3];
	int total[2]={0,0};
	int i;

	for(i=0; i<3; i++) // ������ �й�,����,���� �Է�.
	{
		printf("�й�: ");
		scanf("%d", &score[i][0]); // �й� �Է�
		fflush(stdin);

		while(1) // ���� ���� �Է�
		{
			printf("��������<0~100>: ");
			scanf("%d", &score[i][1]);
			fflush(stdin);

			if((score[i][1]>100)||(score[i][1]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		while(1) // ���� ���� �Է�
		{
			printf("��������<0~100>: ");
			scanf("%d", &score[i][2]);
			fflush(stdin);

			if((score[i][2]>100)||(score[i][2]<0))
				printf("score error<0~100>\n");
			else
				break;
		}

		total[0]+=score[i][1]; // ������ ���������� ��
		total[1]+=score[i][2]; // ������ ���������� ��
	}

	printf("%-12s %-8s %-8s\n", "�й�", "����", "����");
	for(i=0; i<3; i++) // ������ �й�,����,���� ���
	{
		printf("%-12d %-8d %-8d \n", score[i][0], score[i][1], score[i][2]);
	}

	printf("���� ���: %.6f\n", (double)total[0]/3);
	printf("���� ���: %.6f\n", (double)total[1]/3); // ����� ���, �Ҽ��� ������° �ڸ�����
}