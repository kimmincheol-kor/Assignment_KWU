// C���α׷��� 1���� �ǽ�����4

#include<stdio.h>

int swap(); // swap �Լ� ����

int main()
{
	char str[256]={0};
	int i,j,last, temp;

	printf("�Է�: ");
	gets(str);

	for(i=0; i<256; i++) // ���ڰ� ����� ���� ã��.
	{
		if(str[i]==0){
			last=i; // �� ���ڼ� = last
			break;}
	}

	if(last%2==0) // ���ڼ��� ¦���̸�
		for(i=0; i<last/2; i++)
		{
			temp=str[last-1-i];
			str[last-1-i]=str[i];
			str[i]=temp;
		}
	if(last%2!=0) // ���ڼ��� Ȧ���̸� ��� ���ڴ� �״��!
		for(i=0; i<last/2; i++)
		{
			if(i!=last/2+1)
			   {temp=str[last-1-i];
				str[last-1-i]=str[i];
				str[i]=temp;}
		}

	
	printf("���: ");
	for(i=0; i<256; i++)
	{
		printf("%c", str[i]); // �迭�� ���

		if(str[i]==0)
			break;
	}
	printf("\n");
}