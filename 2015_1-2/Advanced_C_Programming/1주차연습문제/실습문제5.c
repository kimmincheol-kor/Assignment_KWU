#include<stdio.h>

int div_sum();

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("숫자 입력: ");
	scanf("%d", &num);
	
	printf("자신을 제외한 약수들의 합: %d\n", div_sum(num));

	if(div_sum(num)==num)
		printf("%d은<는> 완전수 입니다\n", num);

	if(div_sum(num)!=num)
		printf("%d은<는> 완전수가 아닙니다\n", num);

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