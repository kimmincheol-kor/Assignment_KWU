// C프로그래밍 7주차 실습문제4

#include <stdio.h>

struct point {
		int x;
		int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

void main()
{
	struct rect r;
	int weight, height;

	printf("왼쪽 상단의 좌표: ");
	scanf("%d%d", &r.p1.x, &r.p1.y);
	printf("오른쪽 하단의 좌표: ");
	scanf("%d%d", &r.p2.x, &r.p2.y);

	weight=r.p2.x-r.p1.x; // 가로 길이 r의 점2의 x좌표 - r의 점1의 x좌표.
	height=r.p2.y-r.p1.y; // 세로 길이

	printf("면적: %d\n", weight*height);
	printf("둘레: %d\n", (weight*2)+(height*2));

}