  /* C ���α׷���
   7���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int usa;
	int best=0;

    while(1) //break ���ö����� ���� �ݺ�
	{
		printf("���� ���� �Է� : ");
		scanf("%d", &usa); //usa�� �Է�

		if(usa<0)
			{continue;} // usa�� �����̸� �ٽ� while�� ����
		
		best+=usa; // best = best + usa

		if(usa==0)
			{printf("����");
		     printf("\n");
				break;} // usa�� 0 �̸� ����

		printf("���� �� : %d\n", best);
	}
}