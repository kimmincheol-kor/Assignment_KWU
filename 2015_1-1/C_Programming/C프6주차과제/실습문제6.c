/* C ���α׷���
    6���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int gold=1;
	int silver;
	
	for(silver=-1; gold<=27; gold+=2) // �ǹ��� ��ȣ�� ����, ���� ������ ���밪�������Ѵ�, ���ڴ� 2��Ŀ���� ��ȣ�� ��ӹٲ��. ������ũ�Ⱑ 27�̵ɶ����� �ݺ�.
	{
		printf("%d ", gold*silver);
		silver*=-1; // ��ȣ�� ��� �ٲٴ� ����
	}
	
	printf("\n");
	
	return 0;
}