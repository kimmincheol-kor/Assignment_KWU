// ���C�� 6���� �ǽ�����1

#include <stdio.h>

int sum(int a, int b){
	return a+b;
}

void main()
{
	int a=10, b=20;

	int(*fptr)(int,int)=sum; // fptr �� sum �Լ��� ����Ŵ
	printf("%d + %d = %d\n", a, b, fptr(a,b));
}