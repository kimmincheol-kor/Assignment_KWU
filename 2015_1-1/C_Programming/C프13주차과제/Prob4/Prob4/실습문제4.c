// C ���α׷��� 13���� �ǽ�����

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void check(int *ran, int *ans); // check �Լ� ����

int main()
{
	int i=3, j=0, k=0;
	int rannum[5]={0}; // �����ѹ� �迭
	int answer[5]={0}; // ���� �迭


	srand((unsigned)time(NULL)); // �������� ��

	for(i=3; i>0; i--) // ���� �ȳ�����
	{
		printf("%d�� �� ����", i);
		Sleep(1000);
		system("cls");
	}

	for(j=0; j<5; j++)// �����ѹ� 5�� �̾Ƽ� rannum �迭�� ����.
	{
		rannum[j]=rand()%100+1;
	}
	
	for(j=0; j<5; j++) // ���� �����ֱ�
	{
		printf(">> %d", rannum[j]);
		Sleep(1000);
		system("cls");
	}

	printf("���� 5�� ������� �Է�\n");

	check(rannum, answer);// ������Լ�

	return 0;
}

void check(int *ran, int *ans) // �迭�� ����
{
	int a=0, sum=0;
	
	for(a=0; a<5; a++)
	{
		printf("�Է�: ");
		scanf("%d", &ans[a]); // ������ �Է�
		
		if(ran[a]==ans[a])
			sum+=1; // �������� sum ���� 1�� ������
		else{ // Ʋ������ Ʋ�ȴٰ�ȳ� �� ���� �ȳ�
			printf("Ʋ�Ƚ��ϴ�\n����: %d %d %d %d %d\n", ran[0], ran[1], ran[2], ran[3], ran[4]);
			break;
			}

	}

	if(sum==5) // ��� �����̾ sum���� 5�� �Ǿ����� �����̶�� �ȳ�
		printf("��� �����Դϴ�\n");
}