// ���C���α׷��� 9���� �ǽ�����4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[32];
	char id[32];
} Student; // ����ü Student

int compare(const void *a, const void *b) // ����ü�� compare�� �޴¹� (����:����)
{
	Student *A=(Student *)a;
	Student *B=(Student *)b;

	return strcmp((char*)A->id,(char*)B->id); // id�� ���� �������� ����
}

void main()
{
	Student stu[6];
	int i;

	for(i=0; i<6; i++)
	{
		printf("�̸�: ");
		scanf("%s", stu[i].name);

		printf("�й�: ");
		scanf("%s", stu[i].id);
	}

	qsort(stu, 6, sizeof(struct student), compare); // �������� ����
	puts("\n���İ��");
	for(i=0; i<6; i++)
	{
		printf("�̸�: %s\n", stu[i].name);
		printf("�й�: %s\n", stu[i].id);
	}
}