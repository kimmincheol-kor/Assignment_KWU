// ���C�� 11���� �ǽ�����3

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *num=NULL;
	int n, cnt=0;

	while(1)
	{
		printf("���� ������ �Է��ϼ���(����: -1): ");
		scanf("%d", &n);

		if( n == -1 ) break;
		
		num = (int *)realloc(num, sizeof(int)*(cnt+1)); // �޸� ������ ����
		num[cnt]=n;
		cnt++;
	}

	for(n=0; n<cnt; n++)
	{
		printf("num[%d]: %d\n", n, num[n]);
	}

	free(num);
}