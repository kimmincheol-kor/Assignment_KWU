// ���C���α׷��� 9���� �ǽ�����2

#include <stdio.h>

typedef struct coffee
{
	char name[32];
	int price;
} Coffee; // ����ü coffee�� �̸��� Coffee

Coffee GetCoffee(void)
{
	Coffee cof;

	printf("Ŀ�� �̸�: ");
	scanf("%s", cof.name);
	printf("Ŀ�� ����: ");
	scanf("%d", &cof.price);

	return cof; // GetCoffee���� ���� cof�� ��ȯ
}

void ShowCoffee(Coffee cof) // ����ü ���
{
	printf("Ŀ�� �̸�: %s\n", cof.name);
	printf("Ŀ�� ����: %d\n", cof.price);
}

void main()
{
	Coffee coffee[2];
	int i;

	for(i=0; i<2; i++)
		coffee[i]=GetCoffee();

	puts("\n���");
	for(i=0; i<2; i++)
		ShowCoffee(coffee[i]);
}