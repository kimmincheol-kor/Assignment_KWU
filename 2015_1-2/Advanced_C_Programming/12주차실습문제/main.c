#include <stdio.h>

// 1������ ��ũ��
#define MUL(X,Y) ((X)*(Y))
#define MAX(X,Y) X>Y ? X:Y // X�� ũ�� X ���
#define MIN(X,Y) X<Y ? X:Y // X�� ������ X ���

// 2������ ��ũ��
#define CON(X,Y,Z) X##Y##Z // XYZ ��ü

// 4������ ��ũ��
#define IS_EVAN(X) X&1 ? "Ȧ��":"¦��" // Ȧ¦ ����

// 5������ ���
#include "power.h" // ������� ����
extern int number; // �ܺ� ���� ����

// 6������ ��ũ��
#define DEBUG // DEBUG ��ũ�� ����

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
		printf("�й�: %d\n", student_number);
	}

#elif PRACTICE == 3
	{
		char str[32];
		int year,department,number;

		printf("���г⵵,�а���ȣ,���ι�ȣ: ");
		scanf("%s", str);

		sscanf(str, "%d,%d,%d", &year, &department, &number);
		sprintf(str, "%d%d%03d", year, department, number); // %03d�� ������ �ڸ��� 0���� ä��鼭 3�ڸ��� ���

		printf("�й�: %s\n", str);
	}

#elif PRACTICE == 4
	{
		int n;

		while(1)
		{
			printf("�Է�: ");
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

		printf("%d�� %d ����: %.2lf\n", x, y, power(x,y));
		printf("number: %d\n", number);
	}

#elif PRACTICE == 6
	{
#ifdef DEBUG
		printf("DEBUG�� ���ǵǾ� �ֽ��ϴ�.\n");
#endif
#ifndef DEBUG
		printf("DEBUG�� ���ǵǾ����� �ʽ��ϴ�.\n");
#endif
	}

#endif


}