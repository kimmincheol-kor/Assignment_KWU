// ���C���α׷��� 10���� �ǽ�����4

#include <stdio.h>

typedef struct student // ����ü ����
{
	char name[32];
	int math;
	int english;
} Student;

void main()
{
	FILE *fp;
	Student stu[3];
	int i;

	fp=fopen("data.txt", "rt");
	
	for(i=0; i<3; i++)
	{
	fscanf(fp, "%s %d %d", stu[i].name, &stu[i].math, &stu[i].english); // fp���Ͽ��� ���� ������
	}

	printf("%-8s %-8s %-8s \n", "�̸�", "����", "����");
	for(i=0; i<3; i++)
	{
	printf("%-8s %-8d %-8d \n", stu[i].name, stu[i].math, stu[i].english); // ����ü ���
	}

	printf("���� ���: %.6f\n", (double)(stu[0].math+stu[1].math+stu[2].math)/3);
	printf("���� ���: %.6f\n", (double)(stu[0].english+stu[1].english+stu[2].english)/3);

}

