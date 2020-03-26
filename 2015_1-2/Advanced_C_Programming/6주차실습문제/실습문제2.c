// 고급C프 6주차 실습문제2

#include <stdio.h>

int main(int a, char *text[])
{
	// a 는 전달된 인자의 수

	int i=0;
	printf("전달된 인자의 수: %d \n", a-1);

	for(i=1; i<a; i++)
		printf("%d번째 인자: %s \n", i, text[i]);

	return 0;
}