// C���α׷��� 7���� �ǽ�����3

#include <stdio.h>

struct person
{
	char name[16];
	int age;
	struct person * mate;
};

void main()
{
	struct person man[2]={
		{"������", 26}, {"������", 27}
	};
	
	man[0].mate=&man[1]; // man.mate �� man[1] �� ����Ŵ
	man[1].mate=&man[0];

	printf("�̸�: %s\n", man[0].name);
	printf("����: %d\n", man[0].age);
	printf("ģ���̸�: %s\n", man[0].mate->name); // man[0].mate�� name �Ӽ��� ���
	printf("ģ������: %d\n", man[0].mate->age);
}