// C프로그래밍 7주차 실습문제3

#include <stdio.h>

struct person
{
	char name[16];
	int age;
	struct person * mate;
};

void main()
{
	struct person man[2]={
		{"김준현", 26}, {"이휘재", 27}
	};
	
	man[0].mate=&man[1]; // man.mate 는 man[1] 을 가르킴
	man[1].mate=&man[0];

	printf("이름: %s\n", man[0].name);
	printf("나이: %d\n", man[0].age);
	printf("친구이름: %s\n", man[0].mate->name); // man[0].mate의 name 속성을 출력
	printf("친구나이: %d\n", man[0].mate->age);
}