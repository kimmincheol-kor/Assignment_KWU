#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void main()
{
	int menu;
	int i=0;
	PhoneBook *pDelete;

	Phonebook_Load(); // 저장된 파일 불러오기

while(1) // 7번 입력시 까지 반복
{
	puts("========Phone Book========");
	puts("1. Insert");
	puts("2. Update");
	puts("3. Delete");
	puts("4. Search");
	puts("5. Print");
	puts("6. Save");
	puts("7. Exit");
	puts("==========================");

	printf("Choose the item: ");
	scanf("%d", &menu);
	fflush(stdin);
	printf("\n");

	

	switch(menu)
	{
	case 1: 
		if(Insert()==1)
		{
			puts("\nSuccess: Insert\n");
			break;
		}
		else
			break;	

	case 2:
		if(Update()==1)
		{
			puts("\nSuccess: Update\n");
			break;
		}
		else
			break;	

	case 3:
		pDelete=Delete();
		if(pDelete==NULL)
			break;
		else
		{
			puts("\nSuccess: Delete\n");
			free(pDelete);
			break;
		}

	case 4:
		if(Search()==1)
		{
			puts("\nSuccess: Search\n");
			break;
		}
		else
			break;

	case 5: 
		if(Print()==1)
		{
			puts("\nSuccess: Print\n");
			break;
		}
		else
			break;

	case 6:
		if(Save()==1)
		{
			puts("\nSuccess: Save\n");
			break;
		}
		else
			break;

	case 7:
		Free_memory(); // 메모리 해제
		puts("메모리 해제 완료!\n");
		return; // 프로그램 종료

	default: 
		puts("잘못된 번호입니다.\n");
	} // switch 문 끝
} // while 문 끝
}