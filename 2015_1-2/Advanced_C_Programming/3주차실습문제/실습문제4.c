// C프로그래밍 3주차 실습문제4

#include <stdio.h>

void main()
{
	int arr[5];
	int i;
	int *pArr;
	int sum=0;

	printf("입력: ");
	for(i=0; i<sizeof(arr)/sizeof(int); i++)
	{
		scanf("%d", &arr[i]); // arr배열에 하나씩 입력
		pArr=arr+i; // pArr 은 arr[i]번째 주소를 가리킴
		sum+=(*pArr); //sum 값에 pArr이 가리키는 값= arr배열의 값 을 더함
	}

	printf("합: %d\n", sum);

}