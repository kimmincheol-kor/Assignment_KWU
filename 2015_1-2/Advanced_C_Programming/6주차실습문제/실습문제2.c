// ���C�� 6���� �ǽ�����2

#include <stdio.h>

int main(int a, char *text[])
{
	// a �� ���޵� ������ ��

	int i=0;
	printf("���޵� ������ ��: %d \n", a-1);

	for(i=1; i<a; i++)
		printf("%d��° ����: %s \n", i, text[i]);

	return 0;
}