/* C ���α׷���
   4���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	char ch1; // 1����Ʈ ũ���� char
	
	printf("���ĺ� �ҹ��� �Է� : "); 
	scanf("%c",&ch1); // ch1 �� �ҹ��� �Է�
	
	printf("�빮�ڷ� ��ȯ : %c\n",ch1-32); // �ҹ��ڸ� �Է��� ch1���� 32�� ���� �빮�� ���(��ҹ��� ���� 32)

	return 0;
}