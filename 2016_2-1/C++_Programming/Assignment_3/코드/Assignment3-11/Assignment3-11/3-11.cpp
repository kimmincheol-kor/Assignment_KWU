#include <iostream>
#include <fstream>
using namespace std;

class Node
{
private:
	char kind[20];
	Node * pNext;
	Node * pSub;

public:
	Node(){pNext=NULL; pSub=NULL;}
	~Node(){}

	void Setkind(char arr[])
	{
		strcpy(kind, arr);
	}

	 void Setnext(Node * next)
	 {
		 pNext=next;
	 }

	 void Setsub(Node * sub)
	 {
		 pSub=sub;
	 }

	 char * Getkind()
	 {
		 return kind;
	 }

	 Node * Getnext()
	 {
		 return pNext;
	 }

	 Node * Getsub()
	 {
		 return pSub;
	 }
};

class Classifier
{
private:
	Node * pHead;

public:
	Classifier(){pHead=NULL;}
	~Classifier()
	{
		Node * pWork;

		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();
			delete pWork;
		}
	}

	void Insert(char arr[], int num)
	{
		Node * pNew = new Node;
		pNew->Setkind(arr);

		if(num==0) // 첫 분류
		{
			if(pHead==NULL) // 첫입력
			{
				pHead=pNew;
				return;
			}
			else if(strcmp(pHead->Getkind(), pNew->Getkind()) != 0) // 헤드와 다른 입력
			{
				pHead->Setnext(NULL);
				pNew->Setnext(pHead);
				pHead=pNew;
				return;
			}
		}
		else
		{
			Node * pWork;
			Node * pTemp;
			Node * pFirst;
			pWork=pHead;

			for(int i=0; i<num; i++) // 몇번째 분류인지 구분
			{
				if(pWork->Getsub()==NULL) // 하위가 비어있다면,
				{
					pWork->Setsub(pNew);
					return;
				}
				else
				{
					pTemp=pWork;
					pWork=pWork->Getsub();
				}
			}

			pFirst=pWork;

			if( strcmp(pWork->Getkind(), pNew->Getkind()) == 0 ) // 같은 정보가 있다면,
			{
				return;
			}

			while(1)
			{
				if( pWork->Getnext() == NULL ) // 같은 정보가 없다면,
				{
					pTemp->Setsub(pNew);
					pNew->Setnext(pWork);
					return;
				}
				else if( strcmp(pWork->Getnext()->Getkind(), pNew->Getkind()) == 0 ) // 같은 정보가 있다면,
				{
					pTemp->Setsub(pWork->Getnext());
					pWork->Setnext(pWork->Getnext()->Getnext());
					pTemp->Getsub()->Setnext(pFirst);

					return;
				}
				else
					pWork=pWork->Getnext();
			}
		}
	}

	void Select() // 항목 선택
	{
		int menu;
		int s_menu;
		char classify[7][5]={{"계"},{"문"},{"강"},{"목"},{"과"},{"속"},{"종"}};

		// 첫 선택
		cout << "메뉴 (0:종료 1:계 2:문 3:강 4:목 5:과 6:속 7:종)" << endl;
		cout << "입력 : ";
		cin >> menu;
		cout << "----------------------------------" << endl;

		if(menu==0)
			return;

		Node * pWork;
		Node * pTemp;
		pWork=pHead;

		// 첫 선택 분류를 pWork가 가리킴
		for(int i=1; i<menu; i++)
		{
			pWork=pWork->Getsub();
		}

		pTemp=pWork; // 분류의 맨앞 = pTemp

		while(1)
		{
			pWork=pTemp;
			cout << "[" << classify[menu-1] << "]" << endl;
			menu+=1;

			for(int i=1; pWork!=NULL; i++) // 분류 종류 출력
			{
				cout << i << ". " << pWork->Getkind() << endl;
				pWork=pWork->Getnext();
			}
			cout << endl;

			if(menu==8) // 마지막 분류인 경우 종료.
				break;

			pWork=pTemp;
			cout << "메뉴 (0:종료";
			for(int i=1; pWork!=NULL; i++) // 선택지 출력
			{
				cout << " " << i << ":" << pWork->Getkind();
				pWork=pWork->Getnext();
			}
			cout << ")" << endl;

			cout << "입력 : ";
			cin >> s_menu;
			cout << "----------------------------------" << endl;

			if(s_menu==0)
				break;
			else if(s_menu==1)
			{
				pTemp=pTemp->Getsub(); // 다음 분류의 맨앞 = pTemp
			}
			else if(s_menu==2)
			{
				pTemp=pTemp->Getnext()->Getsub(); // 다음 분류의 맨앞 = pTemp
			}
		}
	}

	void Search(char name[])
	{
		cout << name << "는" << endl;
		
		while(1)
		{
			
		}
	}
};

int main()
{
	Classifier list;

	ifstream fin;
	fin.open("animal.txt");
	
	if(!fin)
	{
		cout << "파일 읽기 실패!" << endl;
		return -1;
	}

	char input[50];
	int line;

	while(!fin.eof()) // 파일 읽어서 리스트에 저장.
	{
		fin.getline(input, 50);

		if(input[0]=='-') // 새로운 종류
		{
			line=0;
			continue;
		}

		if(line==7) // 빈줄이므로 그냥 지나감.
			continue;

		list.Insert(input, line);

		line += 1;
	}

	int menu;
	int s_menu;
	char s_name[50];

	while(1)
	{
		cout << "메뉴 (0:종료 1:항목선택 2:검색)" << endl;
		cout << "입력 : ";
		cin >> menu;
		cout << "----------------------------------" << endl;

		switch(menu)
		{
		case 0:
			cout << "종료" << endl << endl;
			break;

		case 1: // 항목 선택
			list.Select();
			break;

		case 2: // 검색
			cout << "동물 이름 : ";
			cin >> s_name;
			cout << "----------------------------------" << endl;

			list.Search(s_name);

			break;

		default:
			cout <<"다시 입력하세요." << endl;
			break;
		}
		
		if(menu==0)
			break;
		else
			cout << "==================================" << endl;
	}


}