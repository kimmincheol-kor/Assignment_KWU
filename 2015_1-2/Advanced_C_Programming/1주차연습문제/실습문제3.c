#include<stdio.h>

int main()
{
	int num=0, sum=0;
	int a=0;

	printf("숫자 입력: ");
	scanf("%d", &num);
	
	printf("%d의 약수: ", num);
	for(a=1; a<num+1; a++)
	{
		if(num%a==0){
			printf("%d ", a);
			sum+=a;}
	}
	printf("\n");

	printf("약수들의 합: %d", sum);
	printf("\n");

	return 0;
}