/* C ���α׷���
   2���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ�
{
	int num;
	
    printf("2�� ������ ��ȣ �ٲٱ�\n");
	printf("�Է� : ");
	scanf("%d", &num); // num�� �����Է�.

	num=~num; //num�� ~����
	num=num+1; // ~����� num�� +1
	
	printf("��� : %d\n", num); // ��� ����Ʈ

	return 0;
}