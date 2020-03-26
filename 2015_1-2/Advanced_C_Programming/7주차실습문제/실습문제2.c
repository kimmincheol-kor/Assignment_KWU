// C프로그래밍 7주차 실습문제2

#include <stdio.h>

struct date 
{
	int year;
	int month;
	int day;
};
struct person
{
	char name[16];
	char id[11];
	int age;
	struct date birth; // person의 속성중의 birth 라는 것은 date 구조체에 속한것이다.
};
void main()
{
	struct person man;

	printf("이름: "); scanf("%s", man.name);
	printf("학번: "); scanf("%s", man.id);
	printf("나이: "); scanf("%d", &man.age);
	printf("생년월일: "); scanf("%d%d%d", &man.birth.year, &man.birth.month, &man.birth.day );


	printf("\n<정보>\n");

	printf("이름: %s\n", man.name);
	printf("학번: %s\n", man.id);
	printf("나이: %d\n", man.age);
	printf("생년월일: %d.%d.%d\n", man.birth); // birth 구조체의 year, month, day 가 순서대로 출력


}