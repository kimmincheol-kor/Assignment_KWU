// ���C�� 10���� �ǽ�����6

#include <stdio.h>

void main()
{
	FILE * fp;
	char file[32];
	char ch;
	int i=1;

	while(1) // fp ���� �Է�
	{
	printf("����1 �̸�: ");
	scanf("%s", file);
	fp=fopen(file, "rb");
	if(fp==0)
		printf("%s�� �������� �ʽ��ϴ�.\n", file);
	else
		break;
	}

	while(feof(fp)==0)
	{
		fseek(fp, -i, SEEK_END); // �ؽ�Ʈ������ �� ������ �������� i ĭ 
		ch=fgetc(fp);
		printf("%c", ch);

		i++;
	}
	
	fclose(fp);

	printf("\n");
}