// ���C�� 11���� �ǽ�����1

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *pi;
	int i, n;

	printf("ũ��: ");
	scanf("%d", &n);

	pi=(int *)malloc(sizeof(int)*n); // �޸� ���� �Ҵ�
	for(i=0; i<n; i++)
	{
		*(pi+i)=i;
		printf("*(pi+%d): %d\n", i, *(pi+i));
	}

	free(pi);
}