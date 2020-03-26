// 고급C프로그래밍 9주차 실습문제5

#include <stdio.h>

typedef struct student
{
	char name[32];
	char id[32];
	struct student *next;
} Student; // 구조체 이름은 Student

void main()
{
	Student stu1={"이승기", "2015722001", NULL};
	Student stu2={"이광수", "2015722007", NULL};
	Student stu3={"하동훈", "2015722003", NULL};
	Student *cur=&stu1; // 포인터 cur 은 stu1 을 가리킴

	stu1.next=&stu2; // stu1의 next 는 stu2 를 가리킴
	stu2.next=&stu3; // stu2의 next 는 stu3를 가리킴

	while(cur!=NULL) // cur이 NULL이면 종료 = 가리키는게 없어지면 종료
	{
		printf("이름: %s\n", cur->name);
		printf("학번: %s\n", cur->id);

		cur=cur->next; // cur이 가리키는 것은 기존 cur이 가리키는 학생의 next
	}
}