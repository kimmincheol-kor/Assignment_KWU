// 고급C프로그래밍 실습문제1

#include <stdio.h>

void main()
{
	int arr[2][2]={ {1,2}, {3,4} };
	int (*ptr)[2];
	int i;

	ptr=arr; // ptr은 arr을 가리킴

	for(i=0; i<2; i++) { // ptr 로 출력 = arr 을 출력
		printf("%d %d\n", ptr[i][0], ptr[i][1]); 
	}
}