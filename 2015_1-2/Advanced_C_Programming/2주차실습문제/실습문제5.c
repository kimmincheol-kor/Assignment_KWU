// C 프로그래밍 2주차 실습문제5

#include <stdio.h>

void main()
{
	int num=0x12345678;
	char *b=(char *)&num;

	if(*b=0x78) // 만약 포인터가 0x78을 가리킨다면 리틀 
		printf("little endian *b = %x\n", *b);
	else if(*b=0x12) // 혹은 만약 포인터가 0x12를 가리킨다면 빅
		printf("big endian *b = %x\n", *b);

}