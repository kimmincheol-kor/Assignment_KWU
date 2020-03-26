// C 프로그래밍 4주차 실습문제5

#include <stdio.h>

int main()
{
	int num[3][3]={
		{ 7,9,2 },
		{ 3,1,8 },
		{ 6,5,4 } };
	int i,j,k,l;
	int temp;

	for(k=0;k<100;k++) // 여유있게 100번 반복 100번 반복하면 숫자가 아무리 꼬여있어도 다 바뀜
	{
		for(i=0;i<3;i++) // 
		{
			for(j=0;j<3;j++) // 작은 숫자가 앞에 오도록 이동
			{
				if(num[i][0]>num[i][1]){ // 앞에 수가 더 크면 바꿈
					temp=num[i][0];
					num[i][0]=num[i][1];
					num[i][1]=temp;
				}
				if(num[i][1]>num[i][2]){
					temp=num[i][1];
					num[i][1]=num[i][2];
					num[i][2]=temp;
				}
				if(num[i][0]>num[i][1]){
					temp=num[i][0];
					num[i][0]=num[i][1];
					num[i][1]=temp;
				}

			}
			if(num[0][2]>num[1][0]){ // 첫줄 맨뒤의 숫자가, 두번째줄 첫번째 숫자보다 크면 두 숫자를 바꿈.
					temp=num[0][2];
					num[0][2]=num[1][0];
					num[1][0]=temp;
			}
			if(num[1][2]>num[2][0]){ // 두번째 줄 맨뒤의 숫자가, 세번째줄 첫번째 숫자보다 크면 두 숫자를 바꿈.
					temp=num[1][2];
					num[1][2]=num[2][0];
					num[2][0]=temp;
			}

		}
	}

	printf("2D array sort\n");

	for(l=0;l<3;l++) // 행
	{
		for(k=0;k<3;k++) // 열
		{
			printf("%d ", num[l][k]);
		}
		printf("\n");
	}
}