// C프로그래밍 12주차 실습

#include <stdio.h>
#include <Windows.h>

void slowp(char *str) // 배열의 주소 값입력
{
	if(*str==0) // 0이면 종료
		return;
	else{
	Sleep(100); // 0.1초 지연
	printf("%c", *str);} // 배열값 출력
}

void main()
{
	char str[256]={0};
	int i,k;

	printf(">> 문장 입력: ");
	gets(str);

	printf(">> 결과: ");
	for(i=0; i<256; i++)
	{
	slowp(&str[i]); // slowp 함수 호출, 모든 배열값 입력
	}

	printf("\n");

}