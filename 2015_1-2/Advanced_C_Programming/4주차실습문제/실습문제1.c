// C ���α׷��� 4���� �ǽ�����1

#include <stdio.h>

void main()
{
	int num=5;
	int *pNum;
	int **dpNum;

	pNum=&num; // pNum�� num�� �ּҰ��� ����Ų��.
	dpNum=&pNum; // dpNum�� pNum�� �ּҰ��� ����Ų��.
	       
	printf("num addr: %p\n", *dpNum);
	printf("pNum addr: %p\n", dpNum);
	printf("dpNum addr: %p\n", &dpNum);
	printf("num: %d\n", **dpNum);

	printf("num addr: %p\n", &num);
	printf("pNum addr: %p\n", &pNum);
	printf("dpNum addr: %p\n", &dpNum);
}