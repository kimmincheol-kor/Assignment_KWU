/* C ���α׷���
   7���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int king;
	printf("���� �Է�<0~10> : ");
	scanf("%d", &king);

	switch(king) // king�� ���� ���� ���� ������ �޶���
	{
	case 10: // king�� 10�̶�� �̰� ����
		printf("���� : A\n");
		break; // ����ġ�� Ż��
	case 9:
		printf("���� : B\n");
		break;
	case 8:
		printf("���� : C\n");
		break;
	case 7:
		printf("���� : D\n");
		break;
	default:
		printf("���� : F\n");
	}
	return 0;
}