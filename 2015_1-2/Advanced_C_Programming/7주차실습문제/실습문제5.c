// C 프로그래밍 7주차 실습문제5

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

	for(i=0; i<6; i++) // stu의 이름과 id 입력받기
	{
		printf("이름: ");
		scanf("%s", stu[i].name);

		printf("학번: ");
		scanf("%s", stu[i].id);
	}

	printf("\n정렬결과\n");
	
	for(i=0; i<6; i++)
	{
		for(j=1; j<6; j++)
		{
			if(strcmp(stu[j].id, stu[j-1].id) == -1) // 학번에 따라 내림차순 정렬
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
		printf("이름: %s\n", stu[i].name);
		printf("학번: %s\n", stu[i].id);
	}

}