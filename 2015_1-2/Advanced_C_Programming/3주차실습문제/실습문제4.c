// C���α׷��� 3���� �ǽ�����4

#include <stdio.h>

void main()
{
	int arr[5];
	int i;
	int *pArr;
	int sum=0;

	printf("�Է�: ");
	for(i=0; i<sizeof(arr)/sizeof(int); i++)
	{
		scanf("%d", &arr[i]); // arr�迭�� �ϳ��� �Է�
		pArr=arr+i; // pArr �� arr[i]��° �ּҸ� ����Ŵ
		sum+=(*pArr); //sum ���� pArr�� ����Ű�� ��= arr�迭�� �� �� ����
	}

	printf("��: %d\n", sum);

}