// C ���α׷��� 14���� �ǽ�����3

#include <stdio.h>

int main()
{
	char mvTitle[5][20]={0};
	char title[20]={0}; // �ӽ÷� ũ�Ⱑ 20�� �迭 ����
	int mvScore[5]={0};
	int menu, i,j,k;

	printf("\n");
	printf("=============================\n");
	printf(">> 1. ��ȭ ���� ���\n");
	printf(">> 2. ��� ����\n");
	printf(">> 3. ����\n");
	printf("=============================\n");

	while(1)
	{
		printf(">> select: ");
		scanf("%d", &menu);
		getchar(); // ���ۿ� ���Ͱ� �����ֱ⶧���� getchar�� ������

		switch(menu)
		{
			case 1:
				if(mvTitle[4][0]!=0) // 5��°�� ��ȭ������ �ԷµǾ��ٸ� ���̻� �߰� X
				{
					printf("�� �̻� �߰��� �� �����ϴ�<�ִ� 5��>\n"); // ����ó�� 3
					break;
				}
				else
				{
				for(i=0; i<5; i++)
					{
						if(mvTitle[i][0]==0){ // ���� �Էµ��� �ʾҴٸ� ����
							printf("����: ");
							for(k=0; k<20; k++)
							{
								title[k]=0; // title�� �Էµ� �����ֱ�
							}
							gets(title); // title�� �Է¹���
							for(k=0; k<20; k++)
							{
								mvTitle[i][k]=title[k]; // title�� mvTitle�� ����
							}
							printf("����<1~5>: ");
							scanf("%d", &mvScore[i]); // ���� �Է�, ����� ���� ������
							if(mvScore[i]>5){ // ����ó��2 ������ 5���� ������ ���� ���Է�
								printf("����<1~5>: ");
								scanf("%d", &mvScore[i]);}
							break;}
					}
					break;
				}
				
			case 2:
				printf("\n");
				printf("-----------------------------------\n");
				printf(" [��ȭ]               [����]\n");
				for(j=0; j<5; j++)
				{
					if(mvTitle[j][0]!=0){
					printf(" ");
					for(k=0; k<20; k++)
					{
						printf("%c", mvTitle[j][k]); // ��ȭ ���� ���
					}
					for(i=0; i<mvScore[j]; i++)
					{
						printf("��"); // ���� ��ŭ �׸� ���
					}
					printf("\n");
					}
				}
				printf("-----------------------------------\n");
				break;
			
			case 3:
				printf("���α׷� ����\n"); // 3�� �Է��ϸ� ���α׷� ����
				break;
			
			default:
				printf("�ٽ� �Է��ϼ���\n"); // ����ó��1
				break;
		}
		if(menu==3) // menu�� 3�� �ԷµǸ� ����ġ���� Ż�� > �� while���� Ż�� > ����
			break;
	}

	return 0;
}