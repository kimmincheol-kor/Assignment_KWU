// C프로그래밍 3주차 실습문제3

#include <stdio.h>

void main()
{
	int freq=0;
	char arr[32];
	char alpha;
	char *pArr;

	printf("입력: ");
	gets(arr); // arr 배열에 문장 입력.

	while(1)
	{
	printf("찾는글자<a-z>: ");
	scanf("%c", &alpha); // alpha에 찾는 글자 입력
	fflush(stdin);

	if((97<=alpha)&&(alpha<=122)) // 소문자의 아스키 코드값은 97~122
		break;
	else
		printf("찾는 글자가 잘못되었습니다.\n");
	}

	for(pArr=arr; pArr!=(arr+sizeof(arr)); pArr++) // arr배열에 입력된 문장중에 alpha의 값과 같은 게있다면 freq에 +1
		{if(*pArr==alpha)
		freq+=1;}


	printf("%c의 갯수: %d\n", alpha, freq);


}