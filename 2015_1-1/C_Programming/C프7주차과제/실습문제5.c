/* C ���α׷���
   7���� �ǽ� */

#include <stdio.h>

int main(void)
{
	int what;
	int one, two;

	printf("���ϱ�<1>, ����<2>, ���ϱ�<3>, ������<4>, ����<5>\n");
	
	while(1) // �������Է� �ݺ�. 5���Է��Ҷ����� ����
	{
	printf("������ ��ȣ �Է� : ");
	scanf("%d", &what);

	switch(what) // what�� ���� ���� ���� �ϴ°� �ٸ�
	{
	
	case 1: // ���ϱ�
		printf("���� �� �� �Է� : ");
		scanf("%d %d", &one, &two);
		printf(">> %d + %d = %d", one, two, one+two);
		break;
	
	case 2: // ����
		printf("���� �� �� �Է� : ");
		scanf("%d %d", &one, &two);
		printf(">> %d - %d = %d", one, two, one-two);
		break;
	
	case 3: // ���ϱ�
		printf("���� �� �� �Է� : ");
		scanf("%d %d", &one, &two);
		printf(">> %d * %d = %d", one, two, one*two);
		break;
	
	case 4: // ������
		printf("���� �� �� �Է� : ");
		scanf("%d %d", &one, &two);
		printf(">> %d / %d = %d", one, two, one/two);
		break;
	
	case 5: // ���α׷�����
		printf("���α׷� ����");
		break;
	
	default: // 12345���� �ƴ� �Է�
	    printf("�˸��� ��ȣ�� �Է��ϼ���");
	  }
	
	printf("\n");
	
	if(what==5) // what�� 5�� �Է��ϸ� ���α׷� �����̹Ƿ� �극��ũ�� Ż��
	{break;}
	}
return 0;	
}