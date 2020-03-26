#include <iostream>
using namespace std;

class Student
{
private:
	char m_name[30]; // �̸�
	char m_id[30]; // �й�
	char m_sex[10]; // ����
	Student * m_next; 

public:
	Student(){m_next=NULL;}
	~Student(){}

	void Setname(char arr[])
	{
		strcpy(m_name, arr);
	}

	void Setid(char arr[])
	{
		strcpy(m_id, arr);
	}

	void Setsex(char arr[])
	{
		strcpy(m_sex, arr);
	}

	void Setnext(Student * Next)
	{
		m_next=Next;
	}

	char * Getname()
	{
		return m_name;
	}
	
	char * Getid()
	{
		return m_id;
	}

	char * Getsex()
	{
		return m_sex;
	}

	Student * Getnext()
	{
		return m_next;
	}
};

class List
{
private:
	Student * pHead;

public:
	List(){pHead=NULL;}
	~List()
	{
		Student * pWork;
		while(1)
		{
			pWork=pHead;
			
			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();
			delete pWork;
		}
	}

	void operator+ (Student &add) // ��� �߰�
	{
		Student * pNew = new Student;

		// �߰��Ϸ��� ����� ����
		pNew->Setname(add.Getname());
		pNew->Setid(add.Getid());
		pNew->Setsex(add.Getsex());

		if(pHead==NULL) // ù �Է�
		{
			pHead=pNew;
		}
		else // �� �ڿ� �Է�
		{
			Student * pWork;
			pWork = pHead;

			while(1)
			{
				if(pWork == NULL)
					break;

				if( strcmp(pWork->Getid(),pNew->Getid()) == 0)
				{
					cout << "���� �й��� �����մϴ�" << endl;
					delete pNew;
					return;
				}
				else
					pWork=pWork->Getnext();
			}

			pWork=pHead;
			while(1)
			{
				if(pWork->Getnext()==NULL)
				{
					pWork->Setnext(pNew);
					break;
				}
				else
					pWork=pWork->Getnext();
			}
		}
	}

	void operator- (Student &del) // ��� ����
	{
		Student * pPrev;
		Student * pWork;
		pWork = pHead;

		// pPrev�� pWork�� ���� ���.
		
		while(1)
		{
			if(pWork==NULL)
			{
				cout << "�л� ������ �������� �ʽ��ϴ�." << endl;
				break;
			}

			if( ( strcmp(pHead->Getname(), del.Getname()) == 0 ) && ( strcmp(pHead->Getid(), del.Getid()) == 0 ) ) // �Ǿ��� �����ϴ� ���.
			{
				pWork=pHead;
				pHead=pHead->Getnext();

				delete pWork;

				return;
			}

			if( ( strcmp(pWork->Getname(), del.Getname()) == 0 ) && ( strcmp(pWork->Getid(), del.Getid()) == 0 ) ) // �߰��� �����ϴ� ��� pWork ����.
			{
				pPrev->Setnext(pWork->Getnext());
				delete pWork;
				return;
			}
			else
			{
				pPrev=pWork;
			}

			pWork=pWork->Getnext();
		}
	}

	void Shownode(int n)
	{
		if(pHead == NULL)
		{
			cout << "�л� ������ �������� �ʽ��ϴ�." << endl;
			return ;
		}
		Student * pWork;
		Student * p;
		pWork = pHead;
		p = pWork;

		while(1)
		{
			Student * pTemp = new Student;

			p=p->Getnext();
			
			if(p==NULL)
			{
				if( pWork->Getnext() == NULL )
					break;

				pWork=pWork->Getnext();
				p=pWork;
				continue;
			}

			// �������� ����
			if( strcmp(pWork->Getname(),p->Getname()) > 0 && n==1) // �̸�����
			{
				pTemp->Setname(pWork->Getname());
				pTemp->Setid(pWork->Getid());
				pTemp->Setsex(pWork->Getsex());
				
				pWork->Setname(p->Getname());
				pWork->Setid(p->Getid());
				pWork->Setsex(p->Getsex());
				
				p->Setname(pTemp->Getname());
				p->Setid(pTemp->Getid());
				p->Setsex(pTemp->Getsex());

				continue;
			}
			
			if( strcmp(pWork->Getid(),p->Getid()) > 0 && n==2) // �й�����
			{
				pTemp->Setname(pWork->Getname());
				pTemp->Setid(pWork->Getid());
				pTemp->Setsex(pWork->Getsex());
				
				pWork->Setname(p->Getname());
				pWork->Setid(p->Getid());
				pWork->Setsex(p->Getsex());
				
				p->Setname(pTemp->Getname());
				p->Setid(pTemp->Getid());
				p->Setsex(pTemp->Getsex());

				continue;
			}
			
			if(n==0)
				return;
			
			if(n!=0 && n!=1 && n!=2)
			{
				cout <<"����� �Է��ϼ���." << endl;
				return;
			}

			delete pTemp;
		}

		pWork=pHead;
		while(pWork!=NULL) // ���
		{
			cout << "�̸� : " << pWork->Getname() << endl;
			cout << "�й� : " << pWork->Getid() << endl;
			cout << "���� : " << pWork->Getsex() << endl;
			cout << endl;

			pWork=pWork->Getnext();
		}
	}
};

int main()
{
	List list;
	int menu, n;
	Student input;
	char name[30], id[30], sex[10];

	while(1)
	{
		cout << "�޴� (0:���� 1:�߰� 2:���� 3:���)" << endl;
		cout << "�Է� : ";
		cin >> menu;
		cout << "------------------------" << endl;

		switch(menu)
		{
		case 0:
			cout << "����" << endl;
			break;

		case 1: // ��� �߰�
			cout << "�̸� : ";
			cin >> name;
			cout << "�й� : ";
			cin >> id;
			cout << "���� : ";
			cin >> sex;

			input.Setname(name);
			input.Setid(id);
			input.Setsex(sex);

			list+input;

			break;

		case 2: // ��� ����
			cout << "�̸� : ";
			cin >> name;
			cout << "�й� : ";
			cin >> id;

			input.Setname(name);
			input.Setid(id);

			cout << "------------------------" << endl;

			list-input;

			break;

		case 3: // ���
			cout << "�޴� (0:���� 1:�̸� 2:�й�)" << endl; // ���� ��� : �̸�������, �й�������
			cout << "�Է� : ";
			cin >> n;
			cout << "------------------------" << endl;

			list.Shownode(n);
			break;

		default:
			cout << "�ùٸ� ���� �Է��ϼ���. (0~3)" << endl;
			break;

		}

		cout << "========================" << endl;

		if(menu==0) // ����
			break;
	}

	return 0;
}