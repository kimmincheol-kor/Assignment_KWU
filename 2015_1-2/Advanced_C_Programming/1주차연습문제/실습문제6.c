#include<stdio.h>

void find_perfect();

int main()
{
	int num;

	printf("���� �Է�: ");
	scanf("%d", &num);

	printf("������<1 ~ %d>: ", num);

	find_perfect(num);




}

void find_perfect(int a)
{
	int i,j,k;
	int sum=0;


	for(i=1; i<=a; i++) // 1���� a ����a
	{
		sum=0;

		for(j=1; j<i; j++) // ���������� üũ
		{
			if(i%j==0)
				sum+=j;
		}
		if(sum==i)
			printf("%d ", i);
	}
	printf("\n");
}