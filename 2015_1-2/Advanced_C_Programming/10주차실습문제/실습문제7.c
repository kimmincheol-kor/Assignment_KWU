// ���C�� 10���� �ǽ�����7

#include <stdio.h>

void Insert();
void menu();
void Print();
void Search();

typedef struct book
{
	char title[32];
	char writer[32];
	char publisher[32];
}Book;

void main()
{
	int n;

	while(1)
	{
		menu();
		printf("��ȣ�� �Է��Ͻÿ�: ");
		scanf("%d", &n);

		switch(n)
		{
		case 1: Insert(); break;
		case 2: Search(); break;		
		case 3: Print(); break;
		case 4: return;
		default: puts("\n�߸��� ��ȣ�Դϴ�.\n");
		}
	}
}

void menu()
{
	puts("==========");
	puts("1. �Է�");
	puts("2. Ž��");
	puts("3. ���");
	puts("4. ����");
	puts("==========");
}

void Insert() // �Է� �Լ�
{
	Book book;
	FILE *fp=fopen("book.txt", "a");
	

	printf("å ����: ");
	scanf("%s", book.title);
	printf("����: ");
	scanf("%s", book.writer);
	printf("���ǻ�: ");
	scanf("%s", book.publisher);

	fwrite((void *)&book, sizeof(book), 1, fp);

	fclose(fp);
}

void Search() // Ž�� �Լ�
{
	Book book;
	FILE *fp=fopen("book.txt", "rb");
	char keyword[32];
	int cnt=0;

	printf("Ű����: ");
	scanf("%s", keyword);

	if(fp == NULL)
	{
		puts("������ �������� �ʽ��ϴ�.");
		return;
	}
	else
	{
		while(feof(fp)==0)
		{
			fread((void *)&book, sizeof(book), 1, fp);
			if((book.title==keyword)||(book.writer==keyword)||(book.publisher==keyword))
			{
				printf("%-10s %-10s %-10s\n","����","����","���ǻ�");
				printf("%-10s%-10s%-10s\n", book.title, book.writer, book.publisher);
				cnt++;
			}
		}

		fclose(fp);
	}
	
	if(cnt==0) // keyword�� ���� ������ ���ٸ�
		printf("Not exist %s\n", keyword);
}
void Print()
{
	Book book;
	FILE *fp=fopen("book.txt", "rb");
	int cnt=0;

	if(fp==NULL)
	{
		puts("������ �������� �ʽ��ϴ�.");
		return;
	}
	else
	{
		printf("%-10s %-10s %-10s\n","����","����","���ǻ�");
		while(feof(fp)==0)
		{
			fread((void *)&book, sizeof(book), 1, fp);
			printf("%-10s%-10s%-10s\n", book.title, book.writer, book.publisher);
		}

		 fclose(fp);
	}
}