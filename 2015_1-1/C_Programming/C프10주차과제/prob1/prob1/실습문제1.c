/* C ���α׷��� 10���� �ǽ� */

#include <stdio.h>

int main()
{
	int i,a;
	int arr[4]={10,20,30,40};
	int size=sizeof(arr)/sizeof(int); // size ���� arr�迭�� ũ��


	printf("Original numbers: ");
	for(i=0; i<size; i++) 
	{
		printf("%d ", arr[i]); // �迭�� ��簪 ���
	}
	printf("\n");

	printf("Nuew numbers: ");
	for(a=0; a<size; a++)
	{
		printf("%d ", ++arr[a]); // arr �迭�� ��簪�� +1 �ؼ� ���
	}
	printf("\n");

	return 0;
}