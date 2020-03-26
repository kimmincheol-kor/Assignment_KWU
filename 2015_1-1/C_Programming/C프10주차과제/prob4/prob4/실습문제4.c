/* C프로그래밍 10주차 실습 */

#include <stdio.h>

int main()
{
	int arr[5]={1,2,3,4,5};
	int a,c=sizeof(arr)/sizeof(int); // c값은 arr 배열의 크기
	int sum=0;
	int m;

    printf("Array: ");
	for(m=0; m<c; m++)
	{
		printf("%d ", arr[m]); // arr배열의 모든값 출력
	}
    printf("\n");

	
	printf("Mean= ");
    for(a=0; a<c; a++)
	{
		sum+=arr[a]; // sum 값은 arr배열의 모든합
	}

	printf("%.6f\n", (double)sum/(sizeof(arr)/sizeof(int))); // 소수점 여섯번째 자리까지 배열의 모든값의 평균(=총합/배열의크기) 출력

	return 0;
}