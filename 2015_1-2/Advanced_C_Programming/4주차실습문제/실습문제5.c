// C ���α׷��� 4���� �ǽ�����5

#include <stdio.h>

int main()
{
	int num[3][3]={
		{ 7,9,2 },
		{ 3,1,8 },
		{ 6,5,4 } };
	int i,j,k,l;
	int temp;

	for(k=0;k<100;k++) // �����ְ� 100�� �ݺ� 100�� �ݺ��ϸ� ���ڰ� �ƹ��� �����־ �� �ٲ�
	{
		for(i=0;i<3;i++) // 
		{
			for(j=0;j<3;j++) // ���� ���ڰ� �տ� ������ �̵�
			{
				if(num[i][0]>num[i][1]){ // �տ� ���� �� ũ�� �ٲ�
					temp=num[i][0];
					num[i][0]=num[i][1];
					num[i][1]=temp;
				}
				if(num[i][1]>num[i][2]){
					temp=num[i][1];
					num[i][1]=num[i][2];
					num[i][2]=temp;
				}
				if(num[i][0]>num[i][1]){
					temp=num[i][0];
					num[i][0]=num[i][1];
					num[i][1]=temp;
				}

			}
			if(num[0][2]>num[1][0]){ // ù�� �ǵ��� ���ڰ�, �ι�°�� ù��° ���ں��� ũ�� �� ���ڸ� �ٲ�.
					temp=num[0][2];
					num[0][2]=num[1][0];
					num[1][0]=temp;
			}
			if(num[1][2]>num[2][0]){ // �ι�° �� �ǵ��� ���ڰ�, ����°�� ù��° ���ں��� ũ�� �� ���ڸ� �ٲ�.
					temp=num[1][2];
					num[1][2]=num[2][0];
					num[2][0]=temp;
			}

		}
	}

	printf("2D array sort\n");

	for(l=0;l<3;l++) // ��
	{
		for(k=0;k<3;k++) // ��
		{
			printf("%d ", num[l][k]);
		}
		printf("\n");
	}
}