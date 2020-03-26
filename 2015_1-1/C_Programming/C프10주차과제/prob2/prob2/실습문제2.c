/* C프로그래밍 10주차 실습 */

#include <stdio.h>

int facto(int num) //팩토리얼 함수
{
	if(num<=1)
		return 1; // 최종적으로 num값을 1씩빼주다가 1이 되었을때 1로 반환 => 함수반복 종료
	else
		return num*facto(num-1); //facto함수에 값 num+sum(num-1) 반환 = 반복
}

int main()
{
	int arr[30]={0}, tmp[30]={0}; // arr배열과 tmp 배열 모든값 0
	int i, j, k, l;
	int num;

	printf("Enter the number of lines to be printed: ");
	scanf("%d", &num); // num값 입력

	tmp[0]=1;
	arr[0]=1;

	for(i=0; i<num; i++) // 높이
	{
		arr[num-1]=1; // 배열의 순서중 높이숫자에 해당하는 값 1 
		
		for(k=(num-i); k>0; k--) // 공백입력
		{
			printf(" ");
		}
		
		for(j=0; j<=i; j++)
		{
			printf("%d ", facto(i)/(facto(j)*facto(i-j))); //적분과통계과정 조합공식을 이용
		}
		printf("\n");
	}

	return 0;
}

// nCr = n!/r!*(n-r)!