// ���C���α׷��� 9���� �ǽ�����6

#include <stdio.h>

typedef struct student
{
	char name[32];
	char id[32];
	struct student *next;
} Student;

void main()
{
	Student stu1={"�̽±�", "2015722001", NULL};
	Student stu2={"�̱���", "2015722007", NULL};
	Student stu3={"�ϵ���", "2015722003", NULL};
	Student stu4={"������", "2015722006", NULL};
	Student stu5={"�ڸ��", "2015722004", NULL};
	Student *cur=&stu1;

	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=&stu4;
	stu4.next=&stu5;
	stu5.next=&stu1;

	while(1)
	{
		printf("�̸�: %s\n", cur->name);
		printf("�й�: %s\n", cur->id);

		if(cur==&stu5) // cur �� ����Ű�� ���� stu5 �̸� 5�� ��� ��������Ƿ� ����.
			break;

		cur=cur->next;
	}
}