/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>

int main()
{
	int asd;
	
	printf("Input : ");
	scanf("%d", &asd); // asd ���� �Է�
	printf("Output : ");

	while(asd>0)
	{
		printf("%d", asd%10); // 10���� ���� �������� ù°�ڸ� ����
		asd/=10; // asd = asd/10 => ù°�ڸ����� ���� 
	} // ù°�ڸ� ���ں��� ���. = �Ųٷ� ���
	

	printf("\n");

	return 0;
}