/* C���α׷��� 11���� �ǽ� */

#include <stdio.h>

void main()
{
	char ch='A';
	int n1=10;
	double n2=2.6;

	char *pCh=&ch;
	int *pN1=&n1;
	double *pN2=&n2; // ������ ������ ����� ���ÿ� �ǿ����� n2�� �ּҰ��� ��ȯ

	printf("ch�� �� : %c\t�ּ� : %p\n", ch, &ch);
	printf("n1�� �� : %d\t�ּ� : %p\n", n1, &n1);
	printf("n2�� �� : %.1f\t�ּ� : %p\n\n", n2, &n2); //�Ҽ��� 1�ڸ����� n2 ���, n2�� �ּҰ� ��� (%p�� �������� �ּҰ��� ����ϴ� ���Ĺ����̴�.)

	printf("pCh�� �� : %c\t����Ű�� ���� �� : %c\n", pCh, *pCh); //*pCh=&ch ���� *pCh�� �ּҰ��̰� pCh�� �������̴�.
	printf("pN1�� �� : %p\t����Ű�� ���� �� : %d\n", pN1, *pN1);
	printf("pN2�� �� : %p\t����Ű�� ���� �� : %.1f\n\n", pN2, *pN2);

	ch='B'; //*pCh�� �ּҰ��ε� �װ��� ������ �Է�, ch�� �ּҰ��� �������� ����.	
	*pN1=27;
	*pN2=1.5;

	printf("ch�� �� : %c\t�ּ� : %p\n", *pCh, pCh); // ch�� �ִ� �ּҿ� ���ο� ������ �ԷµǾ� B ���, ���ο� �ּ� ���
	printf("n1�� �� : %d\t�ּ� : %d\n", n1, &n1);
	printf("n2�� �� : %.1f\t�ּ� : %d\n\n", n2, &n2);

	return;
}