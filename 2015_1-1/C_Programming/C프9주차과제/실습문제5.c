/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>

void reverse(int num) // asd ����
{
	if(num==0){
		return; // �Լ� ����, ��ȯx
	}
	else
	printf("%d", num%10); // �����ڸ��� ���
	reverse(num/10); // �����ڸ��� ����
}
	
int main()
{
	int asd, result;
	
	printf("Input : ");
	scanf("%d", &asd); // asd ���� �Է�

	printf("Output : ");
    reverse(asd); // �Լ� ��� �������Լ����� ��µɳ����� �ҷ���

	printf("\n");

	return 0;
}