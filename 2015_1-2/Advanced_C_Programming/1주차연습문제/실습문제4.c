#include<stdio.h>

int div_sum();

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("숫자 입력: ");
	scanf("%d", &num);
	
	printf("약수들의 합: %d\n", div_sum(num));

	return 0;
}

int div_sum(int snum)
{
	int a;
	int sum=0;

	printf("%d의 약수: ", snum);
	for(a=1; a<snum+1; a++)
	{
		if(snum%a==0){
			printf("%d ", a);
			sum+=a;}
	}
	printf("\n");

	return sum;

}