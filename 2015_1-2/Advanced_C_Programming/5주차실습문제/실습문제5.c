// ���C���α׷��� �ǽ�����5

#include <stdio.h>

void main()
{
	int arr1[2][4]={
		{1,2,3,4},
		{5,6,7,8}
	};
	int arr2[4][2];
	int i,j;

	for(i=0; i<4; i++) // arr1�� ���ι�ġ�� arr2�� �Ű� ���ι�ġ�� �ٲ�
	{
		for(j=0; j<2; j++)
		{
			arr2[i][j]=arr1[j][i];
		}
	}
	

	for(i=0; i<4; i++) // arr2(���ι�ġ) ���
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}