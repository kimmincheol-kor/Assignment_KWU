// 고급C프로그래밍 실습문제5

#include <stdio.h>

void main()
{
	int arr1[2][4]={
		{1,2,3,4},
		{5,6,7,8}
	};
	int arr2[4][2];
	int i,j;

	for(i=0; i<4; i++) // arr1의 가로배치를 arr2로 옮겨 세로배치로 바꿈
	{
		for(j=0; j<2; j++)
		{
			arr2[i][j]=arr1[j][i];
		}
	}
	

	for(i=0; i<4; i++) // arr2(세로배치) 출력
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}