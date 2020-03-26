#include <iostream>
#include <fstream>
using namespace std;

class Char
{
private:
	char ch;
	Char * pNext;
	Char * pPrev;

public:
	Char(){ch=NULL;pNext=NULL;pPrev=NULL;}
	~Char(){}

	void Setch(char c)
	{
		this->ch=c;
	}

	void Setnext(Char * next)
	{
		this->pNext=next;
	}

	void Setprev(Char * next)
	{
		this->pPrev=next;
	}

	char Getch()
	{
		return ch;
	}

	Char * Getnext()
	{
		return pNext;
	}

	Char * Getprev()
	{
		return pPrev;
	}
};

class List
{
public:
	Char * pHead;
	Char * pTail;

	List(){pHead=NULL;}
	~List()
	{
		Char * pWork;
		
		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();

			delete pWork;
		}
	}

	void Push(char c)
	{
		Char * pNew = new Char;
		pNew->Setch(c);

		if(pHead==NULL)
		{
			pHead=pNew;
			pTail=pHead;
		}
		else // 맨앞에 삽입
		{
			pNew->Setnext(pHead);
			pHead->Setprev(pNew);
			pHead=pNew;
		}
	}
};

class Queue : public List // 상속
{
public:
	Queue(){}
	~Queue()
	{
		Char * pWork;
		
		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();

			delete pWork;
		}
	}

	char Pop()
	{
		Char * pWork;
		pWork=pTail;

		pTail=pTail->Getprev();

		return pWork->Getch();
	}
};

class Stack : public List // 상속
{
public:
	Stack(){}
	~Stack()
	{
		Char * pWork;
		
		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();

			delete pWork;
		}
	}

	char Pop()
	{
		Char * pWork;
		pWork=pHead;

		pHead=pHead->Getnext();

		return pWork->Getch();
	}
};

int main()
{
	char arr[100];
	Queue que;
	Stack stk;
	int length;

	ifstream fin;
	fin.open("inheritance.txt");

	if(!fin)
	{
		cout << "파일 오픈 실패!" << endl;
		return -1;
	}

	while(!fin.eof())
	{
		fin.getline(arr, 100);

		length=strlen(arr);

		for(int i=0; i<length; i++)
		{
			que.Push(arr[i]);
			stk.Push(arr[i]);
		}
	}

	cout << "Queue : ";
	for(int i=0; i<length; i++)
	{
		cout << que.Pop();
	}
	cout << endl;

	cout << "Stack : ";
	for(int i=0; i<length; i++)
	{
		cout << stk.Pop();
	}
	cout << endl;

	return 0;
}