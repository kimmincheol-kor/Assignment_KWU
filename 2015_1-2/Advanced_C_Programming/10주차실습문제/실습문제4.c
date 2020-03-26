// 고급C프로그래밍 10주차 실습문제4

#include <stdio.h>

typedef struct student // 구조체 선언
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
	fscanf(fp, "%s %d %d", stu[i].name, &stu[i].math, &stu[i].english); // fp파일에서 값을 가져옴
	}

	printf("%-8s %-8s %-8s \n", "이름", "수학", "영어");
	for(i=0; i<3; i++)
	{
	printf("%-8s %-8d %-8d \n", stu[i].name, stu[i].math, stu[i].english); // 구조체 출력
	}

	printf("수학 평균: %.6f\n", (double)(stu[0].math+stu[1].math+stu[2].math)/3);
	printf("영어 평균: %.6f\n", (double)(stu[0].english+stu[1].english+stu[2].english)/3);

}

