// 고급C프로그래밍 실습문제4

#include <stdio.h>

void bin(int n);
void oct(int n);
void hex(int n);

void main()
{
	int n;

	printf("입력<0~65535>: ");
	scanf("%d", &n);

	if( n<0 || n>65535 ){
		printf("입력이 잘못되었습니다.\n");
		return;
	}

	bin(n);
	printf("\n");
	oct(n);
	printf("\n");
	hex(n);
	printf("\n");
}


void bin(int n) // 2진수.
{
	int mg, i;
	int twojs[16]={0,};
	
	for(i=0; i<16; i++) // 2진수로 만들기
	{
		mg=n%2;
		twojs[i]=mg;
		n=n/2;
	}
	
	printf("2진수: ");

	for(i=1; i<17; i++) // 출력
	{
		printf("%d", twojs[16-i]);

		if(i%4==0)
			printf(" ");
	}
	
}

void oct(int n) // 8진수
{
	int mg, i;
	int eightjs[6]={0,};
	
	for(i=0; i<6; i++) // 8진수로 만들기
	{
		mg=n%8;
		eightjs[i]=mg;
		n=n/8;
	}

	printf("8진수: ");
	
	for(i=0; i<6; i++) // 출력
	{
		printf("%d", eightjs[5-i]);
	}
	
}

void hex(int n) // 16진수
{
	int mg, i;
	int sixtjs[4]={0,};
	
	for(i=0; i<4; i++) // 16진수로 만들기
	{
		mg=n%16;

		if(mg==10)
			mg='A';
		if(mg==11)
			mg='B';
		if(mg==12)
			mg='C';
		if(mg==13)
			mg='D';
		if(mg==14)
			mg='E';
		if(mg==15)
			mg='F';
		
		sixtjs[i]=mg;
		n=n/16;
	}

	printf("16진수: ");
	
	for(i=0; i<4; i++) // 출력
	{
		if(sixtjs[3-i]<10)
			printf("%d", sixtjs[3-i]); // 0~9 까지는 정수형태로 출력
		else if(sixtjs[3-i]>=10)
			printf("%c", sixtjs[3-i]); // 10부터는 알파벳이므로 문자형태로 출력
	}
}