// 고급C프로그래밍 9주차 실습문제1

#include <stdio.h>

typedef struct person
{
	char name[20];
	int age;
} Person; // 구조체 이름은 Person


void main()
{
	Person man;
	printf("이름: ");
	scanf("%s", man.name);
	printf("나이: ");
	scanf("%d", &man.age);

	puts("\n입력결과");
	printf("이름: %s\n", man.name); // 구조체 Person의 man의 name 출력
	printf("나이: %d\n", man.age); // 구조체 Person의 man의 age 출력
}