// C���α׷��� 3���� �ǽ�����2

#include <stdio.h>

void main()
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int *pArr;

	for(pArr=arr; pArr!=(arr+10); pArr++) //pArr�� arr�迭�� ù��°ĭ�� �ּҸ� ����Ų��. �׷��Ƿ� pArr++ �� ������ �������� �迭�� ����ĭ�� ����Ų��.
		printf("%d ", *pArr);
	printf("\n");
}