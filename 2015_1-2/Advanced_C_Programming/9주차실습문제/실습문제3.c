// ���C���α׷��� 9���� �ǽ�����3

#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
} Point; // ����ü �̸��� Point

void swap(Point *p) // xpos�� ypos�� swap
{
	int temp=p->xpos;

	p->xpos=p->ypos;
	p->ypos=temp;
}

void main()
{
	Point point;
	printf("x��ǥ: ");
	scanf("%d", &point.xpos);
	printf("y��ǥ: ");
	scanf("%d", &point.ypos);

	swap(&point);
	printf("swap: [%d, %d]\n", point.xpos, point.ypos);
}
