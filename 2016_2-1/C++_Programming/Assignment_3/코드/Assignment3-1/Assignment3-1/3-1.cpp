#include <iostream>
using namespace std;

class Node 
{
private:
	char *value; // 노드의 값
	Node *Next; // 노드의 다음 값

public:
	Node(){Next=NULL;}
	~Node(){}

	void Setvalue(char arr[]) // 값 설정
	{
		int length=strlen(arr);

		value = new char[length]; // 길이만큼 동적할당

		for(int i=0; i<length; i++)
		{
			value[i]=arr[i];
		}
		value[length]='\0';
	}

	void SetNext(Node * pNext)
	{
		Next=pNext;
	}

	char * Getvalue()
	{
		return value;
	}

	Node * GetNext()
	{
		return Next;
	}
};

class List
{
private:
	Node * pHead;
public:
	List(){pHead=NULL;}
	~List() // 동적할당 해제
	{
		Node * pWork;

		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->GetNext();
			delete pWork;
		}
	}

	void Insert(char arr[])
	{
		Node * pNew = new Node; // 새로운 노드 생성
		pNew->Setvalue(arr);

		if(pHead == NULL) // 첫 입력
		{
			pHead=pNew;
			pNew->SetNext(NULL);
		}
		else // 나중 입력 -> 리스트의 맨앞
		{
			pNew->SetNext(pHead);
			pHead=pNew;
		}
		
		// 링크드리스트 출력
		Node * pWork;
		pWork = pHead;
		while(pWork != NULL)
		{
			cout << pWork->Getvalue();

			if(pWork->GetNext() == NULL)
			{
				cout << endl;
				break;
			}
			else
			{
				cout << " -> ";
				pWork=pWork->GetNext();
			}
		}
	}
};

void main()
{
	List list;
	char arr[100];
	char *p; // 포인터

	int cnt=0;

	while(strcmp(arr, "END") != 0)
	{
		cnt = 0;

		gets(arr); // 문장을 입력받음

		p=arr; // p가 문장을 가리킴

		for(int i=0; i<100; i++)
		{
			if(*(p+i)==NULL) // 다음 문자가 NULL이면 종료
				break;

			if(p[i]==' ') // 띄어쓰기가 나오면
			{
				p[i]='\0'; // NULL로 바꿈 -> p는 문장말고 단어를 가리킴

				list.Insert(p); // 단어 인서트

				cnt += 1;

				p=p+(i+1); // 단어의 다음글자를 가리킴

				i=0; // 다시 p의 맨앞을 가리키기 위해서 0으로 초기화
			}
		}

		if(strcmp(p,"END")==0) // 단어가 END 일 경우 종료
					return;

		list.Insert(p); // 문장의 마지막 단어 인서트
	}
}