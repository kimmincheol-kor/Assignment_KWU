#include<stdio.h>

int main()
{
	int num1, num2;

	printf("숫자1 입력: ");
	scanf("%d", &num1);

	printf("숫자2 입력: ");
	scanf("%d", &num2);

	if(num1%num2==0)
		printf("%d은<는> %d의 약수입니다\n", num2, num1);
	else
		printf("%d은<는> %d의 약수가 아닙니다\n", num2, num1);

	return 0;
}