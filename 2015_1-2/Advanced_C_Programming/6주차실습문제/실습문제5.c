// ���C�� 6���� �ǽ�����5


#include <stdio.h>
#include <string.h>

void main()
{
	char arr[5][2][32]={
		{"apple", "���"},
		{"grape", "����"},
		{"banana", "�ٳ���"},
		{"orange", "������"},
		{"lemon", "����"} };
	char str[32];
	int i;

	while(1)
	{
		printf("�Է�<����:exit>: ");
		gets(str); // �Է¹���
		fflush(stdin);

		if((strncmp(str, "exit", 4))==0) // �Է¹����� exit ���
			break; // while�� Ż��

		for(i=0; i<5; i++)
		{
			if((strncmp(str, arr[i][1], 32))==0)
			{
				printf("%s: %s\n", arr[i][1], arr[i][0]);
				break;
			}
			
			if( ( (strncmp(str,arr[4][1],32) ) != 0 ) && (i==4) ) // �Է��� �ܾ ���,����,�ٳ���,������,�����߿� ���ٸ�,
				printf("���� �ܾ��Դϴ�.\n");
		}
	}
}