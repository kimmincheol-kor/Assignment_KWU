// C프로그래밍 12주차 실습

#include <stdio.h>

void counting(char *str, char count, int *sum) // 카운팅함수에서는 3개의 숫자가 입력된다, 배열의주소값, 카운트값, 썸값의주소값
{
	if(*str==count)
		*sum+=1;
	else if(*str==0){
		printf("%d", *sum);
		return;}
}


void main()
{
	char str[256]={0};
	char count;
	int i,j,k,sum=0;

	printf(">> 문장 입력: ");
	gets(str); // str 배열에 문장입력

	printf(">> 카운트할 문자 입력: ");
	scanf("%c", &count); // count 입력
	
	printf(">> 문자 <%c> count = ", count);
	for(i=0; i<256; i++)
	{
		counting(&str[i],count,&sum); // 카운팅함수 호출

		if(str[i]==0) // 배열값이 0 이면 반복종료
			break;
	}
	printf("\n");
}