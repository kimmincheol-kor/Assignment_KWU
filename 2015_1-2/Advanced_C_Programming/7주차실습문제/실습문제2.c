// C���α׷��� 7���� �ǽ�����2

#include <stdio.h>

struct date 
{
	int year;
	int month;
	int day;
};
struct person
{
	char name[16];
	char id[11];
	int age;
	struct date birth; // person�� �Ӽ����� birth ��� ���� date ����ü�� ���Ѱ��̴�.
};
void main()
{
	struct person man;

	printf("�̸�: "); scanf("%s", man.name);
	printf("�й�: "); scanf("%s", man.id);
	printf("����: "); scanf("%d", &man.age);
	printf("�������: "); scanf("%d%d%d", &man.birth.year, &man.birth.month, &man.birth.day );


	printf("\n<����>\n");

	printf("�̸�: %s\n", man.name);
	printf("�й�: %s\n", man.id);
	printf("����: %d\n", man.age);
	printf("�������: %d.%d.%d\n", man.birth); // birth ����ü�� year, month, day �� ������� ���


}