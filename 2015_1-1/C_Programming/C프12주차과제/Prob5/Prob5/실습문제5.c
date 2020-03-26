// C프로그래밍 12주차 실습문제

#include <stdio.h>

void bubble_sort(int flag, int *arr);
void swap(int *n1, int *n2);
int compare(int flag, int n1, int n2){
	return flag==1? (n1>n2):(n1<n2);
}

int main()
{
	int list[5]={0};
	int i=0, flag=0;

	printf("#--- Bubble Sort ---#\n");
	printf("1. Ascending Order\n");
	printf("2. Descending Order\n");
	printf("3. Exit\n\n");

	do{
		printf("\nSelect: ");
		scanf("%d", &flag);

		if(flag==3) // 3입력하면 종료
			break;
		
		else if((flag!=1)&&(flag!=2)&&(flag!=3)) // 1,2,3 이 아닌 수를 입력하면 컨티뉴
			continue;
		
		printf("Input the list <5>: ");
		for(i=0; i<5; i++){ // list 에 값 입력
			scanf("%d", &list[i]);
		}

		bubble_sort(flag, list); // flag 값 , list 배열 입력

    }while(1);

	return 0;
}

void bubble_sort(int flag, int *arr) // bubble sort
{
	int i, j, k;
	for (i=0; i<5; i++) { // 먼저오는 숫자
		for(j=i+1; j<5; j++) { // 나중숫자
			if(compare(flag, arr[i], arr[j])>0) { // 먼저오는숫자 - 나중숫자 비교 flag=오름차순 내림차순 결정
				swap(&arr[i], &arr[j]);
				printf(">> %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
			}
		}
	}
}

void swap(int *n1, int *n2)
{
	int point1=*n1;
	int point2=*n2;

	*n1=point2;
	*n2=point1;
}