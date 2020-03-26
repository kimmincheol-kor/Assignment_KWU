// ���C���α׷��� �ǽ�����4

#include <stdio.h>

void bin(int n);
void oct(int n);
void hex(int n);

void main()
{
	int n;

	printf("�Է�<0~65535>: ");
	scanf("%d", &n);

	if( n<0 || n>65535 ){
		printf("�Է��� �߸��Ǿ����ϴ�.\n");
		return;
	}

	bin(n);
	printf("\n");
	oct(n);
	printf("\n");
	hex(n);
	printf("\n");
}


void bin(int n) // 2����.
{
	int mg, i;
	int twojs[16]={0,};
	
	for(i=0; i<16; i++) // 2������ �����
	{
		mg=n%2;
		twojs[i]=mg;
		n=n/2;
	}
	
	printf("2����: ");

	for(i=1; i<17; i++) // ���
	{
		printf("%d", twojs[16-i]);

		if(i%4==0)
			printf(" ");
	}
	
}

void oct(int n) // 8����
{
	int mg, i;
	int eightjs[6]={0,};
	
	for(i=0; i<6; i++) // 8������ �����
	{
		mg=n%8;
		eightjs[i]=mg;
		n=n/8;
	}

	printf("8����: ");
	
	for(i=0; i<6; i++) // ���
	{
		printf("%d", eightjs[5-i]);
	}
	
}

void hex(int n) // 16����
{
	int mg, i;
	int sixtjs[4]={0,};
	
	for(i=0; i<4; i++) // 16������ �����
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

	printf("16����: ");
	
	for(i=0; i<4; i++) // ���
	{
		if(sixtjs[3-i]<10)
			printf("%d", sixtjs[3-i]); // 0~9 ������ �������·� ���
		else if(sixtjs[3-i]>=10)
			printf("%c", sixtjs[3-i]); // 10���ʹ� ���ĺ��̹Ƿ� �������·� ���
	}
}