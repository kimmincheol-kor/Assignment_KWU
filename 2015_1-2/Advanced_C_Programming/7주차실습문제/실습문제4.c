// C���α׷��� 7���� �ǽ�����4

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

	printf("���� ����� ��ǥ: ");
	scanf("%d%d", &r.p1.x, &r.p1.y);
	printf("������ �ϴ��� ��ǥ: ");
	scanf("%d%d", &r.p2.x, &r.p2.y);

	weight=r.p2.x-r.p1.x; // ���� ���� r�� ��2�� x��ǥ - r�� ��1�� x��ǥ.
	height=r.p2.y-r.p1.y; // ���� ����

	printf("����: %d\n", weight*height);
	printf("�ѷ�: %d\n", (weight*2)+(height*2));

}