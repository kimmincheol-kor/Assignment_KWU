/* C ���α׷���
   7���� �ǽ� */

#include <stdio.h>

int main(void)
{
	char one;

	printf("���ĺ� �Է�: ");
	scanf("%c", &one); //one �� �Է�

	if(one<='Z'&&one>='A') // one�� ũ�Ⱑ A����ũ�� Z�����۴ٸ� = one�� �빮�ڶ�� ����
	    {one+=' '; // ������ �ƽ�Ű�ڵ�ǥ���� 32 �� �ش�
	     printf("��ҹ��� ���� : %c \n", one);}
	else // one�� �빮�ڰ� �ƴ϶��
		if(one>='a'&&one<='z') // one�� �ҹ��� ��� ����
			{one-=' ';
	         printf("��ҹ��� ���� : %c \n", one);}
		else // one�� �ҹ��ڰ� �ƴ϶�� ���� = �빮�ڵ� �ƴϰ�, �ҹ��ڵ� �ƴϴ� = ���ĺ��� �ƴϴ�
			printf("��ҹ��� ���� : ���ĺ��� �ƴմϴ�\n");

     return 0;
}