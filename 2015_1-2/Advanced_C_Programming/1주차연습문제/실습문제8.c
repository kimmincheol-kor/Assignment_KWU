#include<stdio.h>

int main()
{
	int str[5];
	int i, *pMax, *pMin;

	printf("5개의 정수 입력: ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &str[i]);
	}
	pMax=&str[0];
	pMin=&str[0];
	
	for(i=0; i<5; i++)
	{
		if(str[i]>*pMax)
			pMax=&str[i];

		if(str[i]<*pMin)
			pMin=&str[i];
	}

	printf("Max: %d\n", *pMax);
	printf("Min: %d\n", *pMin);

}