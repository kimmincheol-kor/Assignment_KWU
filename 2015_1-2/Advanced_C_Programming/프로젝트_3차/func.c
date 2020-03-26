#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

PhoneBook *pHead=NULL;

PhoneBook * Delete() // ������ ��� ����
{
	PhoneBook *pWork=pHead;
	PhoneBook *pPrev;
	PhoneBook *pTemp;
	char find[16];

	if(pWork==NULL)
	{
		puts("Error: Empty phone book list\n"); // ����� ��ȣ�� �����ϴ�
		return NULL;
	}

	printf("Delete phone number: "); // �����ȣ �Է�
	fflush(stdin);
	gets(find);

	while(pWork!=NULL) // �Է��� ��ȣ ã��
	{
		if(strcmp(find, pWork->number) == 0)
			break;
		pPrev=pWork;
		pWork=pWork->next;
	}
	
	if(pWork==NULL) 
	{
		puts("Error: Not exist phone number"); // �Է��Ͻ� ��ȣ�� �����ϴ�
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

int Insert() // ������ ��� ���� (��ũ�帮��Ʈ�� ����)
{
	char str1[16];
	char str2[16];
	int num;
	int i=0;

	PhoneBook *pWork=NULL;
	PhoneBook *pNew=NULL;
	PhoneBook *pPrev=NULL;

	// �Է�
	printf("Name: ");
	gets(str1);
	fflush(stdin);
	printf("Age: ");
	scanf("%d", &num);
	fflush(stdin);
	printf("Phone number<000-0000-0000>: ");
	gets(str2);
	fflush(stdin);

	// ����ó��

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

	// ����ó�� ��


	pNew = (PhoneBook *)malloc(sizeof(PhoneBook)); // �޸� ���� �Ҵ�

	if(pNew == NULL)
	{
		puts("�޸� �����Ҵ� ����\n");
		return 0;
	}

	// pNew�� �Է��Ѱ� �Է�
	strcpy(pNew->name, str1);
	strcpy(pNew->number, str2);
	pNew->age=num;

	//�̸��� ���� �������� ����
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

int Update() // ������ ��� ����
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

	pTemp=pWork; // �ٲٷ��� ��ȭ��ȣ
	
	if(pTemp==NULL)
	{
		puts("Error: Not exist phone number");
		return 0;
	}
	else
	{
		printf("Update data<1:Name, 2:Age, 3:Phone number>: ");
		scanf("%d", &n);

		// n���� ���� ������ �����Ͱ� �޶���
		switch(n)
		{
		case 1: // �̸� ����
			printf("Update Name: ");
			fflush(stdin);
			gets(ch_name);

			strcpy(pTemp->name, ch_name);

			// �����ϱ�
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
			// ���� ��

			return 1;

		case 2: // ���� ����
			printf("Update Age: ");
			fflush(stdin);
			scanf("%d", &ch_age);

			pTemp->age=ch_age;
			return 1;

		case 3: // ��ȣ ����
			printf("Update phone number: ");
			fflush(stdin);
			gets(ch_number);

			// ����ó��

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

			// ����ó�� ��

			strcpy(pTemp->number, ch_number);
			return 1;


		default:
			puts("Error: Wrong input");
			return 0;
		}
	}

}

int Search() // ������ ��� �˻�
{
	PhoneBook *pWork=pHead;
	char find[16];
	int no=1;

	if(pWork==NULL)
		{
		puts("Error: Empty phone book list\n");
		return 0;
		}

	// Ű���� �Է�
	printf("Search Word: ");
	fflush(stdin);
	gets(find); 

	while(pWork != NULL)
	{
		if( strstr(pWork->name, find) != NULL || strstr(pWork->number, find) != NULL)
		{
			if(no==1) // ù�����϶���.
				printf("%-6s %-12s %-6s %-16s\n", "no.", "Name", "age", "Phone Number");

			printf("%-6d %-12s %-6d %-16s\n", no, pWork->name, pWork->age, pWork->number);
			no++;		
		}
		pWork=pWork->next;
	}

	if(no==1)
	{
		printf("Not exist %s\n\n", find); // �˻��� �����Ͱ� �����ϴ�.
		return 0;
	}
	else
		return 1;
}

int Print() // ������ ��� ���
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

int Save() // ��ũ�� ����Ʈ�� ���Ϸ� ����
{
	PhoneBook *pWork=pHead;

	FILE *save = fopen("phonebook.txt", "wt"); // write ����(

	if(save==NULL)
	{
		puts("���� ���� ���� !\n");
		return 0;
	}

	if(pWork==NULL)
	{
		puts("Error: Empty phone book list\n");
		return 0;
	}

	while(pWork!=NULL)
	{
		fprintf(save,"%s %d %s\n", pWork->name, pWork->age, pWork->number); // ���Ͽ� �Է��ϱ�
		pWork=pWork->next;
	}

	fclose(save); // ���� �ݱ�

	return 1;

}

void Free_memory() // �޸� ���� �Լ�
{
	PhoneBook *pWork=pHead;

	while(pHead != NULL)
	{
		pWork=pHead; // pHead�� ����Ŵ
		pHead=pHead->next; // pHead�� ��ġ ����
		free(pWork); // pWork �ʱ�ȭ
	}
}

void Phonebook_Load() // ����� ������ �ε�
{
	PhoneBook *pWork = pHead;
	PhoneBook *pLoad=NULL;
	PhoneBook *pPrev=NULL;

	FILE *load=fopen("phonebook.txt", "rt");

	if(load==NULL || feof(load)!=0 ) // ������¿� �����߰ų�, ������ ���̶��,
	{
		puts("����� ������ �����ϴ� !\n");
		return;
	}
	else
	{
		while(feof(load)==0) // ������ ���� �ƴ϶��
		{
			pLoad = (PhoneBook *)malloc(sizeof(PhoneBook));

			fscanf(load,"%s %d %s\n", pLoad->name, &pLoad->age, pLoad->number); // �ҷ�����

			// �����ϱ�
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
			puts("���� ������ �ε�Ϸ� !\n");
	}
	fclose(load);
}