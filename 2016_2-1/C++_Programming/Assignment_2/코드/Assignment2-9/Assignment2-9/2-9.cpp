#include <iostream>
using namespace std;

class Student
{
private:
	char s_Name[15];
	int s_Number;
	Student * s_pNext;

public:
	Student(){s_pNext=NULL;};
	~Student(){};

	void setName(char * name)
	{
		for(int i=0; i<15; i++)
		{
			s_Name[i]=name[i];

			if(name[i]=='\0')
				break;
		}
	}

	void setNumber(int number)
	{
		s_Number=number;
	}
	
	void setNext(Student * pNext)
	{
		s_pNext=pNext;

	}

	char *getName()
	{
		return s_Name;
	}
	
	int getNumber()
	{
		return s_Number;
	}
	
	Student * getNext()
	{
		return s_pNext;
	}
};

class StudentList
{
private:
	Student * s_pHead;

public:
	StudentList(){s_pHead=NULL;}
	~StudentList(){}

	void Insert(char * name, int number)
	{
		if(s_pHead==NULL) // 첫 입력
		{
			Student * pNew = new Student;

			pNew->setName(name);
			pNew->setNumber(number);

			s_pHead=pNew;
		}
		else 
		{
			Student * pWork;
			pWork = s_pHead;
			
			while(1)
			{
				if(pWork->getNumber() == number)
				{
					cout << "Same Student ID is exist." << endl;
					return ; 
				}

				if(pWork->getNext()==NULL)
					break;
				else
					pWork=pWork->getNext();
			}
			
			Student * pNew = new Student;
			pNew->setName(name);
			pNew->setNumber(number);

			pWork=s_pHead;
			while(1)
			{
				if(pWork->getNext()==NULL)
				{
					pWork->setNext(pNew);
					break;
				}
				else
					pWork=pWork->getNext();
			}
		}
		cout << endl;
	}
	
	void Search(char * name)
	{
		cout << "< Result of Search >" << endl;
		Student * pWork;
		pWork = s_pHead;

		while(1)
		{
			if(strcmp(pWork->getName(),name)==0)
			{
				cout << "Name : " << pWork->getName() << endl;
				cout << "ID : " << pWork->getNumber() << endl;
			}

			if(pWork->getNext()==NULL)
				break;
			else
				pWork=pWork->getNext();
		}
	}
	
	void Search(char * name, int number)
	{
		cout << "< Result of Search >" << endl;
		Student * pWork;
		pWork = s_pHead;

		while(1)
		{
			if( ( strcmp(pWork->getName(),name)==0 ) && ( pWork->getNumber() == number ) )
			{
				cout << "Name : " << pWork->getName() << endl;
				cout << "ID : " << pWork->getNumber() << endl;
			}

			if(pWork->getNext()==NULL)
				break;
			else
				pWork=pWork->getNext();
		}
		cout << endl;
	}
	
	void Sort()
	{
		Student * pWork;
		Student * pTemp = new Student;
		Student * p;
		pWork = s_pHead;
		p = pWork->getNext();

		while(1)
		{
			p=p->getNext();
			
			if(p==NULL)
			{
				if( pWork->getNext() == NULL )
					break;

				pWork=pWork->getNext();
				p=pWork;
				continue;
			}

			// 오름차순 정렬
			if( strcmp(pWork->getName(),p->getName()) > 0 )
			{
				pTemp->setName(pWork->getName());
				pTemp->setNumber(pWork->getNumber());
				
				pWork->setName(p->getName());
				pWork->setNumber(p->getNumber());
				
				p->setName(pTemp->getName());
				p->setNumber(pTemp->getNumber());

				continue;
			}
		}
	}
	
	void PrintAll()
	{
		Student * pWork;
		pWork=s_pHead;

		cout << " << PRINT ALL OF STUDENT >>" << endl ;

		while(1)
		{
			cout << "*Student Information" << endl;
			cout << "Student Name : " << pWork->getName() << endl;
			cout << "Student Number : " << pWork->getNumber() << endl ;

			if(pWork->getNext()==NULL)
				break;
			else
				pWork=pWork->getNext();

			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
	int menu;
	char name[15];
	int num;
	StudentList list;

	cout << "Welcome to Student information management Program^^" << endl;

	while(1)
	{
		cout << "====MENU====\n1.Insert\n2.Search\n3.Sort\n4.PrintAll\n5.Exit\nInput Menu : ";
		cin >> menu;
		cout << endl;

		switch(menu)
		{
		case 1:
			cout << "<INSERT>" << endl;
			cout << "Student Name : " ;
			cin >> name;
			cout << "Student Number : " ;
			cin >> num;

			list.Insert(name, num);
			break;

		case 2:
			cout << "SEARCH" << endl;
			cout << "Student Name : ";
			cin >> name;

			int wish;
			cout << "Do you want to find information with Student ID ?( Yes=1 , No=Anykey ): ";
			cin >> wish;

			if(wish==1)
			{
				cout << "Student Number : " ;
				cin >> num;

				list.Search(name, num);
			}
			else
			{
				list.Search(name);
			}
			break;

		case 3:
			list.Sort();
			break;

		case 4:
			list.PrintAll();
			break;

		case 5:
			return 0;

		default:
			cout << "Try again range <1~4>" << endl;
			break;
		}
	}
}