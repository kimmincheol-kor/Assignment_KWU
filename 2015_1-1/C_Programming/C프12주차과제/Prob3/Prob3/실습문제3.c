// C���α׷��� 12���� �ǽ�

#include <stdio.h>
#include <Windows.h>

void slowp(char *str) // �迭�� �ּ� ���Է�
{
	if(*str==0) // 0�̸� ����
		return;
	else{
	Sleep(100); // 0.1�� ����
	printf("%c", *str);} // �迭�� ���
}

void main()
{
	char str[256]={0};
	int i,k;

	printf(">> ���� �Է�: ");
	gets(str);

	printf(">> ���: ");
	for(i=0; i<256; i++)
	{
	slowp(&str[i]); // slowp �Լ� ȣ��, ��� �迭�� �Է�
	}

	printf("\n");

}