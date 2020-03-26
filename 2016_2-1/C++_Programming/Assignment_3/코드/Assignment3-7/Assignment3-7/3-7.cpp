#include <iostream>
#include <fstream>
using namespace std;

class Acbook
{
private:
	char kind[10]; // 수입인가 지출인가
	int value; // 값
	Acbook * next;

public:
	Acbook(){next=NULL;}
	~Acbook(){}

	void Setkind(char arr[])
	{
		for(int i=0; i<10; i++)
		{
			kind[i]=arr[i];

			if(arr[i]==NULL)
				break;
		}
	}

	void Setvalue(int n)
	{
		this->value=n;
	}

	void Setnext(Acbook * node)
	{
		this->next=node;
	}

	char * Getkind()
	{
		return kind;
	}

	int Getvalue()
	{
		return value;
	}

	Acbook * Getnext()
	{
		return next;
	}

	Acbook operator+ (Acbook &ac) // 두 노드를 더하는 함수
	{
		Acbook result;
		
		if(strcmp(ac.Getkind(), "income")==0) // 수입
		{
			result.Setkind("income");
			result.Setvalue(this->Getvalue() + ac.Getvalue());
		}
		else if(strcmp(ac.Getkind(), "expend")==0) // 지출
		{
			result.Setkind("income");
			result.Setvalue(this->value - ac.Getvalue());
		}

		return result;
	}
};

class List
{
private:
	Acbook * pHead;

public:
	List(){pHead=NULL;}
	~List()
	{
		Acbook * pWork;

		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();
			delete pWork;
		}
	}

	int Load(List *list)
	{
		char name[50];
		char value[50];
		int n;
		pHead=NULL;
	
		ifstream fin; // 파일 읽기
		fin.open("acbook.txt");
	

		if(!fin)
		{
			return -1;
		}

		while(!fin.eof())
		{
			fin.getline(name, 50, ' ');
			fin.getline(value, 50);
			n=atoi(value);
	
			list->Insert(name, n);
		}
		return 0;
	}

	int Save()
	{
		ofstream fout; // 파일에 출력
		fout.open("acbook.txt");

		if(!fout)
		{
			return -1;
		}

		Acbook * pWork;
		pWork=pHead;

		while(1)
		{
			fout << pWork->Getkind() << " " << pWork->Getvalue();
			pWork=pWork->Getnext();

			if(pWork==NULL)
				break;
			else
				fout << endl;
		}
		return 0;
	}

	int Insert(char arr[], int n)
	{
		Acbook * pNew = new Acbook;

		pNew->Setkind(arr);
		pNew->Setvalue(n);

		if(pHead==NULL) // 첫 입력
		{
			pHead=pNew;
		}
		else // 아니면 맨뒤에 입력
		{
			Acbook * pWork;
			pWork = pHead;

			pWork=pHead;
			while(1)
			{
				if(pWork->Getnext()==NULL)/
				{
					pWork->Setnext(pNew);
					break;
				}
				else
					pWork=pWork->Getnext();
			}
		}

		return 0;
	}

	int Calc() // 계산 함수
	{
		Acbook * Result = new Acbook; // 결과 노드

		// 초기값
		Result->Setkind("income");
		Result->Setvalue(0);
		Result->Setnext(NULL);

		Acbook * pWork;

		while(1)
		{
			pWork = pHead;
			
			if(pWork == NULL)
			{
				break;
			}

			Result->Setkind(Result->operator+(*pWork).Getkind());
			Result->Setvalue(Result->operator+(*pWork).Getvalue());

			if(Result->Getvalue() < 0) // 경고 문구
				cout << "경고 : 잔고가 0원 이하입니다" << endl;
	
			pHead=pHead->Getnext();

			delete pWork; // 사라진 노드 동적할당 해제.
		}

		if(Result->Getvalue() < 0) // 최후 값이 마이너스인 경우.
		{
			Result->Setkind("expend");
			Result->Setvalue(Result->Getvalue() * (-1) );
		}

		pHead=Result;
		pHead->Setnext(NULL);

		return 0;
	}
};

int main()
{
	List list;
	int menu, check;

	cout << "1.Load 2.Save 3.Ins 4.Calc 5.Exit" << endl;
	while(1)
	{
		cin >> menu;
		if(menu == 5)
		{
			cout << "Program termination" << endl;
			break;
		}

		switch(menu)
		{
		case 1:
			check = list.Load(&list);

			if(check==0)
				cout << "Load Complete" << endl;
			else
				cout << "Fail to Load" << endl;
			break;

		case 2:
			check = list.Save();

			if(check==0)
				cout << "Save Complete" << endl;
			else
				cout << "Fail to Save" << endl;
			break;

		case 3:
			char kind[50];
			int num;

			cin >> kind;
			cin >> num;

			check = list.Insert(kind, num);

			if(check==0)
				cout << "Insert Success" << endl;
			else
				cout << "Fail to Insert" << endl;
			break;

		case 4:
			check = list.Calc();

			if(check==0)
				cout << "Calc Success" << endl;
			else
				cout << "Fail to Calc" << endl;
			break;

		default:
			cout << "다시 입력하세요" << endl;
			break;
		}
	}

	return 0;
}