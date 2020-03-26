#include<stdio.h>

void find_perfect();

int main()
{
	int num;

	printf("숫자 입력: ");
	scanf("%d", &num);

	printf("완전수<1 ~ %d>: ", num);

	find_perfect(num);




}

void find_perfect(int a)
{
	int i,j,k;
	int sum=0;


	for(i=1; i<=a; i++) // 1부터 a 까지a
	{
		sum=0;

		for(j=1; j<i; j++) // 완전수인지 체크
		{
			if(i%j==0)
				sum+=j;
		}
		if(sum==i)
			printf("%d ", i);
	}
	printf("\n");
}