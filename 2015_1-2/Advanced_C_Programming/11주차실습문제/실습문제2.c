// 고급C프 11주차 실습문제2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person // person 구조체 선언
{
	char name[32];
	int age;
}Person;

void main()
{
	Person *person;

	person=(Person *)malloc(sizeof(Person)); // 구조체 메모리 할당
	strcpy(person->name, "홍길동"); // 문자열 복사
	(*person).age=20;

	printf("이름: %s\n", person->name);
	printf("나이: %d\n", person->age);
}