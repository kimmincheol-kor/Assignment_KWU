// ���C���α׷��� 9���� �ǽ�����1

#include <stdio.h>

typedef struct person
{
	char name[20];
	int age;
} Person; // ����ü �̸��� Person


void main()
{
	Person man;
	printf("�̸�: ");
	scanf("%s", man.name);
	printf("����: ");
	scanf("%d", &man.age);

	puts("\n�Է°��");
	printf("�̸�: %s\n", man.name); // ����ü Person�� man�� name ���
	printf("����: %d\n", man.age); // ����ü Person�� man�� age ���
}