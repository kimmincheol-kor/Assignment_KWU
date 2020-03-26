#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
private:
	T data;
	Node * pNext;

public:
	Node(){pNext=NULL;}
	~Node(){}

	void Setdata(T dt)
	{
		data=dt;
	}

	void Setnext(Node * pNew)
	{
		pNext=pNew;
	}

	T Getdata()
	{
		return data;
	}

	Node * Getnext()
	{
		return pNext;
	}
};

template <typename T>
class List
{
private:
	Node<T> * pHead;
	List * L_Next;

public:
	List(){pHead=NULL; L_Next=NULL;}
	~List()
	{
		Node<T> * pWork;
		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();
			delete pWork;
		}
	}

	void Insert(T data)
	{
		Node<T> * pNew = new Node<T>;
		pNew->Setdata(data);

		if(pHead==NULL)
		{
			pHead=pNew;
		}
		else
		{
			Node<T> * pWork;
			Node<T> * pSmall;
			Node<T> * pBig;

			pWork = pHead;
			
			while(1)
			{
				if( pNew->Getdata() < pHead->Getdata()) // 헤드보다 작을때,
				{
					pNew->Setnext(pHead);
					pHead=pNew;
					break;
				}
				
				if( pWork->Getnext() == NULL) // 끝보다 클때,
				{
					pWork->Setnext(pNew);
					break;
				}

				if( pNew->Getdata() < pWork->Getnext()->Getdata() && pNew->Getdata() >= pWork->Getdata() ) // 사이에 낄때,
				{
					pSmall = pWork;
					pBig = pWork->Getnext();

					pSmall->Setnext(pNew);
					pNew->Setnext(pBig);

					break;
				}
				pWork = pWork->Getnext();
			}
		}
	}

	void S_Insert(T data) // 문자열
	{
		Node<T> * pNew = new Node<T>;
		
		char * word = new char[strlen(data)];
		strcpy(word, data);

		pNew->Setdata(word);

		if(pHead==NULL)
		{
			pHead=pNew;
		}
		else
		{
			Node<T> * pWork;
			Node<T> * pSmall;
			Node<T> * pBig;

			pWork = pHead;
			
			while(1)
			{
				if( strcmp( pNew->Getdata() , pHead->Getdata() ) <= 0 ) // 헤드보다 작을때,
				{
					pNew->Setnext(pHead);
					pHead=pNew;
					break;
				}
				
				if( pWork->Getnext() == NULL) // 끝보다 클때,
				{
					pWork -> Setnext(pNew);
					break;
				}

				if( strcmp( pNew->Getdata() , pWork->Getnext()->Getdata() ) <= 0 && strcmp( pNew->Getdata() , pWork->Getdata() ) >= 0 ) // 사이에 낄때,
				{
					pSmall = pWork;
					pBig = pWork->Getnext();

					pSmall->Setnext(pNew);
					pNew->Setnext(pBig);

					break;
				}
				pWork = pWork->Getnext();
			}
		}
	}

	List * nextline()
	{
		L_Next=new List<T>;
		return L_Next;
	}

	List * Getnextline()
	{
		return L_Next;
	}

	void Sort() // 정수 정렬
	{
		List * LWork;
		List * LPrev;
		List * LTemp;

		while(1)
		{
			LWork=this;
			LPrev=NULL;

			int change=0;

			while(1)
			{
				if(LWork->Getnextline()==NULL)
					break;

				if(LWork->Getnextline()->pHead==NULL)
				{
					change += 1; // 변화가 있다.
					LWork->L_Next=LWork->Getnextline()->Getnextline();
					break;
				}

				if(LWork->pHead->Getdata() > LWork->Getnextline()->pHead->Getdata())
				{
					change += 1; // 변화가 있다.
					if(LPrev==NULL) // 첫줄과 두번째줄을 바꿀때
					{
						LTemp=LWork->Getnextline();
						LWork->L_Next=LWork->Getnextline()->Getnextline();
						LTemp->L_Next=LWork;
						
						break;
					}
					else // 중간에서 바꿀때
					{
						LTemp=LWork;
						LPrev->L_Next=LWork->Getnextline();
						LTemp->L_Next=LTemp->Getnextline()->Getnextline();
						LPrev->Getnextline()->L_Next=LTemp;
						break;
					}
				}

				LPrev=LWork;
				LWork=LWork->Getnextline();
			}


			if(change==0) // 변화가 없었다.
				break;
		}
	}

	void S_Sort() // 문자열 정렬
	{
		List * LWork;
		List * LPrev;
		List * LTemp;

		while(1)
		{
			LWork=this;
			LPrev=NULL;

			int change=0;

			while(1)
			{
				if(LWork->Getnextline()==NULL)
					break;

				if(LWork->Getnextline()->pHead==NULL)
				{
					change += 1; // 변화가 있다.
					LWork->L_Next=LWork->Getnextline()->Getnextline();
					break;
				}

				if( strcmp(LWork->pHead->Getdata(), LWork->Getnextline()->pHead->Getdata()) > 0 )
				{
					change += 1; // 변화가 있다.
					if(LPrev==NULL) // 첫줄과 두번째줄을 바꿀때
					{
						LTemp=LWork->Getnextline();
						LWork->L_Next=LWork->Getnextline()->Getnextline();
						LTemp->L_Next=LWork;
						
						break;
					}
					else // 중간을 바꿀때
					{
						LTemp=LWork;
						LPrev->L_Next=LWork->Getnextline();
						LTemp->L_Next=LTemp->Getnextline()->Getnextline();
						LPrev->Getnextline()->L_Next=LTemp;
						break;
					}
				}

				LPrev=LWork;
				LWork=LWork->Getnextline();
			}


			if(change==0) // 변화가 없었다.
				break;
		}
	}

	void Show() // 출력
	{
		Node<T> * pWork;
		pWork=pHead;

		ofstream fout;
		fout.open("result.txt", ios::app);

		while(1)
		{
			if(pWork==NULL)
				break;

			fout << pWork->Getdata() << " ";
			pWork=pWork->Getnext();
		}

		fout.close();
	}
};

int main()
{
	char *p;
	char *word;

	ifstream fin;
	fin.open("input.txt");

	int a=0;
	int b=0;
	int c=0;
	int line=0;

	List<int> INT;
	List<char *> STRING;

	List<int> * pList1;
	List<char *> * pList2;

	pList1=&INT;
	pList2=&STRING;

	while(!fin.eof()) // 파일에 저장된 단어 -> 리스트
	{
		char input[255]={'\0',}; // 문자열 초기화
		fin.getline(input, 255);
		line+=1;
		if(line!=1)
		{
			pList1=pList1->nextline();
			pList2=pList2->nextline();
		}
		p=input; // p는 리스트의 pWork 같은 역할.

		for(int i=0; *p != NULL; i++)
		{
			a=0; b=0; c=0;
			if(input[i]==' ' || input[i]==NULL)
			{
				word = p; // word는 단어를 가리킴

				input[i]='\0';
				
				while(1)
				{
					if(*p==NULL)
					{
						if(b==0 && a!=0 && c==0) // 정수인 경우
						{
							pList1->Insert(atoi(word));
						}
						else if(b==0 && a!=0 && c!=0) // 실수인 경우
						{
							continue;
						}
						else // 문자인 경우
						{
							pList2->S_Insert(word);
						}

						break;
					}

					if(*p=='.')
						c+=1;

					if(48 <= *p && 57 >= *p)
						a+=1;
					else if(*p !='.')
						b+=1;

					p+=1; // 다음 문자
				}
				
				p+=1; // 다음 단어
			}
		}
	}

	fin.close(); // 파일 닫음

	pList1=&INT;
	pList2=&STRING;

	// 리스트 정렬
	pList1->Sort();
	pList2->S_Sort();

	// 파일 초기화
	ofstream reset;
	reset.open("result.txt");

	reset.close();

	// 파일에 출력
	ofstream fout;
	fout.open("result.txt", ios::app); // ios::App 는 파일에 이어쓰기

	for(int i=0; i<line; i++)
	{
		if(pList1!=NULL)
		{
			pList1->Show();
			pList1=pList1->Getnextline();
		}
		
		if(pList2!=NULL)
		{
			pList2->Show();
			pList2=pList2->Getnextline();
		}
		fout << endl;
	}

	fout.close();

	return 0;
}