/* C���α׷��� 10���� �ǽ� */

#include <stdio.h>

int main()
{
	int arr[5]={1,2,3,4,5};
	int a,c=sizeof(arr)/sizeof(int); // c���� arr �迭�� ũ��
	int sum=0;
	int m;

    printf("Array: ");
	for(m=0; m<c; m++)
	{
		printf("%d ", arr[m]); // arr�迭�� ��簪 ���
	}
    printf("\n");

	
	printf("Mean= ");
    for(a=0; a<c; a++)
	{
		sum+=arr[a]; // sum ���� arr�迭�� �����
	}

	printf("%.6f\n", (double)sum/(sizeof(arr)/sizeof(int))); // �Ҽ��� ������° �ڸ����� �迭�� ��簪�� ���(=����/�迭��ũ��) ���

	return 0;
}