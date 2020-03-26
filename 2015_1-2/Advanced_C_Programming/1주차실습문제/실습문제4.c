// C프로그래밍 1주차 실습문제4

#include<stdio.h>

int swap(); // swap 함수 선언

int main()
{
	char str[256]={0};
	int i,j,last, temp;

	printf("입력: ");
	gets(str);

	for(i=0; i<256; i++) // 글자가 몇글자 인지 찾기.
	{
		if(str[i]==0){
			last=i; // 총 글자수 = last
			break;}
	}

	if(last%2==0) // 글자수가 짝수이면
		for(i=0; i<last/2; i++)
		{
			temp=str[last-1-i];
			str[last-1-i]=str[i];
			str[i]=temp;
		}
	if(last%2!=0) // 글자수가 홀수이면 가운데 글자는 그대로!
		for(i=0; i<last/2; i++)
		{
			if(i!=last/2+1)
			   {temp=str[last-1-i];
				str[last-1-i]=str[i];
				str[i]=temp;}
		}

	
	printf("결과: ");
	for(i=0; i<256; i++)
	{
		printf("%c", str[i]); // 배열값 출력

		if(str[i]==0)
			break;
	}
	printf("\n");
}