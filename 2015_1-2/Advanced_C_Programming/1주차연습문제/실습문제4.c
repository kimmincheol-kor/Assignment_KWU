#include<stdio.h>

int div_sum();

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("���� �Է�: ");
	scanf("%d", &num);
	
	printf("������� ��: %d\n", div_sum(num));

	return 0;
}

int div_sum(int snum)
{
	int a;
	int sum=0;

	printf("%d�� ���: ", snum);
	for(a=1; a<snum+1; a++)
	{
		if(snum%a==0){
			printf("%d ", a);
			sum+=a;}
	}
	printf("\n");

	return sum;

}