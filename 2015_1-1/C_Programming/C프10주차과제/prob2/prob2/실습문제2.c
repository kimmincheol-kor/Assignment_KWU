/* C���α׷��� 10���� �ǽ� */

#include <stdio.h>

int facto(int num) //���丮�� �Լ�
{
	if(num<=1)
		return 1; // ���������� num���� 1�����ִٰ� 1�� �Ǿ����� 1�� ��ȯ => �Լ��ݺ� ����
	else
		return num*facto(num-1); //facto�Լ��� �� num+sum(num-1) ��ȯ = �ݺ�
}

int main()
{
	int arr[30]={0}, tmp[30]={0}; // arr�迭�� tmp �迭 ��簪 0
	int i, j, k, l;
	int num;

	printf("Enter the number of lines to be printed: ");
	scanf("%d", &num); // num�� �Է�

	tmp[0]=1;
	arr[0]=1;

	for(i=0; i<num; i++) // ����
	{
		arr[num-1]=1; // �迭�� ������ ���̼��ڿ� �ش��ϴ� �� 1 
		
		for(k=(num-i); k>0; k--) // �����Է�
		{
			printf(" ");
		}
		
		for(j=0; j<=i; j++)
		{
			printf("%d ", facto(i)/(facto(j)*facto(i-j))); //���а������� ���հ����� �̿�
		}
		printf("\n");
	}

	return 0;
}

// nCr = n!/r!*(n-r)!