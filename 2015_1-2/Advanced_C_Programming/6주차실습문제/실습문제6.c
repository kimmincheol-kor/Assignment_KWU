// 고급C프 6주차 실습문제6


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_ascending(const void *a, const void *b){
	return strcmp((char*)a,(char*)b); // a와 b를 비교한 값 반환
}
int compare_descending(const void *a, const void *b){
	return strcmp((char*)b,(char*)a);
}

void main()
{
	int i;
	char arr[10][32]={"apple", "lemon", "grape", "peach", "pears",
		"orange", "mango", "melon", "tomato", "banana"};

	qsort(arr, 10, sizeof(arr[0]), compare_ascending);
	puts("오름차순");
	for(i=0; i<10; i++){
		printf("%s\n", arr[i]);
	}

	qsort(arr, 10, sizeof(arr[0]),compare_descending);
	puts("\n내림차순");
	for(i=0; i<10; i++){
		printf("%s\n", arr[i]);
	}
}