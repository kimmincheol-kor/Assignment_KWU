// C���α׷��� 12���� �ǽ�

#include <stdio.h>

void counting(char *str, char count, int *sum) // ī�����Լ������� 3���� ���ڰ� �Էµȴ�, �迭���ּҰ�, ī��Ʈ��, �氪���ּҰ�
{
	if(*str==count)
		*sum+=1;
	else if(*str==0){
		printf("%d", *sum);
		return;}
}


void main()
{
	char str[256]={0};
	char count;
	int i,j,k,sum=0;

	printf(">> ���� �Է�: ");
	gets(str); // str �迭�� �����Է�

	printf(">> ī��Ʈ�� ���� �Է�: ");
	scanf("%c", &count); // count �Է�
	
	printf(">> ���� <%c> count = ", count);
	for(i=0; i<256; i++)
	{
		counting(&str[i],count,&sum); // ī�����Լ� ȣ��

		if(str[i]==0) // �迭���� 0 �̸� �ݺ�����
			break;
	}
	printf("\n");
}