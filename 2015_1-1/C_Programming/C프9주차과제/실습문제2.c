/* C ���α׷���
   9���� �ǽ����� */

#include <stdio.h>


int setID() // setID �Լ�
{
	int id;
	printf("�й� �Է� : ");
	scanf("%d", &id); //id�� �Է�
	return id; //id�� ��ȯ
}

void printfTimeTable(int mID)
{
	printf("\n============ �ð�ǥ (�й� : %d) ============\n", mID);
	printf("\t%-20s%-12s%-12s\n", "�������", "���ǽð�", "���ǽ�");
	printf("====================================================\n");
	printf("\t%-20s%-12s%-12s\n", "C���α׷���", "��6��5", "��401");
	printf("\t%-20s%-12s%-12s\n", "�ý������α׷���", "��12", "��514");
	printf("\n");

}


int main()
{
	int id=0, sel=0;
	printf("1. �й� �Է�\n");
	printf("2. �ð�ǥ Ȯ��\n");
	printf("3. ����\n");

	while(1) // ���ѷ���
	{
		printf(">> select : ");
		scanf("%d", &sel);
		switch(sel)
		{
        case 1:
			id=setID(); // id���� setID���� ��ȯ�� ������ ����
			continue;

		case 2:
			if(id==0){
				printf("�й��� ���� �Է��ϼ���\n");
			continue;} // �й��� �Էµ����ʾ����Ƿ� �й����� �Է�

			printfTimeTable(id); // mID �� id ����

		case 3:
			break; //����ġ�� Ż��
		
		default:
			continue; // �ٸ������� �ٽ� �Է�

		}

		if(sel==3)
			break; // sel�� 3�϶� while �� Ż��
	}

	return 0;
}