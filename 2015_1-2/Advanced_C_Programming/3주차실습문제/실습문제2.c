// C프로그래밍 3주차 실습문제2

#include <stdio.h>

void main()
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int *pArr;

	for(pArr=arr; pArr!=(arr+10); pArr++) //pArr은 arr배열의 첫번째칸의 주소를 가리킨다. 그러므로 pArr++ 는 포인터 연산으로 배열의 다음칸을 가리킨다.
		printf("%d ", *pArr);
	printf("\n");
}