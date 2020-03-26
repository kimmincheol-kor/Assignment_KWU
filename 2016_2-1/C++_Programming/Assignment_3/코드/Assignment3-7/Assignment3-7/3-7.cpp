#include <iostream>
#include <fstream>
using namespace std;

class Acbook
{
private:
	char kind[10]; // �����ΰ� �����ΰ�
	int value; // ��
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

	Acbook operator+ (Acbook &ac) // �� ��带 ���ϴ� �Լ�
	{
		Acbook result;
		
		if(strcmp(ac.Getkind(), "income")==0) // ����
		{
			result.Setkind("income");
			result.Setvalue(this->Getvalue() + ac.Getvalue());
		}
		else if(strcmp(ac.Getkind(), "expend")==0) // ����
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
	
		ifstream fin; // ���� �б�
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
		ofstream fout; // ���Ͽ� ���
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

		if(pHead==NULL) // ù �Է�
		{
			pHead=pNew;
		}
		else // �ƴϸ� �ǵڿ� �Է�
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

	int Calc() // ��� �Լ�
	{
		Acbook * Result = new Acbook; // ��� ���

		// �ʱⰪ
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

			if(Result->Getvalue() < 0) // ��� ����
				cout << "��� : �ܰ� 0�� �����Դϴ�" << endl;
	
			pHead=pHead->Getnext();

			delete pWork; // ����� ��� �����Ҵ� ����.
		}

		if(Result->Getvalue() < 0) // ���� ���� ���̳ʽ��� ���.
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
			cout << "�ٽ� �Է��ϼ���" << endl;
			break;
		}
	}

	return 0;
}