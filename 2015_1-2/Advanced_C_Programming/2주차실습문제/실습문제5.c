// C ���α׷��� 2���� �ǽ�����5

#include <stdio.h>

void main()
{
	int num=0x12345678;
	char *b=(char *)&num;

	if(*b=0x78) // ���� �����Ͱ� 0x78�� ����Ų�ٸ� ��Ʋ 
		printf("little endian *b = %x\n", *b);
	else if(*b=0x12) // Ȥ�� ���� �����Ͱ� 0x12�� ����Ų�ٸ� ��
		printf("big endian *b = %x\n", *b);

}