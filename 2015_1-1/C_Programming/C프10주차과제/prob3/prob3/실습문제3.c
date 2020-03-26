/* C프로그래밍 10주차 실습 */

#include <stdio.h>

void even(int num) 
{
	int arr[10]={10, 21, 35, 46, 57, 64, 79, 82, 91, 101};

	if(arr[num]%2==0) //2의 배수이면
		printf("%d ", arr[num]); // 출력
	else
		return; // 아니면 종료

}

int main()
{
	int arr[10]={10, 21, 35, 46, 57, 64, 79, 82, 91, 101}; // arr 배열값 모두 입력
	int a=0, b=0, c=sizeof(arr)/sizeof(int); // c값을 arr 배열의 크기
	
	printf("even numbers: ");
	
	for(a=0; a<c; a++)
	{
		even(a); // even함수에 0부터 9까지 대입(=배열의 모든값 입력) -> 함수출력
	}

	printf("\n");

	return 0;
}