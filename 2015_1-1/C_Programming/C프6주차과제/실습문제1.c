/* C ���α׷���
    6���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int power;
	int super;

	printf("Input : ");
	scanf("%d", &power); //power �� �����Է�

	for(super=1; power>=super; super++) // �����ǰ���1�� �ʱ�ȭ; �Ŀ��� ���ۺ��� ũ�ų� ������ ��ɹ�����; ��ɹ��̳����� ���ۿ� 1�� ������
	{
		printf("%d\n", super);
	}

	// ó���� ���۰� 1, �׸��� ++ �����ؼ� 2, 3, 4 �̷��� �ö󰡴ٰ� ���۰� �Ŀ����� ���ٸ� �ݺ����� ������.

    return 0;
}