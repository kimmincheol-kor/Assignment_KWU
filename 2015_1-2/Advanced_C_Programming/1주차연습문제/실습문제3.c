#include<stdio.h>

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("���� �Է�: ");
	scanf("%d", &num);
	
	printf("%d�� ���: ", num);
	for(a=1; a<num+1; a++)
	{
		if(num%a==0){
			printf("%d ", a);
			sum+=a;}
	}
	printf("\n");

	printf("������� ��: %d", sum);
	printf("\n");

	return 0;
}