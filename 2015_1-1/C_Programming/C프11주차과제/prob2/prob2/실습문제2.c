/* C���α׷��� 11���� �ǽ����� */

#include <stdio.h>

int main()
{
	int num[10]={0};
	int i;
	int *pMax=NULL;
	int *pMin=NULL;

	printf("Input: ");

	for(i=0; i<10; i++)
	{
		scanf("%d", &num[i]); // num �迭 0������ 9������ �Է�.
	}
	
	pMax=&num[0];
	pMin=&num[0]; // �ִ밪�� �ּҰ� �ּҴ� num[0]�� �ּҷ� �Է�

	for(i=0; i<10; i++) //�迭 num ���� Max�� Min�� ã�Ƴ���
	{
		if(num[i]>*pMax)
			pMax=&num[i];
		else if(num[i]<*pMin)
		    pMin=&num[i];
    }

	printf("Max: %d\n", *pMax);
	printf("Min: %d\n", *pMin);

	return 0;
}