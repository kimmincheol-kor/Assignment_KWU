// 고급C프 6주차 실습문제5


#include <stdio.h>
#include <string.h>

void main()
{
	char arr[5][2][32]={
		{"apple", "사과"},
		{"grape", "포도"},
		{"banana", "바나나"},
		{"orange", "오렌지"},
		{"lemon", "레몬"} };
	char str[32];
	int i;

	while(1)
	{
		printf("입력<종료:exit>: ");
		gets(str); // 입력받음
		fflush(stdin);

		if((strncmp(str, "exit", 4))==0) // 입력받은게 exit 라면
			break; // while문 탈출

		for(i=0; i<5; i++)
		{
			if((strncmp(str, arr[i][1], 32))==0)
			{
				printf("%s: %s\n", arr[i][1], arr[i][0]);
				break;
			}
			
			if( ( (strncmp(str,arr[4][1],32) ) != 0 ) && (i==4) ) // 입력한 단어가 사과,포도,바나나,오렌지,레몬중에 없다면,
				printf("없는 단어입니다.\n");
		}
	}
}