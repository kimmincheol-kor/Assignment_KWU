#include <stdio.h>

int main()
{
	int num;
	int i;

	printf("������ �Է��ϼ���: ");
	scanf("%d", &num);
	printf("���μ� ���� : ");
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
	printf("\n��� ��\n");

	return 0;
}