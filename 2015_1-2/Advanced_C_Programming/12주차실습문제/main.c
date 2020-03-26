#include <stdio.h>

// 1번문제 매크로
#define MUL(X,Y) ((X)*(Y))
#define MAX(X,Y) X>Y ? X:Y // X가 크면 X 출력
#define MIN(X,Y) X<Y ? X:Y // X가 작으면 X 출력

// 2번문제 매크로
#define CON(X,Y,Z) X##Y##Z // XYZ 합체

// 4번문제 매크로
#define IS_EVAN(X) X&1 ? "홀수":"짝수" // 홀짝 구분

// 5번문제 헤더
#include "power.h" // 헤더파일 구분
extern int number; // 외부 변수 참조

// 6번문제 매크로
#define DEBUG // DEBUG 매크로 정의

#define PRACTICE 5

int main()
{
#if PRACTICE == 1
	{
		printf("(1+1)*(2+2) = %d\n", MUL(1+1,2+2));
		printf("max(5,3) = %d\n", MAX(5,3));
		printf("min(5,3) = %d\n", MIN(5,3));
	}

#elif PRACTICE == 2
	{
		int student_number = CON(2015, 722, 001);
		printf("학번: %d\n", student_number);
	}

#elif PRACTICE == 3
	{
		char str[32];
		int year,department,number;

		printf("입학년도,학과번호,개인번호: ");
		scanf("%s", str);

		sscanf(str, "%d,%d,%d", &year, &department, &number);
		sprintf(str, "%d%d%03d", year, department, number); // %03d는 나머지 자리를 0으로 채우면서 3자리수 출력

		printf("학번: %s\n", str);
	}

#elif PRACTICE == 4
	{
		int n;

		while(1)
		{
			printf("입력: ");
			scanf("%d", &n);
			printf("%d: %s\n\n", n, IS_EVAN(n));
		}
	}

#elif PRACTICE == 5
	{
		int x,y;

		printf("x: ");
		scanf("%d", &x);
		printf("y: ");
		scanf("%d", &y);

		printf("%d의 %d 제곱: %.2lf\n", x, y, power(x,y));
		printf("number: %d\n", number);
	}

#elif PRACTICE == 6
	{
#ifdef DEBUG
		printf("DEBUG가 정의되어 있습니다.\n");
#endif
#ifndef DEBUG
		printf("DEBUG가 정의되어있지 않습니다.\n");
#endif
	}

#endif


}