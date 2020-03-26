#include<stdio.h>

int main()
{
	int num;
	int a=0,b=0,c=0;

	printf("숫자 입력: ");
	scanf("%d", &num);
	
	printf("%d의 약수: ", num);
	for(a=1; a<num+1; a++)
	{
		if(num%a==0){
			printf("%d ", a);}

	}

	printf("\n");

	return 0;

}