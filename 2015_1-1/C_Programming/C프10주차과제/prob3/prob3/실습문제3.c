/* C���α׷��� 10���� �ǽ� */

#include <stdio.h>

void even(int num) 
{
	int arr[10]={10, 21, 35, 46, 57, 64, 79, 82, 91, 101};

	if(arr[num]%2==0) //2�� ����̸�
		printf("%d ", arr[num]); // ���
	else
		return; // �ƴϸ� ����

}

int main()
{
	int arr[10]={10, 21, 35, 46, 57, 64, 79, 82, 91, 101}; // arr �迭�� ��� �Է�
	int a=0, b=0, c=sizeof(arr)/sizeof(int); // c���� arr �迭�� ũ��
	
	printf("even numbers: ");
	
	for(a=0; a<c; a++)
	{
		even(a); // even�Լ��� 0���� 9���� ����(=�迭�� ��簪 �Է�) -> �Լ����
	}

	printf("\n");

	return 0;
}