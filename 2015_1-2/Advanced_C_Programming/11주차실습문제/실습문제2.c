// ���C�� 11���� �ǽ�����2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person // person ����ü ����
{
	char name[32];
	int age;
}Person;

void main()
{
	Person *person;

	person=(Person *)malloc(sizeof(Person)); // ����ü �޸� �Ҵ�
	strcpy(person->name, "ȫ�浿"); // ���ڿ� ����
	(*person).age=20;

	printf("�̸�: %s\n", person->name);
	printf("����: %d\n", person->age);
}