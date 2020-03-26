// 고급C프로그래밍 9주차 실습문제4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[32];
	char id[32];
} Student; // 구조체 Student

int compare(const void *a, const void *b) // 구조체를 compare에 받는법 (참조:구글)
{
	Student *A=(Student *)a;
	Student *B=(Student *)b;

	return strcmp((char*)A->id,(char*)B->id); // id에 따라서 오름차순 정렬
}

void main()
{
	Student stu[6];
	int i;

	for(i=0; i<6; i++)
	{
		printf("이름: ");
		scanf("%s", stu[i].name);

		printf("학번: ");
		scanf("%s", stu[i].id);
	}

	qsort(stu, 6, sizeof(struct student), compare); // 오름차순 정렬
	puts("\n정렬결과");
	for(i=0; i<6; i++)
	{
		printf("이름: %s\n", stu[i].name);
		printf("학번: %s\n", stu[i].id);
	}
}