// ���C�� 6���� �ǽ�����4

#include <stdio.h>
#include <string.h>
int atoi(char str[]);

void main()
{
	char str[32]; // �����Է�
	int i;
	char op=0; // ��ȣ

	printf("�����Է�: ");
	gets(str);

	for(i=0; i<32; i++)
	{
		if(str[i]==NULL) // �Է¹������� �迭ĭ�� NULL �̹Ƿ� ����
			break;
		
		if( (str[i]=='+') || (str[i]=='-') || (str[i]=='/') || (str[i]=='*') ) // �迭���� ��Ģ�����ڶ��,
		{
			if(op!=0){ // op�� ����� �ԷµǾ��ٸ�
				printf("�߸��� �������Դϴ�.\n");
				op='1'; // ������ �ִٸ� op='1'
				break;}
			else
				op=str[i];
		}
		
		if( str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && ( str[i]>'9' || str[i]<'0' ) ) // �迭���� ��Ģ�����ڵ� �ƴϰ�, ���ڵ� �ƴ϶��
		{
			printf("�߸��� �������Դϴ�.\n");
			op='1'; // ������ �ִٸ� op='1'
			break;
		}
	}

	if(op==0) // �����������鼭, op�� �ƹ����� �Էµ����ʾҴٸ�,
		printf("�����ڰ� �����ϴ�.\n");


	// ����
	if(op!='1') // ������ ���ٸ�
	{
		for(i=0; i<32; i++) // ����������, �����ڵ� ��Ģ�����̹Ƿ�
		{
			if(str[i]==op)
				break;
		} // �����ڰ� �迭 ���° ĭ�� �ִ��� i �� ����

		if(str[0]==op || str[i+1]==NULL)
			printf("�߸��� �����Դϴ�.\n"); 
		else
		{
		if(op=='+')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)+atoi(str+i+1));
		if(op=='-')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)-atoi(str+i+1));
		if(op=='/')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)/atoi(str+i+1));
		if(op=='*')
			printf("%d %c %d = %d\n", atoi(str), op, atoi(str+i+1), atoi(str)*atoi(str+i+1));
		}
	}
}