// ���C���α׷��� �ǽ�����1

#include <stdio.h>

void main()
{
	int arr[2][2]={ {1,2}, {3,4} };
	int (*ptr)[2];
	int i;

	ptr=arr; // ptr�� arr�� ����Ŵ

	for(i=0; i<2; i++) { // ptr �� ��� = arr �� ���
		printf("%d %d\n", ptr[i][0], ptr[i][1]); 
	}
}