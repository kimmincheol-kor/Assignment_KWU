// C ���α׷��� 3���� �ǽ�����6

#include <stdio.h>
#include <string.h>

void reverse();

void main()
{
	char str[32];

	printf("�Է�: ");
	gets(str);

	reverse(str);
	printf("reverse: %s\n", str);
}

void reverse(char arr[]) // ������ �Լ�
{
	int i, temp;
	int last;
	
	for(i=0; i<32; i++) // ���ڰ� ����� ���� ã��.
	{
		if(arr[i]==0){
			last=i; // �� ���ڼ� = last
			break;}
	}

	if(last%2==0) // ���ڼ��� ¦���̸�
		for(i=0; i<last/2; i++)
		{
			temp=arr[last-1-i];
			arr[last-1-i]=arr[i];
			arr[i]=temp;
		}
	if(last%2!=0) // ���ڼ��� Ȧ���̸� ��� ���ڴ� �״��!
		for(i=0; i<last/2; i++)
		{
			if(i!=last/2+1)
			   {temp=arr[last-1-i];
				arr[last-1-i]=arr[i];
				arr[i]=temp;}
		}


}