// C프로그래밍 7주차 실습문제1

#include <stdio.h>

struct perseon // 구조체 person 선언
{
	char name[20];
	int code[20];
	int age;
} man1, man2;

void main()
{
	printf("이름: "); scanf("%s", man1.name);
	printf("학번: "); scanf("%s", man1.code);
	printf("나이: "); scanf("%d", &man1.age);
	
	printf("이름: "); scanf("%s", man2.name);
	printf("학번: "); scanf("%s", man2.code);
	printf("나이: "); scanf("%d", &man2.age);

	printf("\n결과\n");

	printf("이름: %s\n", man1.name);
	printf("학번: %s\n", man1.code);
	printf("나이: %d\n", man1.age);

	printf("이름: %s\n", man2.name);
	printf("학번: %s\n", man2.code);
	printf("나이: %d\n", man2.age);
}