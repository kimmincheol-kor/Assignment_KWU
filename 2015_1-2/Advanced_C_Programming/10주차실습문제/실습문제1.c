// 고급C프 10주차 실습문제1

#include <stdio.h>

typedef union rdbuf // 공용체 선언
{
	int iBuf;
	char bBuf[4];
}RDBuf;

int main(void)
{
	int i;
	RDBuf buf;
	printf("정수 입력: ");
	scanf("%d", &(buf.iBuf)); // 입력

	printf("바이트: ");
	for(i=0;i<4;i++)
	{
		printf("%u ", buf.bBuf[i]); // 바이트단위로 출력
	}
	printf("\n");


}