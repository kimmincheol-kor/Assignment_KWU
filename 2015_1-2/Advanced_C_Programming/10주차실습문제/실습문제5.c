// ���C�� 10���� �ǽ�����5

#include <stdio.h>

void main()
{
	FILE *fp1, *fp2;
	char str[128];
	
	while(1) // fp1 ���� �Է�
	{
	printf("����1 �̸�: ");
	scanf("%s", str);
	fp1=fopen(str, "rt");
	if(fp1==0)
		printf("%s�� �������� �ʽ��ϴ�.\n", str);
	else
		break;
	}
	
	while(1) // fp2 ���� �Է�
	{
	printf("����2 �̸�: ");
	scanf("%s", str);
	fp2=fopen(str, "rt");
	if(fp2==0)
		printf("%s�� �������� �ʽ��ϴ�.\n", str);
	else
		break;
	}

	while(feof(fp1)==0) // fp1�� ���� �ƴ϶�� �ݺ�.
	{
		if( fgetc(fp1)!=fgetc(fp2) ) // �� ���ڰ� �ٸ��ų�, fp2�� ���̶��.
		{
			printf("�� ������ ���� �ٸ��ϴ�.\n");
			return;
		}
	} // �ƹ� ���� ���� while�� ���� = �� ������ ���� ����

	printf("�� ������ ���� �����ϴ�.\n");
}