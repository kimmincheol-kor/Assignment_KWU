#include <iostream>
using namespace std;

template <typename T>
class Type
{
private:
	T data; // Ÿ�� Ŭ������ ������
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
	Type<T> * pHead; // T Ÿ���� ������

public:
	List(){pHead=NULL;}
	~List() // �����Ҵ� ����
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

	void Insert(T data) // ����, �Ǽ� �μ�Ʈ
	{
		Type<T> * pNew = new Type<T>; // T Ÿ���� ���ο� ������ ����
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
				if( pNew->Getdata() < pHead->Getdata()) // ��庸�� ������,
				{
					pNew->Setnext(pHead);
					pHead=pNew;
					break;
				}
				
				if( pWork->Getnext() == NULL) // ������ Ŭ��,
				{
					pWork->Setnext(pNew);
					break;
				}

				if( pNew->Getdata() < pWork->Getnext()->Getdata() && pNew->Getdata() >= pWork->Getdata() ) // ���̿� ����,
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

	void S_Insert(T data) // ���ڿ� �μ�Ʈ
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
				if( strcmp( pNew->Getdata() , pHead->Getdata() ) <= 0 ) // ��庸�� ������,
				{
					pNew->Setnext(pHead);
					pHead=pNew;
					break;
				}
				
				if( pWork->Getnext() == NULL) // ������ Ŭ��,
				{
					pWork -> Setnext(pNew);
					break;
				}

				if( strcmp( pNew->Getdata() , pWork->Getnext()->Getdata() ) <= 0 && strcmp( pNew->Getdata() , pWork->Getdata() ) >= 0 ) // ���̿� ����,
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

	void Show() // ����Ʈ ��� �Լ�
	{
		if(pHead==NULL)
		{
			cout << "��尡 �����ϴ�." << endl;
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
		char input[255]={'\0',}; // ���ڿ� �ʱ�ȭ
		gets(input); // �Է�
		p=input; // p�� ����Ʈ�� pWork ���� ����.

		for(int i=0; *p != NULL; i++)
		{
			a=0; b=0; c=0;
			if(input[i]==' ' || input[i]==NULL)
			{
				word = p; // word�� �ܾ ����Ŵ

				input[i]='\0';

				if(strcmp(word ,"END")==0) // END�̸� ����
					break;
				
				while(1)
				{
					if(*p==NULL)
					{
						if(b==0 && a!=0 && c==0) // ������ ���
						{
							INT.Insert(atoi(word));
						}
						else if(b==0 && a!=0 && c!=0) // �Ǽ��� ���
						{
							DOUBLE.Insert(atof(word));
						}
						else // ������ ���
						{
							STRING.S_Insert(word);
						}

						break;
					}

					if(*p=='.') // ���� �ִ� ��� c ++
						c+=1;

					if(48 <= *p && 57 >= *p) // ������ ��� a ++
						a+=1;
					else if(*p !='.') // ���ڵ� �ƴϰ� ���� �ƴѰ�� b ++
						b+=1;

					p+=1; // ���� ���ڸ� ����Ŵ
				}
				
				p+=1; // ���� �ܾ ����Ŵ
			}
		}
		if(strcmp(word ,"END")==0) // END�̸� ����
					break;
	}
	cout << endl << endl;

	cout << "���ڿ� : ";
	STRING.Show();

	cout << "���� : ";
	INT.Show();

	cout << "�Ǽ� : ";
	DOUBLE.Show();

	return 0;
}