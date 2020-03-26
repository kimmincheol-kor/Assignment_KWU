#include <iostream>
using namespace std;

class Node 
{
private:
	char *value; // ����� ��
	Node *Next; // ����� ���� ��

public:
	Node(){Next=NULL;}
	~Node(){}

	void Setvalue(char arr[]) // �� ����
	{
		int length=strlen(arr);

		value = new char[length]; // ���̸�ŭ �����Ҵ�

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
	~List() // �����Ҵ� ����
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
		Node * pNew = new Node; // ���ο� ��� ����
		pNew->Setvalue(arr);

		if(pHead == NULL) // ù �Է�
		{
			pHead=pNew;
			pNew->SetNext(NULL);
		}
		else // ���� �Է� -> ����Ʈ�� �Ǿ�
		{
			pNew->SetNext(pHead);
			pHead=pNew;
		}
		
		// ��ũ�帮��Ʈ ���
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
	char *p; // ������

	int cnt=0;

	while(strcmp(arr, "END") != 0)
	{
		cnt = 0;

		gets(arr); // ������ �Է¹���

		p=arr; // p�� ������ ����Ŵ

		for(int i=0; i<100; i++)
		{
			if(*(p+i)==NULL) // ���� ���ڰ� NULL�̸� ����
				break;

			if(p[i]==' ') // ���Ⱑ ������
			{
				p[i]='\0'; // NULL�� �ٲ� -> p�� ���帻�� �ܾ ����Ŵ

				list.Insert(p); // �ܾ� �μ�Ʈ

				cnt += 1;

				p=p+(i+1); // �ܾ��� �������ڸ� ����Ŵ

				i=0; // �ٽ� p�� �Ǿ��� ����Ű�� ���ؼ� 0���� �ʱ�ȭ
			}
		}

		if(strcmp(p,"END")==0) // �ܾ END �� ��� ����
					return;

		list.Insert(p); // ������ ������ �ܾ� �μ�Ʈ
	}
}