// C���α׷��� 12���� �ǽ�����

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

		if(flag==3) // 3�Է��ϸ� ����
			break;
		
		else if((flag!=1)&&(flag!=2)&&(flag!=3)) // 1,2,3 �� �ƴ� ���� �Է��ϸ� ��Ƽ��
			continue;
		
		printf("Input the list <5>: ");
		for(i=0; i<5; i++){ // list �� �� �Է�
			scanf("%d", &list[i]);
		}

		bubble_sort(flag, list); // flag �� , list �迭 �Է�

    }while(1);

	return 0;
}

void bubble_sort(int flag, int *arr) // bubble sort
{
	int i, j, k;
	for (i=0; i<5; i++) { // �������� ����
		for(j=i+1; j<5; j++) { // ���߼���
			if(compare(flag, arr[i], arr[j])>0) { // �������¼��� - ���߼��� �� flag=�������� �������� ����
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