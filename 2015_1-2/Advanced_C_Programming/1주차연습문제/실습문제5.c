#include<stdio.h>

int div_sum();

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("���� �Է�: ");
	scanf("%d", &num);
	
	printf("�ڽ��� ������ ������� ��: %d\n", div_sum(num));

	if(div_sum(num)==num)
		printf("%d��<��> ������ �Դϴ�\n", num);

	if(div_sum(num)!=num)
		printf("%d��<��> �������� �ƴմϴ�\n", num);

	return 0;
}

int div_sum(int snum)
{
	int a;
	int sum=0;

	for(a=1; a<snum; a++)
	{
		if(snum%a==0){
			sum+=a;}
	}

	return sum;

}