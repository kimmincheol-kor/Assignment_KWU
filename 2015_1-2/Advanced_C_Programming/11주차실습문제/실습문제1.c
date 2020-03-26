// 고급C프 11주차 실습문제1

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *pi;
	int i, n;

	printf("크기: ");
	scanf("%d", &n);

	pi=(int *)malloc(sizeof(int)*n); // 메모리 공간 할당
	for(i=0; i<n; i++)
	{
		*(pi+i)=i;
		printf("*(pi+%d): %d\n", i, *(pi+i));
	}

	free(pi);
}