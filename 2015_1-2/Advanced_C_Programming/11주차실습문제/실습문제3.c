// 고급C프 11주차 실습문제3

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *num=NULL;
	int n, cnt=0;

	while(1)
	{
		printf("양의 정수를 입력하세요(종료: -1): ");
		scanf("%d", &n);

		if( n == -1 ) break;
		
		num = (int *)realloc(num, sizeof(int)*(cnt+1)); // 메모리 공간을 변경
		num[cnt]=n;
		cnt++;
	}

	for(n=0; n<cnt; n++)
	{
		printf("num[%d]: %d\n", n, num[n]);
	}

	free(num);
}