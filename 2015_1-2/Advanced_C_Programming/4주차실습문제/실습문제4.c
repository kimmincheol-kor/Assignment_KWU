// C ���α׷��� 4���� �ǽ�����4

#include <stdio.h>

void swap(int ***dpA, int ***dpB);

void main()
{
	int a,b;
	int *pA, *pB;
	int **dpA, **dpB;

	pA=&a;
	pB=&b;
	dpA=&pA;
	dpB=&pB;

	// dpA -> pA -> a
	// pA�� a�� �ּҸ� ����Ű��, *pA �� �� �ּ��� ���̴�.
	// *dpA �� pA�� �ּ��̰�, **dpA�� pA�� ���̴�.

	printf("�Է�: ");
	scanf("%d %d", *dpA, *dpB); // *dpA �� pA�� �ּ��̰� pA�� a�� ����Ų��.

	swap(&dpA, &dpB); // pA�� pB�� �ּҰ��� �Լ��� ����
	
	printf("swap: %d %d\n", **dpA, **dpB); // a �� b �� ���� ���
}

void swap(int * **tpA, int ***tpB)
{
	int *temp=**tpA; // temp�� ���� dpA�� ��

	**tpA=**tpB;
	**tpB=temp; // ������ ���� �ٲ���.
}