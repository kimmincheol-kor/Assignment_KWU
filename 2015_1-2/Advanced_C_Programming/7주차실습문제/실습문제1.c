// C���α׷��� 7���� �ǽ�����1

#include <stdio.h>

struct perseon // ����ü person ����
{
	char name[20];
	int code[20];
	int age;
} man1, man2;

void main()
{
	printf("�̸�: "); scanf("%s", man1.name);
	printf("�й�: "); scanf("%s", man1.code);
	printf("����: "); scanf("%d", &man1.age);
	
	printf("�̸�: "); scanf("%s", man2.name);
	printf("�й�: "); scanf("%s", man2.code);
	printf("����: "); scanf("%d", &man2.age);

	printf("\n���\n");

	printf("�̸�: %s\n", man1.name);
	printf("�й�: %s\n", man1.code);
	printf("����: %d\n", man1.age);

	printf("�̸�: %s\n", man2.name);
	printf("�й�: %s\n", man2.code);
	printf("����: %d\n", man2.age);
}