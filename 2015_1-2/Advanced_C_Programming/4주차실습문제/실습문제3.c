// C ���α׷��� 4���� �ǽ�����3

#include <stdio.h>

void main()
{
	char name[3][16];
	int score[3][3];
	int i;

	for(i=0; i<3; i++) // �̸�, ���� �Է�
	{
		printf("%d�� �̸�: ", i+1);
		gets(name[i]);
		fflush(stdin);

		while(1)
		{
		printf("���� ����<0-100>: ");
		scanf("%d", &score[i][0]);
		fflush(stdin);

		if((score[i][0]>100)||(score[i][0]<0))
			printf("������ �ٽ� Ȯ���ϼ���\n");
		else
			break;
		}

		while(1)
		{
		printf("���� ����<0-100>: ");
		scanf("%d", &score[i][1]);
		fflush(stdin);

		if((score[i][1]>100)||(score[i][1]<0))
			printf("������ �ٽ� Ȯ���ϼ���\n");
		else
			break;
		}

		while(1)
		{
		printf("���� ����<0-100>: ");
		scanf("%d", &score[i][2]);
		fflush(stdin);

		if((score[i][2]>100)||(score[i][2]<0))
			printf("������ �ٽ� Ȯ���ϼ���\n");
		else
			break;
		}
	}

	printf("\n");

	printf("%-8s %-8s %-8s %-8s\n", "�̸�","����","����","����");
	for(i=0; i<3; i++)
	{
		printf("%-8s %-8d %-8d %-8d\n", name[i], score[i][0], score[i][1], score[i][2]);
	}
}