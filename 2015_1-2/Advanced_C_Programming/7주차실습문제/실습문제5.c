// C ���α׷��� 7���� �ǽ�����5

#include <stdio.h>
#include <string.h>

struct student {
	char name[16];
	char id[16];
};

void main()
{
	struct student stu[6];
	struct student temp;
	int i,j;

	for(i=0; i<6; i++) // stu�� �̸��� id �Է¹ޱ�
	{
		printf("�̸�: ");
		scanf("%s", stu[i].name);

		printf("�й�: ");
		scanf("%s", stu[i].id);
	}

	printf("\n���İ��\n");
	
	for(i=0; i<6; i++)
	{
		for(j=1; j<6; j++)
		{
			if(strcmp(stu[j].id, stu[j-1].id) == -1) // �й��� ���� �������� ����
			{
				strcpy(temp.name, stu[j-1].name);
				strcpy(stu[j-1].name, stu[j].name);
				strcpy(stu[j].name, temp.name);

				strcpy(temp.id,stu[j-1].id);
				strcpy(stu[j-1].id,stu[j].id);
				strcpy(stu[j].id,temp.id);
			}
		}
	}

	for(i=0; i<6; i++)
	{
		printf("�̸�: %s\n", stu[i].name);
		printf("�й�: %s\n", stu[i].id);
	}

}