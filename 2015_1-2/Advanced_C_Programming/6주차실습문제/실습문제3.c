// ���C�� 6���� �ǽ�����3

#include <stdio.h>
#include <string.h>

void main()
{
	char text1[50];
	char text2[50];
	char space[1]={' '};

	printf("���ڿ�1: ");
	gets(text1);

	printf("���ڿ�2: ");
	gets(text2);

	strncat(text1, space, 1); // ���� �߰�
	strcat(text1, text2); // text1 text2

	printf("���ڿ�1 + ���ڿ�2: %s\n", text1);
}