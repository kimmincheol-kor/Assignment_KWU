#include <stdio.h>

void sum(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // ����
{
	int sz1, sz2;
	int i,j;

	while(1)
	{
		printf("���2 ũ��<2~10>: ");
		scanf("%d%d", &sz1, &sz2);
		fflush(stdin);
	if( sz1<2 || sz1>10 || sz2<2 || sz2>10 )
		printf("����� ũ�Ⱑ �߸��Ǿ����ϴ�.\n");
	else
		break;
	}
	
	

	printf("���2 �Է�: \n");
		for(i=0; i<sz1; i++) // ���2 �Է�
		{
			for(j=0; j<sz2; j++)
			{
				scanf("%lf", &hang2[i][j]);
			}
		}

	if( sz1!=size1 || sz2!=size2 )
		{
		printf("�� ����� ũ�Ⱑ �ٸ��ϴ�.\n");
		return;
		}

	printf("��� ���� ���\n");
		for(i=0; i<sz1; i++) // ���2 �Է�
		{
			for(j=0; j<sz2; j++)
			{
				printf("%8.2f ", hang1[i][j]+hang2[i][j]);
			}
			printf("\n");
		}


}

void sub(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // ����
{
	int sz1, sz2;
	int i,j;
	while(1)
	{
		printf("���2 ũ��<2~10>: ");
		scanf("%d%d", &sz1, &sz2);
		fflush(stdin);
	if( sz1<2 || sz1>10 || sz2<2 || sz2>10 )
		printf("����� ũ�Ⱑ �߸��Ǿ����ϴ�.\n");
	else
		break;
	}
	

	printf("���2 �Է�: \n");
		for(i=0; i<sz1; i++) // ���2 �Է�
		{
			for(j=0; j<sz2; j++)
			{
				scanf("%lf", &hang2[i][j]);
			}
		}

	if( sz1!=size1 || sz2!=size2 )
		{
		printf("�� ����� ũ�Ⱑ �ٸ��ϴ�.\n");
		return;
		}

	printf("��� ���� ���\n");
		for(i=0; i<sz1; i++) // ���2 �Է�
		{
			for(j=0; j<sz2; j++)
			{
				printf("%8.2f ", hang1[i][j]-hang2[i][j]);
			}
			printf("\n");
		}


}

void mul(double (*hang1)[10], double (*hang2)[10], int size1, int size2)
{
	int a,b,c;
	double sum=0;

	int sz1, sz2;
	int i,j;

	printf("���2 ũ��<2~10>: ");
	scanf("%d%d", &sz1, &sz2);
	fflush(stdin);
	if( size2!=sz1 ){
		printf("������ �� ���� ���Դϴ�.\n");
		return;
	}
	
	else
	{
	printf("���2 �Է�: \n");
	for(i=0; i<sz1; i++) // ���2 �Է�
	{
		for(j=0; j<sz2; j++)
		{
			scanf("%lf", &hang2[i][j]);
		}
	}

	printf("���� ���\n");
	for(a=0; a<sz2; a++) // ������
		{
				for(b=0; b<size1; b++) // �����
				{
					sum=0; // sum�� �ʱ�ȭ
						for(c=0; c<size2; c++) // �ϳ�����
						{
							sum+=hang1[a][c]*hang2[c][b]; // 3x3 ����� ������ 3���� ���Ѱ��� ������ߵ� �װ� = sum
						}
					printf("%8.2f ", sum); // ���������� �� 3������ ���Ѱ� sum ���
				}
			printf("\n");
		}
	} // if�� ����

}

void rev(double (*hang1)[10], double (*hang2)[10], int size1, int size2) // // ��İ���
{
	double temp;
	double revn;
	int i,j;
	
	if( size1==2 && size2==2 )
	{
		revn=hang1[0][0]*hang1[1][1]-hang1[0][1]*hang1[1][0];
		hang2[0][0]=hang1[1][1]/revn; hang2[0][1]=-hang1[0][1]/revn;
		hang2[1][0]=-hang1[1][0]/revn; hang2[1][1]=hang1[0][0]/revn;

		printf("����� ���\n");
		for(i=0; i<2; i++) // ���2 �Է�
		{
			for(j=0; j<2; j++)
			{
				printf("%8.2f ", hang2[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("2x2 ����� �ƴմϴ�.\n");
	}

}

void trans(double (*hang1)[10], double (*hang2)[10], int size1, int size2) //��ġ���
{
	double temp;
	int i,j;

	printf("��ġ[ ���\n");
	for(i=0; i<size2; i++)
	{
		for(j=0; j<size1; j++)
		{
			temp=hang1[j][i];
			hang2[i][j]=temp;
			printf("%8.2f ", hang2[i][j]);
		}
		printf("\n");
	}
}


void main()
{
	double hang1[10][10];
	double hang2[10][10];
	int what;
	int size1, size2;
	int i,j,k;

	while(1) // ��ü while
	{
		while(1) // ũ���Է� while
		{
			printf("���1 ũ��<2~10>: ");
			scanf("%d%d", &size1, &size2);
			fflush(stdin);
			if( size1<2 || size1>10 || size2<2 || size2>10 )
				printf("����� ũ�Ⱑ �߸��Ǿ����ϴ�.\n");
			else
				break;
		}

		printf("���1 �Է�: \n");
		for(i=0; i<size1; i++) // ���1 �Է�
		{
			for(j=0; j<size2; j++)
			{
				scanf("%lf", &hang1[i][j]);
			}
		}
		

		while(1) // ���� �Է�.
		{
		printf("����<1:����, 2:����, 3:����, 4:�����, 5:��ġ���>: ");
		scanf("%d", &what);

		if(what>5 || what<1)
			{
			printf("�߸��� �����Դϴ�.\n");
			continue;
			}
		
		else
			{
		switch(what)
			{

			printf("����<1:����, 2:����, 3:����, 4:�����, 5:��ġ���>: ");
			scanf("%d", &what);

			case 1: // ����
				sum(hang1, hang2, size1, size2);
				break;
	
			case 2: // ����
				sub(hang1, hang2, size1, size2);
				break;
	
			case 3: // ����
				mul(hang1, hang2, size1, size2);
				break;
	
			case 4: // �����
				rev(hang1, hang2, size1, size2);
				break;

			case 5: // ��ġ���
				trans(hang1, hang2, size1, size2);
				break;

			default: // ���Ͼ���.
				break;
			
			} // ���� switch �� ����
			
			break;

			} // else �� ����
		


		} // ���� while �� ����
	} // ��ü while ����
} // ���� �Լ� ����