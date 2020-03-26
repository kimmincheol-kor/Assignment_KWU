// 고급C프 6주차 실습문제4

#include <stdio.h>
#include <string.h>
int atoi(char str[]);

void main()
{
	char str[32]; // 연산입력
	int i;
	char op=0; // 기호

	printf("연산입력: ");
	gets(str);

	for(i=0; i<32; i++)
	{
		if(str[i]==NULL) // 입력받지않은 배열칸은 NULL 이므로 종료
			break;
		
		if( (str[i]=='+') || (str[i]=='-') || (str[i]=='/') || (str[i]=='*') ) // 배열값이 사칙연산자라면,
		{
			if(op!=0){ // op에 어떤값이 입력되었다면
				printf("잘못된 연산자입니다.\n");
				op='1'; // 오류가 있다면 op='1'
				break;}
			else
				op=str[i];
		}
		
		if( str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && ( str[i]>'9' || str[i]<'0' ) ) // 배열값이 사칙연산자도 아니고, 숫자도 아니라면
		{
			printf("잘못된 연산자입니다.\n");
			op='1'; // 오류가 있다면 op='1'
			break;
		}
	}

	if(op==0) // 오류가없으면서, op에 아무값이 입력되지않았다면,
		printf("연산자가 없습니다.\n");


	// 연산
	if(op!='1') // 오류가 없다면
	{
		for(i=0; i<32; i++) // 오류가없고, 연산자도 사칙연산이므로
		{
			if(str[i]==op)
				break;
		} // 연산자가 배열 몇번째 칸에 있는지 i 에 저장

		if(str[0]==op || str[i+1]==NULL)
			printf("잘못된 연산입니다.\n"); 
		else
		{
		if(op=='+')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)+atoi(str+i+1));
		if(op=='-')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)-atoi(str+i+1));
		if(op=='/')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)/atoi(str+i+1));
		if(op=='*')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)*atoi(str+i+1));
		}
	}
}