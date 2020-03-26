// C프로그래밍 12주차 실습

#include <stdio.h>

void main()
{
	char str[256]={0};
	char find;
	int i=0,j;

	printf(">> 문장 입력: ");
	gets(str); //str 배열에 문장 입력

	printf(">> 검색할 단어의 첫 글자 입력: ");
	scanf("%c", &find); //find 값 입력

	printf(">> ");
	while(i<256) // 큰while
	{
		if(((str[i]==find)||(str[i]==find-32))&&((str[i-1]==' ')||(i==0))){ // str배열의 값이 find 이고, (그 전값이 공백이거나, 첫번째 글자인경우) 작은 while 실행
			while(str[i]!=' ') // 작은 while, 공백이 나오면 종료
			{
				if(str[i]==0)
					break; // 작은 while 종료
				else{
				printf("%c", str[i]); // 배열값 출력
				i++;} // 계속 i가 증가하다가 공백, 혹은 0 값이 나오면 종료 
			}
			printf("\n");
			if(str[i]==' ') // 배열값을 출력하다가 공백이 나오면 전체 반복문 종료, => 단어 하나만 출력
				break; // 큰 while 종료
		}
		else if(str[i]==0){
			printf("%c로 시작하는 단어가 없습니다\n", find);
			break;} // find 값이 하나도없으면 종료
		else{
			i++; // find 값도아니고 0도 아니면 i에 1더해서 재실행
		}
	}
}