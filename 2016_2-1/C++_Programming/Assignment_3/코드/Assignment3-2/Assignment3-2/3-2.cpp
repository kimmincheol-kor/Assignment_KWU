#include <iostream>
using namespace std;

template <typename T>
class Type
{
private:
	T data; // 타입 클래스의 데이터
	Type * pNext;

public:
	Type(){pNext=NULL;}
	~Type(){}

	void Setdata(T dt)
	{
		data=dt;
	}

	void Setnext(Type * pNew)
	{
		pNext=pNew;
	}

	T Getdata()
	{
		return data;
	}

	Type * Getnext()
	{
		return pNext;
	}

};

template <typename T>
class List
{
private:
	Type<T> * pHead; // T 타입의 포인터

public:
	List(){pHead=NULL;}
	~List() // 동적할당 해제
	{
		Type<T> * pWork;

		while(1)
		{
			pWork=pHead;

			if(pWork==NULL)
				break;

			pHead=pHead->Getnext();
			delete pWork;
		}
	}

	void Insert(T data) // 정수, 실수 인서트
	{
		Type<T> * pNew = new Type<T>; // T 타입의 새로운 데이터 생성
		pNew->Setdata(data);

		if(pHead==NULL)
		{
			pHead=pNew;
		}
		else
		{
			Type<T> * pWork;
			Type<T> * pSmall;
			Type<T> * pBig;

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

	void S_Insert(T data) // 문자열 인서트
	{
		Type<T> * pNew = new Type<T>;
		
		char * word = new char[strlen(data)];
		strcpy(word, data);

		pNew->Setdata(word);

		if(pHead==NULL)
		{
			pHead=pNew;
		}
		else
		{
			Type<T> * pWork;
			Type<T> * pSmall;
			Type<T> * pBig;

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

	void Show() // 리스트 출력 함수
	{
		if(pHead==NULL)
		{
			cout << "노드가 없습니다." << endl;
			return;
		}

		Type<T> * pWork;
		pWork=pHead;

		while(1)
		{
			cout << pWork->Getdata() << " ";

			pWork=pWork->Getnext();
			
			if(pWork==NULL)
			{
				cout << endl;
				break;
			}
		}
	}


};

int main()
{
	char *p;
	char *word;

	int a=0;
	int b=0;
	int c=0;

	List<int> INT;
	List<double> DOUBLE;
	List<char *> STRING;

	while(1)
	{
		char input[255]={'\0',}; // 문자열 초기화
		gets(input); // 입력
		p=input; // p는 리스트의 pWork 같은 역할.

		for(int i=0; *p != NULL; i++)
		{
			a=0; b=0; c=0;
			if(input[i]==' ' || input[i]==NULL)
			{
				word = p; // word는 단어를 가리킴

				input[i]='\0';

				if(strcmp(word ,"END")==0) // END이면 종료
					break;
				
				while(1)
				{
					if(*p==NULL)
					{
						if(b==0 && a!=0 && c==0) // 정수인 경우
						{
							INT.Insert(atoi(word));
						}
						else if(b==0 && a!=0 && c!=0) // 실수인 경우
						{
							DOUBLE.Insert(atof(word));
						}
						else // 문자인 경우
						{
							STRING.S_Insert(word);
						}

						break;
					}

					if(*p=='.') // 점이 있는 경우 c ++
						c+=1;

					if(48 <= *p && 57 >= *p) // 숫자인 경우 a ++
						a+=1;
					else if(*p !='.') // 숫자도 아니고 점도 아닌경우 b ++
						b+=1;

					p+=1; // 다음 문자를 가리킴
				}
				
				p+=1; // 다음 단어를 가리킴
			}
		}
		if(strcmp(word ,"END")==0) // END이면 종료
					break;
	}
	cout << endl << endl;

	cout << "문자열 : ";
	STRING.Show();

	cout << "정수 : ";
	INT.Show();

	cout << "실수 : ";
	DOUBLE.Show();

	return 0;
}