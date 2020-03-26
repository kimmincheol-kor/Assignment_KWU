// 고급C프로그래밍 9주차 실습문제3

#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
} Point; // 구조체 이름은 Point

void swap(Point *p) // xpos와 ypos를 swap
{
	int temp=p->xpos;

	p->xpos=p->ypos;
	p->ypos=temp;
}

void main()
{
	Point point;
	printf("x좌표: ");
	scanf("%d", &point.xpos);
	printf("y좌표: ");
	scanf("%d", &point.ypos);

	swap(&point);
	printf("swap: [%d, %d]\n", point.xpos, point.ypos);
}
