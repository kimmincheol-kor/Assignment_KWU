#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

PhoneBook *pHead=NULL;

PhoneBook * Delete() // 데이터 노드 삭제
{
	PhoneBook *pWork=pHead;
	PhoneBook *pPrev;
	PhoneBook *pTemp;
	char find[16];

	if(pWork==NULL)
	{
		puts("Error: Empty phone book list\n"); // 저장된 번호가 없습니다
		return NULL;
	}

	printf("Delete phone number: "); // 지울번호 입력
	fflush(stdin);
	gets(find);

	while(pWork!=NULL) // 입력한 번호 찾기
	{
		if(strcmp(find, pWork->number) == 0)
			break;
		pPrev=pWork;
		pWork=pWork->next;
	}
	
	if(pWork==NULL) 
	{
		puts("Error: Not exist phone number"); // 입력하신 번호가 없습니다
		return NULL;
	}
	else
	{
		if(pWork==pHead)
		{
			pHead=pHead->next;
		}
		else
		{
			pPrev->next=pWork->next;
		}
		return pWork;
	}
}

int Insert() // 데이터 노드 삽입 (링크드리스트에 정렬)
{
	char str1[16];
	char str2[16];
	int num;
	int i=0;

	PhoneBook *pWork=NULL;
	PhoneBook *pNew=NULL;
	PhoneBook *pPrev=NULL;

	// 입력
	printf("Name: ");
	gets(str1);
	fflush(stdin);
	printf("Age: ");
	scanf("%d", &num);
	fflush(stdin);
	printf("Phone number<000-0000-0000>: ");
	gets(str2);
	fflush(stdin);

	// 예외처리

	if(str2[3] != '-' || str2[8] != '-')
	{
		puts("Error: wrong form phone number");
		return 0;
	}
	while(i != 12)
	{
		if('0' > str2[i] || str2[i] > '9')
		{
		puts("Error: wrong form phone number");
		return 0;
		}
		else if(i==2 || i==7)
			i+=2;
		else if('0' > str2[12] || str2[12] > '9')
		{
		puts("Error: wrong form phone number");
		return 0;
		}
		else if(str2[13] != NULL)
		{
		puts("Error: wrong form phone number");
		return 0;
		}
		else
			i++;
	}
		
	pWork=pHead;
	while(pWork != NULL)
	{
		if(strcmp(str2, pWork->number) == 0)
		{
		puts("Error: already exist phone number");
		return 0;
		}
		else
			pWork=pWork->next;
	}

	// 예외처리 끝


	pNew = (PhoneBook *)malloc(sizeof(PhoneBook)); // 메모리 동적 할당

	if(pNew == NULL)
	{
		puts("메모리 동적할당 실패\n");
		return 0;
	}

	// pNew에 입력한값 입력
	strcpy(pNew->name, str1);
	strcpy(pNew->number, str2);
	pNew->age=num;

	//이름에 따라서 오름차순 정렬
	if(pHead == NULL)
	{
		pHead=pNew;
		pNew->next=NULL;
	}
	else
	{
		pWork=pHead;
		while(pWork != NULL)
		{
			if(strcmp(pWork->name, pNew->name) > 0 ) break;
			pPrev=pWork;
			pWork=pWork->next;
		}
		if(pWork==pHead)
		{
			pNew->next=pHead;
			pHead=pNew;
		}
		else
		{
			pPrev->next=pNew;
			pNew->next=pWork;
		}
	}
	return 1;
}

int Update() // 데이터 노드 수정
{
	PhoneBook *pWork=pHead;
	PhoneBook *pTemp;
	PhoneBook *pPrev;
	char find[16];
	char ch_name[16];
	char ch_number[16];
	int n;
	int ch_age;
	int i=0;

	if(pWork==NULL)
		{
		puts("Error: Empty phone book list\n");
		return 0;
		}

	printf("Update phone number: ");
	fflush(stdin);
	gets(find);



	while(pWork!=NULL)
	{
		if(strcmp(find, pWork->number) == 0)
			break;
		pPrev=pWork;
		pWork=pWork->next;
	}

	pTemp=pWork; // 바꾸려는 전화번호
	
	if(pTemp==NULL)
	{
		puts("Error: Not exist phone number");
		return 0;
	}
	else
	{
		printf("Update data<1:Name, 2:Age, 3:Phone number>: ");
		scanf("%d", &n);

		// n값에 따라서 수정할 데이터가 달라짐
		switch(n)
		{
		case 1: // 이름 변경
			printf("Update Name: ");
			fflush(stdin);
			gets(ch_name);

			strcpy(pTemp->name, ch_name);

			// 정렬하기
			if(pTemp==pHead)
			{
				pHead=pHead->next;		
			}
			else
			{
				pPrev->next=pWork->next;
			}
			
			pWork=pHead;
			while(pWork != NULL)
			{
				if(strcmp(pWork->name, pTemp->name) > 0 ) break;
				pPrev=pWork;
				pWork=pWork->next;
			}

			pPrev->next=pTemp;
			pTemp->next=pWork;
			// 정렬 끝

			return 1;

		case 2: // 나이 변경
			printf("Update Age: ");
			fflush(stdin);
			scanf("%d", &ch_age);

			pTemp->age=ch_age;
			return 1;

		case 3: // 번호 변경
			printf("Update phone number: ");
			fflush(stdin);
			gets(ch_number);

			// 예외처리

			if(ch_number[3] != '-' || ch_number[8] != '-')
			{
				puts("Error: wrong form phone number");
				return 0;
			}
			while(i != 12)
			{
				if('0' > ch_number[i] || ch_number[i] > '9')
				{
				puts("Error: wrong form phone number");
				return 0;
				}
				else if(i==2 || i==7)
					i+=2;
				else if('0' > ch_number[12] || ch_number[12] > '9')
				{
				puts("Error: wrong form phone number");
				return 0;
				}
				else if(ch_number[13] != NULL)
				{
				puts("Error: wrong form phone number");
				return 0;
				}
				else
					i++;
			}
		
			pWork=pHead;
			while(pWork != NULL)
			{
				if(strcmp(ch_number, pWork->number) == 0)
				{
				puts("Error: already exist phone number");
				return 0;
				}
				else
					pWork=pWork->next;
			}

			// 예외처리 끝

			strcpy(pTemp->number, ch_number);
			return 1;


		default:
			puts("Error: Wrong input");
			return 0;
		}
	}

}

int Search() // 데이터 노드 검색
{
	PhoneBook *pWork=pHead;
	char find[16];
	int no=1;

	if(pWork==NULL)
		{
		puts("Error: Empty phone book list\n");
		return 0;
		}

	// 키워드 입력
	printf("Search Word: ");
	fflush(stdin);
	gets(find); 

	while(pWork != NULL)
	{
		if( strstr(pWork->name, find) != NULL || strstr(pWork->number, find) != NULL)
		{
			if(no==1) // 첫문장일때만.
				printf("%-6s %-12s %-6s %-16s\n", "no.", "Name", "age", "Phone Number");

			printf("%-6d %-12s %-6d %-16s\n", no, pWork->name, pWork->age, pWork->number);
			no++;		
		}
		pWork=pWork->next;
	}

	if(no==1)
	{
		printf("Not exist %s\n\n", find); // 검색된 데이터가 없습니다.
		return 0;
	}
	else
		return 1;
}

int Print() // 데이터 노드 출력
{
	int no=1;
	PhoneBook *pWork=pHead;

	if(pWork==NULL)
	{
		puts("Error: Empty phone book list\n");
		return 0;
	}
	else
	{
	printf("%-6s %-12s %-6s %-16s\n", "no.", "Name", "age", "Phone Number");
	while(pWork!=NULL)
	{
		printf("%-6d %-12s %-6d %-16s\n", no, pWork->name, pWork->age, pWork->number);
		pWork=pWork->next;
		no++;
	}
	printf("\n");
	return 1;
	}
}

int Save() // 링크드 리스트를 파일로 저장
{
	PhoneBook *pWork=pHead;

	FILE *save = fopen("phonebook.txt", "wt"); // write 형식(

	if(save==NULL)
	{
		puts("파일 오픈 실패 !\n");
		return 0;
	}

	if(pWork==NULL)
	{
		puts("Error: Empty phone book list\n");
		return 0;
	}

	while(pWork!=NULL)
	{
		fprintf(save,"%s %d %s\n", pWork->name, pWork->age, pWork->number); // 파일에 입력하기
		pWork=pWork->next;
	}

	fclose(save); // 파일 닫기

	return 1;

}

void Free_memory() // 메모리 해제 함수
{
	PhoneBook *pWork=pHead;

	while(pHead != NULL)
	{
		pWork=pHead; // pHead를 가리킴
		pHead=pHead->next; // pHead의 위치 변경
		free(pWork); // pWork 초기화
	}
}

void Phonebook_Load() // 저장된 데이터 로드
{
	PhoneBook *pWork = pHead;
	PhoneBook *pLoad=NULL;
	PhoneBook *pPrev=NULL;

	FILE *load=fopen("phonebook.txt", "rt");

	if(load==NULL || feof(load)!=0 ) // 파일출력에 실패했거나, 파일의 끝이라면,
	{
		puts("저장된 내용이 없습니다 !\n");
		return;
	}
	else
	{
		while(feof(load)==0) // 파일의 끝이 아니라면
		{
			pLoad = (PhoneBook *)malloc(sizeof(PhoneBook));

			fscanf(load,"%s %d %s\n", pLoad->name, &pLoad->age, pLoad->number); // 불러오기

			// 정렬하기
			if(pHead == NULL)
			{
				pHead=pLoad;
				pLoad->next=NULL;
			}
			else
			{
				pWork=pHead;
				while(pWork != NULL)
				{
					if(strcmp(pWork->name, pLoad->name) > 0 ) break;
					pPrev=pWork;
					pWork=pWork->next;
				}
				if(pWork==pHead)
				{
					pLoad->next=pHead;
					pHead=pLoad;
				}
				else
				{
					pPrev->next=pLoad;
					pLoad->next=pWork;
				}
			}	
		}
			puts("기존 데이터 로드완료 !\n");
	}
	fclose(load);
}