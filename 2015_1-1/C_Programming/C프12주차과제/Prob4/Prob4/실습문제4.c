// C���α׷��� 12���� �ǽ�

#include <stdio.h>

void main()
{
	char str[256]={0};
	char find;
	int i=0,j;

	printf(">> ���� �Է�: ");
	gets(str); //str �迭�� ���� �Է�

	printf(">> �˻��� �ܾ��� ù ���� �Է�: ");
	scanf("%c", &find); //find �� �Է�

	printf(">> ");
	while(i<256) // ūwhile
	{
		if(((str[i]==find)||(str[i]==find-32))&&((str[i-1]==' ')||(i==0))){ // str�迭�� ���� find �̰�, (�� ������ �����̰ų�, ù��° �����ΰ��) ���� while ����
			while(str[i]!=' ') // ���� while, ������ ������ ����
			{
				if(str[i]==0)
					break; // ���� while ����
				else{
				printf("%c", str[i]); // �迭�� ���
				i++;} // ��� i�� �����ϴٰ� ����, Ȥ�� 0 ���� ������ ���� 
			}
			printf("\n");
			if(str[i]==' ') // �迭���� ����ϴٰ� ������ ������ ��ü �ݺ��� ����, => �ܾ� �ϳ��� ���
				break; // ū while ����
		}
		else if(str[i]==0){
			printf("%c�� �����ϴ� �ܾ �����ϴ�\n", find);
			break;} // find ���� �ϳ��������� ����
		else{
			i++; // find �����ƴϰ� 0�� �ƴϸ� i�� 1���ؼ� �����
		}
	}
}