/* C 프로그래밍 10주차 실습 */

#include <stdio.h>

int main()
{
	int i,a;
	int arr[4]={10,20,30,40};
	int size=sizeof(arr)/sizeof(int); // size 값은 arr배열의 크기


	printf("Original numbers: ");
	for(i=0; i<size; i++) 
	{
		printf("%d ", arr[i]); // 배열의 모든값 출력
	}
	printf("\n");

	printf("Nuew numbers: ");
	for(a=0; a<size; a++)
	{
		printf("%d ", ++arr[a]); // arr 배열의 모든값에 +1 해서 출력
	}
	printf("\n");

	return 0;
}