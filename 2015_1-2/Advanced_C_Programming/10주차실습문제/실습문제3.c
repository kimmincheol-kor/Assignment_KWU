// ���C���α׷��� 10���� �ǽ�����3

#include <stdio.h>

int main()
{
	char str[30];
	int i;

	FILE * fp=fopen("data.txt", "rt"); // data.txt ���Ͽ���
	if(fp==NULL)
	{
		printf("���Ͽ��� ����!");
		return -1;
	}

	fgets(str, sizeof(str), fp); // str �迭�� fp������ ������ �Է�
	printf("%s \n", str);
	
	fclose(fp);
	return 0;
}