/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>

int Sum(int mA, int mB);
double Average(int mA, int mB);
char Compare(int mA, int mB); // �Լ� �̸� ����

int main(void)
{
	int a, b;

	printf("���� �� �� �Է� : ");
	scanf("%d %d", &a, &b);
	printf(">> Sum : %d\n", Sum(a, b)); // Sum �Լ� ȣ��
	printf(">> Average : %.1f\n", Average(a, b)); // Average �Լ� ȣ��
	printf(">> Compare : %d %c %d\n", a, Compare(a, b), b); // Compare �Լ� ȣ��

	return 0;
}

int Sum(int mA, int mB) // �Լ��̸��� Sum
{
	return mA+mB; // mA+mB ���� Sum�� ȣ���� �������� ����
} // sum �Լ��� ��ü

double Average(int mA, int mB)
{
	return ((double)mA+mB)/2; // �Ҽ��ڸ��� ���
}

char Compare(int mA, int mB)
{
	if((mA-mB)>0)
		return '>';
	if((mA-mB)==0) // ���� 0 �̸� ���ٴ°�
		return '=';
	if((mA-mB)<0)
		return '<';
}