/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>

int Tree(char ch1, int num1) // 문자 ch1, 높이 num1
{
	int a,b,c=1,d,e,f;
	
	for(a=1; a<=num1; a++) // 높이만큼 반복.
	{
		for(d=(num1-a); d>0; d--) // 공백입력, 공백이 많았다가 작아져야하기때문에 num1-a 를하면 a가 커지므로 공백입력수가 줄어든다
		{
			printf(" ");
		}

		
		for(b=1; b<=c; b++) //문자입력
		{
			printf("%c", ch1);
		}

		printf("\n");
		c+=2; // 행이 지날수록 문자 2개씩 더 입력되어야됨
	}
}


int main()
{
	char ch;
	int num=0;

	printf("문자 입력 : ");
	scanf("%c", &ch);
	printf("높이 입력 : ");
	scanf("%d", &num);
	Tree(ch, num);

	return 0;
}

