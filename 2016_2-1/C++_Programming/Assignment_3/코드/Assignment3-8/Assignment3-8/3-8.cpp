#include <iostream>
using namespace std;

class Student
{
private:
	char m_name[30]; // 이름
	char m_id[30]; // 학번
	char m_sex[10]; // 성별
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

	void operator+ (Student &add) // 노드 추가
	{
		Student * pNew = new Student;

		// 추가하려는 노드의 정보
		pNew->Setname(add.Getname());
		pNew->Setid(add.Getid());
		pNew->Setsex(add.Getsex());

		if(pHead==NULL) // 첫 입력
		{
			pHead=pNew;
		}
		else // 맨 뒤에 입력
		{
			Student * pWork;
			pWork = pHead;

			while(1)
			{
				if(pWork == NULL)
					break;

				if( strcmp(pWork->Getid(),pNew->Getid()) == 0)
				{
					cout << "같은 학번이 존재합니다" << endl;
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

	void operator- (Student &del) // 노드 제거
	{
		Student * pPrev;
		Student * pWork;
		pWork = pHead;

		// pPrev는 pWork의 이전 노드.
		
		while(1)
		{
			if(pWork==NULL)
			{
				cout << "학생 정보가 존재하지 않습니다." << endl;
				break;
			}

			if( ( strcmp(pHead->Getname(), del.Getname()) == 0 ) && ( strcmp(pHead->Getid(), del.Getid()) == 0 ) ) // 맨앞을 제거하는 경우.
			{
				pWork=pHead;
				pHead=pHead->Getnext();

				delete pWork;

				return;
			}

			if( ( strcmp(pWork->Getname(), del.Getname()) == 0 ) && ( strcmp(pWork->Getid(), del.Getid()) == 0 ) ) // 중간을 제거하는 경우 pWork 제거.
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
			cout << "학생 정보가 존재하지 않습니다." << endl;
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

			// 오름차순 정렬
			if( strcmp(pWork->Getname(),p->Getname()) > 0 && n==1) // 이름으로
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
			
			if( strcmp(pWork->Getid(),p->Getid()) > 0 && n==2) // 학번으로
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
				cout <<"제대로 입력하세요." << endl;
				return;
			}

			delete pTemp;
		}

		pWork=pHead;
		while(pWork!=NULL) // 출력
		{
			cout << "이름 : " << pWork->Getname() << endl;
			cout << "학번 : " << pWork->Getid() << endl;
			cout << "성별 : " << pWork->Getsex() << endl;
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
		cout << "메뉴 (0:종료 1:추가 2:제거 3:출력)" << endl;
		cout << "입력 : ";
		cin >> menu;
		cout << "------------------------" << endl;

		switch(menu)
		{
		case 0:
			cout << "종료" << endl;
			break;

		case 1: // 노드 추가
			cout << "이름 : ";
			cin >> name;
			cout << "학번 : ";
			cin >> id;
			cout << "성별 : ";
			cin >> sex;

			input.Setname(name);
			input.Setid(id);
			input.Setsex(sex);

			list+input;

			break;

		case 2: // 노드 제거
			cout << "이름 : ";
			cin >> name;
			cout << "학번 : ";
			cin >> id;

			input.Setname(name);
			input.Setid(id);

			cout << "------------------------" << endl;

			list-input;

			break;

		case 3: // 출력
			cout << "메뉴 (0:종료 1:이름 2:학번)" << endl; // 정렬 방식 : 이름에따라, 학번에따라
			cout << "입력 : ";
			cin >> n;
			cout << "------------------------" << endl;

			list.Shownode(n);
			break;

		default:
			cout << "올바른 값을 입력하세요. (0~3)" << endl;
			break;

		}

		cout << "========================" << endl;

		if(menu==0) // 종료
			break;
	}

	return 0;
}