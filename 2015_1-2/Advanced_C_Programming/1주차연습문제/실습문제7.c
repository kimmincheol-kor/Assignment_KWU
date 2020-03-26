#include<stdio.h>

int main()
{
	int str[5];
	int i, max=0, min=0;

	printf("5개의 정수 입력: ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &str[i]);
	}

	min=str[0];
	
	for(i=0; i<5; i++)
	{
		if(str[i]>max)
			max=str[i];

		if(str[i]<min)
			min=str[i];
	}

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);

}