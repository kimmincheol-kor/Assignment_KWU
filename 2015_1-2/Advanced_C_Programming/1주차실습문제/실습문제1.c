// C ���α׷��� 1���� �ǽ�����1

#include <stdio.h>

int main()
{
	int num;

	while(1) // -1�� �Էµɶ����� �ݺ�.
	{
	printf("�Է�<����:-1>: ");
	scanf("%d", &num);

	if(num>0){ // ����� ����
	if(num%2==0)
		printf("¦���Դϴ�.\n");
	else
		printf("Ȧ���Դϴ�.\n");}
	else if(num==-1) // -1 �� ������ ����
		break;
	else // ����� -1 �� �ƴ� ���� �Է� ������ ���Է�.
		printf("�ٽ� �Է��ϼ���.\n");
	}
}