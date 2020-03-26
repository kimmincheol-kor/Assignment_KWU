// ���C�� 6���� �ǽ�����6


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_ascending(const void *a, const void *b){
	return strcmp((char*)a,(char*)b); // a�� b�� ���� �� ��ȯ
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
	puts("��������");
	for(i=0; i<10; i++){
		printf("%s\n", arr[i]);
	}

	qsort(arr, 10, sizeof(arr[0]),compare_descending);
	puts("\n��������");
	for(i=0; i<10; i++){
		printf("%s\n", arr[i]);
	}
}