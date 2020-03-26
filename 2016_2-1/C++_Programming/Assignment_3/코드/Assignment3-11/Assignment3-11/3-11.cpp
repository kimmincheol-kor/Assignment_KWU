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

		if(num==0) // ù �з�
		{
			if(pHead==NULL) // ù�Է�
			{
				pHead=pNew;
				return;
			}
			else if(strcmp(pHead->Getkind(), pNew->Getkind()) != 0) // ���� �ٸ� �Է�
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

			for(int i=0; i<num; i++) // ���° �з����� ����
			{
				if(pWork->Getsub()==NULL) // ������ ����ִٸ�,
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

			if( strcmp(pWork->Getkind(), pNew->Getkind()) == 0 ) // ���� ������ �ִٸ�,
			{
				return;
			}

			while(1)
			{
				if( pWork->Getnext() == NULL ) // ���� ������ ���ٸ�,
				{
					pTemp->Setsub(pNew);
					pNew->Setnext(pWork);
					return;
				}
				else if( strcmp(pWork->Getnext()->Getkind(), pNew->Getkind()) == 0 ) // ���� ������ �ִٸ�,
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

	void Select() // �׸� ����
	{
		int menu;
		int s_menu;
		char classify[7][5]={{"��"},{"��"},{"��"},{"��"},{"��"},{"��"},{"��"}};

		// ù ����
		cout << "�޴� (0:���� 1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:��)" << endl;
		cout << "�Է� : ";
		cin >> menu;
		cout << "----------------------------------" << endl;

		if(menu==0)
			return;

		Node * pWork;
		Node * pTemp;
		pWork=pHead;

		// ù ���� �з��� pWork�� ����Ŵ
		for(int i=1; i<menu; i++)
		{
			pWork=pWork->Getsub();
		}

		pTemp=pWork; // �з��� �Ǿ� = pTemp

		while(1)
		{
			pWork=pTemp;
			cout << "[" << classify[menu-1] << "]" << endl;
			menu+=1;

			for(int i=1; pWork!=NULL; i++) // �з� ���� ���
			{
				cout << i << ". " << pWork->Getkind() << endl;
				pWork=pWork->Getnext();
			}
			cout << endl;

			if(menu==8) // ������ �з��� ��� ����.
				break;

			pWork=pTemp;
			cout << "�޴� (0:����";
			for(int i=1; pWork!=NULL; i++) // ������ ���
			{
				cout << " " << i << ":" << pWork->Getkind();
				pWork=pWork->Getnext();
			}
			cout << ")" << endl;

			cout << "�Է� : ";
			cin >> s_menu;
			cout << "----------------------------------" << endl;

			if(s_menu==0)
				break;
			else if(s_menu==1)
			{
				pTemp=pTemp->Getsub(); // ���� �з��� �Ǿ� = pTemp
			}
			else if(s_menu==2)
			{
				pTemp=pTemp->Getnext()->Getsub(); // ���� �з��� �Ǿ� = pTemp
			}
		}
	}

	void Search(char name[])
	{
		cout << name << "��" << endl;
		
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
		cout << "���� �б� ����!" << endl;
		return -1;
	}

	char input[50];
	int line;

	while(!fin.eof()) // ���� �о ����Ʈ�� ����.
	{
		fin.getline(input, 50);

		if(input[0]=='-') // ���ο� ����
		{
			line=0;
			continue;
		}

		if(line==7) // �����̹Ƿ� �׳� ������.
			continue;

		list.Insert(input, line);

		line += 1;
	}

	int menu;
	int s_menu;
	char s_name[50];

	while(1)
	{
		cout << "�޴� (0:���� 1:�׸��� 2:�˻�)" << endl;
		cout << "�Է� : ";
		cin >> menu;
		cout << "----------------------------------" << endl;

		switch(menu)
		{
		case 0:
			cout << "����" << endl << endl;
			break;

		case 1: // �׸� ����
			list.Select();
			break;

		case 2: // �˻�
			cout << "���� �̸� : ";
			cin >> s_name;
			cout << "----------------------------------" << endl;

			list.Search(s_name);

			break;

		default:
			cout <<"�ٽ� �Է��ϼ���." << endl;
			break;
		}
		
		if(menu==0)
			break;
		else
			cout << "==================================" << endl;
	}


}