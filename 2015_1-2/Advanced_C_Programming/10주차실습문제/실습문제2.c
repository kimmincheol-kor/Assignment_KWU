// ���C���α׷��� 10���� �ǽ�����2

#include <stdio.h>

enum day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

void main()
{
	enum day d;
	
	d=Sun;

	switch(d)
		{
		case Sun:
			printf("��");

		case Mon:
			printf("��");

		case Tue:
			printf("ȭ");

		case Wed:
			printf("��");

		case Thu:
			printf("��");

		case Fri:
			printf("��");

		case Sat:
			printf("��");
		}

	printf("\n");


}