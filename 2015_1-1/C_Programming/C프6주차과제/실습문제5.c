/* C ���α׷���
    6���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int home;

    do // do~while���� ������ ����Ȯ��
	{
		
		printf("Input : ");
		scanf("%d", &home);

	}while(home!=-1); // home�� -1�� �ƴϸ� ����ؼ� �ݺ� = home�� -1�̸� ����
	
	return 0;
}