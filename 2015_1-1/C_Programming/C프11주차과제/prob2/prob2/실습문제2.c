/* C프로그래밍 11주차 실습문제 */

#include <stdio.h>

int main()
{
	int num[10]={0};
	int i;
	int *pMax=NULL;
	int *pMin=NULL;

	printf("Input: ");

	for(i=0; i<10; i++)
	{
		scanf("%d", &num[i]); // num 배열 0번부터 9번까지 입력.
	}
	
	pMax=&num[0];
	pMin=&num[0]; // 최대값과 최소값 주소는 num[0]의 주소로 입력

	for(i=0; i<10; i++) //배열 num 에서 Max와 Min울 찾아낸다
	{
		if(num[i]>*pMax)
			pMax=&num[i];
		else if(num[i]<*pMin)
		    pMin=&num[i];
    }

	printf("Max: %d\n", *pMax);
	printf("Min: %d\n", *pMin);

	return 0;
}