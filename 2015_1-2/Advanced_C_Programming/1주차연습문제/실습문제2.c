#include<stdio.h>

int main()
{
	int num;
	int a=0,b=0,c=0;

	printf("���� �Է�: ");
	scanf("%d", &num);
	
	printf("%d�� ���: ", num);
	for(a=1; a<num+1; a++)
	{
		if(num%a==0){
			printf("%d ", a);}

	}

	printf("\n");

	return 0;

}