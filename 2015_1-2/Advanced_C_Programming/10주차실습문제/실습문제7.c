// 고급C프 10주차 실습문제7

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
		printf("번호를 입력하시오: ");
		scanf("%d", &n);

		switch(n)
		{
		case 1: Insert(); break;
		case 2: Search(); break;		
		case 3: Print(); break;
		case 4: return;
		default: puts("\n잘못된 번호입니다.\n");
		}
	}
}

void menu()
{
	puts("==========");
	puts("1. 입력");
	puts("2. 탐색");
	puts("3. 출력");
	puts("4. 종료");
	puts("==========");
}

void Insert() // 입력 함수
{
	Book book;
	FILE *fp=fopen("book.txt", "a");
	

	printf("책 제목: ");
	scanf("%s", book.title);
	printf("저자: ");
	scanf("%s", book.writer);
	printf("출판사: ");
	scanf("%s", book.publisher);

	fwrite((void *)&book, sizeof(book), 1, fp);

	fclose(fp);
}

void Search() // 탐색 함수
{
	Book book;
	FILE *fp=fopen("book.txt", "rb");
	char keyword[32];
	int cnt=0;

	printf("키워드: ");
	scanf("%s", keyword);

	if(fp == NULL)
	{
		puts("파일이 존재하지 않습니다.");
		return;
	}
	else
	{
		while(feof(fp)==0)
		{
			fread((void *)&book, sizeof(book), 1, fp);
			if((book.title==keyword)||(book.writer==keyword)||(book.publisher==keyword))
			{
				printf("%-10s %-10s %-10s\n","제목","저자","출판사");
				printf("%-10s%-10s%-10s\n", book.title, book.writer, book.publisher);
				cnt++;
			}
		}

		fclose(fp);
	}
	
	if(cnt==0) // keyword와 같은 문장이 없다면
		printf("Not exist %s\n", keyword);
}
void Print()
{
	Book book;
	FILE *fp=fopen("book.txt", "rb");
	int cnt=0;

	if(fp==NULL)
	{
		puts("파일이 존재하지 않습니다.");
		return;
	}
	else
	{
		printf("%-10s %-10s %-10s\n","제목","저자","출판사");
		while(feof(fp)==0)
		{
			fread((void *)&book, sizeof(book), 1, fp);
			printf("%-10s%-10s%-10s\n", book.title, book.writer, book.publisher);
		}

		 fclose(fp);
	}
}