// 고급C프로그래밍 10주차 실습문제2

#include <stdio.h>

enum day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

void main()
{
	enum day d;
	
	d=Sun;

	switch(d)
		{
		case Sun:
			printf("일");

		case Mon:
			printf("월");

		case Tue:
			printf("화");

		case Wed:
			printf("수");

		case Thu:
			printf("목");

		case Fri:
			printf("금");

		case Sat:
			printf("토");
		}

	printf("\n");


}