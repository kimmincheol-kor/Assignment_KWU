// ���C�� 10���� �ǽ�����1

#include <stdio.h>

typedef union rdbuf // ����ü ����
{
	int iBuf;
	char bBuf[4];
}RDBuf;

int main(void)
{
	int i;
	RDBuf buf;
	printf("���� �Է�: ");
	scanf("%d", &(buf.iBuf)); // �Է�

	printf("����Ʈ: ");
	for(i=0;i<4;i++)
	{
		printf("%u ", buf.bBuf[i]); // ����Ʈ������ ���
	}
	printf("\n");


}