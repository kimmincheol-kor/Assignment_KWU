// 고급C프로그래밍 9주차 실습문제6

#include <stdio.h>

typedef struct student
{
	char name[32];
	char id[32];
	struct student *next;
} Student;

void main()
{
	Student stu1={"이승기", "2015722001", NULL};
	Student stu2={"이광수", "2015722007", NULL};
	Student stu3={"하동훈", "2015722003", NULL};
	Student stu4={"정형돈", "2015722006", NULL};
	Student stu5={"박명수", "2015722004", NULL};
	Student *cur=&stu1;

	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=&stu4;
	stu4.next=&stu5;
	stu5.next=&stu1;

	while(1)
	{
		printf("이름: %s\n", cur->name);
		printf("학번: %s\n", cur->id);

		if(cur==&stu5) // cur 이 가리키는 것이 stu5 이면 5명 모두 출력했으므로 종료.
			break;

		cur=cur->next;
	}
}