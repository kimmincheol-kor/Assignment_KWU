/* C ���α׷���
    5���� �ǽ� */

#include <stdio.h>

int main(void) //main �Լ� 
{
	int min;
	int chul;
	double jjang; //��ö¯ ������ʱ�ȭ

	printf("ù ��° ���� �Է� : ");
	scanf("%d", &min); // �� �� �Է�
	printf("�� ��° ���� �Է� : ");
	scanf("%d", &chul); // ö �� �Է�

	jjang=(double)min/(double)chul; // ¯�� �Ǽ��� �������̹Ƿ� ����� �����ߴ�
	
	printf("%d / %d �� ������ ������ ��� : �� %d, ������ %d\n", min, chul, min/chul, min%chul);
	printf("%d / %d �� �Ǽ��� ������ ��� : %.6f", min, chul, jjang); // ��ö�� ����, ¯�� �Ҽ� 6��°�ڸ� ���� ���

	return 0;// �̰� ���� �ϳ����ȹ���.
}