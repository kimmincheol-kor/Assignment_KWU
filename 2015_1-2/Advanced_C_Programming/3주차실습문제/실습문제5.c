// C ���α׷��� 3���� �ǽ�����5

#include <stdio.h>

void main()
{
	char *arr[5]={"apple","grape","banana","melon","orange"};
	int score[5]={0,};
	char ch;
	int i;

	for(i=0; i<5; i++)
	{
		printf("are you like %s <y/n>? ", arr[i]);
		scanf("%c", &ch);
		fflush(stdin); // ch �� �Է��� �����ִ� ����(����) ����

		if((ch!='y')&&(ch!='n')) // y �� n�� �Է��Ѱ� �ƴ϶��
		{
			while(1) // y�� n�� �Է��Ҷ����� �ݺ�.
			{
				printf("please type 'y' or 'n'\n");
				printf("are you like %s <y/n>? ", arr[i]);
				scanf("%c", &ch);
				fflush(stdin);
				
				if((ch=='y')||(ch=='n'))
					break;
			}

		}
		
		if(ch=='y') // y�� �Է��ߴٸ� ���� �Է�
		{printf("point<1~5>: ");
		scanf("%d", &score[i]);
		fflush(stdin);

			while(1)
			{
				if((score[i]<1)||(score[i]>5)) // �Է��������� 1~5�� �ƴ϶�� �ݺ�
					{printf("input error.<1~5>\n");
					printf("point<1~5>: ");
					scanf("%d", &score[i]);
					fflush(stdin);}
				else // �Է��������� 1~5�̸� while �� ����
					break;


			}
		}
		else if(ch=='n')
			continue;
	}


	for(i=0; i<5; i++)
		if(score[i]!=0) printf("%s: %d\n", *(arr+i), score[i]); // �Է¹��� �������� ���, �Էµ����ʾҴٸ� ��� x


}