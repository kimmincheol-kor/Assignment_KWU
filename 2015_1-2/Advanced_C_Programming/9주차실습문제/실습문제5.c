// ���C���α׷��� 9���� �ǽ�����5

#include <stdio.h>

typedef struct student
{
	char name[32];
	char id[32];
	struct student *next;
} Student; // ����ü �̸��� Student

void main()
{
	Student stu1={"�̽±�", "2015722001", NULL};
	Student stu2={"�̱���", "2015722007", NULL};
	Student stu3={"�ϵ���", "2015722003", NULL};
	Student *cur=&stu1; // ������ cur �� stu1 �� ����Ŵ

	stu1.next=&stu2; // stu1�� next �� stu2 �� ����Ŵ
	stu2.next=&stu3; // stu2�� next �� stu3�� ����Ŵ

	while(cur!=NULL) // cur�� NULL�̸� ���� = ����Ű�°� �������� ����
	{
		printf("�̸�: %s\n", cur->name);
		printf("�й�: %s\n", cur->id);

		cur=cur->next; // cur�� ����Ű�� ���� ���� cur�� ����Ű�� �л��� next
	}
}