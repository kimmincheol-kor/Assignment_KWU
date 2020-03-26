#include <stdio.h>

int main()
{
	int num;
	int i;

	printf("정수를 입력하세요: ");
	scanf("%d", &num);
	printf("소인수 분해 : ");
	while(1)
	{
		for(i=2; i<=num; i++)
		{
			if(num%i==0)
			{
				printf("%d ", i);
				num/=i;
				break;
			}
			else
				continue;
		}

		if(num==1)
			break;
	}
	printf("\n출력 끝\n");

	return 0;
}