// C���α׷��� 3���� �ǽ�����3

#include <stdio.h>

void main()
{
	int freq=0;
	char arr[32];
	char alpha;
	char *pArr;

	printf("�Է�: ");
	gets(arr); // arr �迭�� ���� �Է�.

	while(1)
	{
	printf("ã�±���<a-z>: ");
	scanf("%c", &alpha); // alpha�� ã�� ���� �Է�
	fflush(stdin);

	if((97<=alpha)&&(alpha<=122)) // �ҹ����� �ƽ�Ű �ڵ尪�� 97~122
		break;
	else
		printf("ã�� ���ڰ� �߸��Ǿ����ϴ�.\n");
	}

	for(pArr=arr; pArr!=(arr+sizeof(arr)); pArr++) // arr�迭�� �Էµ� �����߿� alpha�� ���� ���� ���ִٸ� freq�� +1
		{if(*pArr==alpha)
		freq+=1;}


	printf("%c�� ����: %d\n", alpha, freq);


}