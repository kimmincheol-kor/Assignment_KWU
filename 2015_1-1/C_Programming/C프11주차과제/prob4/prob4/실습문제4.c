/* C���α׷��� 11���� �ǽ����� */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, ranNum, num=0;

	srand((unsigned)time(NULL)); // �Էµ� �� ���� ������ �������� �ִµ�, time ���� �������ν� ����ؼ� �������� �ٲ�Ƿ� ��¥������(?) �̵ȴ�.
	ranNum=rand()%10+1; // ranNum���� 1,2,3...9,10 �߿��� �����ȴ�, 10���� ���� �������� ���ڸ� ��(0~9)�̸�, 1�� ���ϸ� 1~10�� �ȴ�.

	do // �ϴ� ����
	{
		printf("Input <1~10>: ");
		scanf("%d", &num); //num�� �Է�

		if(num>ranNum)
			printf("random number�� %d���� �۽��ϴ�.\n", num);
		else if(num<ranNum)
			printf("random number�� %d���� Ů�ϴ�.\n", num);
		else if(num=ranNum)
			printf("random number�� %d�Դϴ�.\n", num);
	} while(num!=ranNum); // num�� ranNum �� ������ ����

		printf("\n");

		return 0;
}