/* C프로그래밍 11주차 실습 */

#include <stdio.h>

int Tree(int num)// 높이 num
{
	int a,b,c=1,d,e,f;
	
	for(a=1; a<=num; a++) // 높이만큼 반복.
	{
		for(d=(num-a); d>0; d--) // 공백입력, 공백이 많았다가 작아져야하기때문에 num1-a 를하면 a가 커지므로 공백입력수가 줄어든다
		{
			printf(" ");
		}

		
		for(b=1; b<=c; b++) //문자입력
		{
			printf("* ");
		}

		printf("\n");
		c++;// 행이 지날수록 문자 1개씩 더 입력되어야됨
	}
}

int main()
{
	int height;
	int i,j,k;

	printf("높이 입력: ");
	scanf("%d", &height);

	Tree(height);

	return 0;
}