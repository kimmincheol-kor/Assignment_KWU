#include <iostream>
#include <fstream>
using namespace std;

class Station
{
private:
	char * m_name; // ���̸�
	Station * m_Prev; // ���� ��
	Station * m_Next; // ���� ��

public:
	Station(){m_name=NULL; m_Prev=NULL; m_Next=NULL;}
	~Station(){}

	void SetName(char arr[])
	{
		m_name=new char [strlen(arr)];

		for(int i=0; i<255; i++)
		{
			if(arr[i]==NULL)
			{
				m_name[i]='\0';
				break;
			}

			m_name[i]=arr[i];
		}
	}

	void SetPrev(Station * node)
	{
		m_Prev=node;
	}

	void SetNext(Station * node)
	{
		m_Next=node;
	}

	char * GetName()
	{
		return m_name;
	}

	Station * GetPrev()
	{
		return m_Prev;
	}

	Station * GetNext()
	{
		return m_Next;
	}
};

class List
{
private:
	Station * p_Head; // �� �� ��
	Station * p_Tail; // �� �� ��

public:
	List(){p_Head=NULL;}
	~List() // �����Ҵ� ����
	{
		Station * pWork;

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
		Station * pNew = new Station;

		pNew->SetName(arr);

		if(p_Head == NULL) // ù ����
		{
			p_Head=pNew;
			p_Tail=pNew;
		}
		else
		{
			Station * pWork;
			pWork = p_Head;

			while(1)
			{
				if(pWork->GetNext()==NULL) // �� ���� ����
				{
					pWork->SetNext(pNew); // ������ ����
					pNew->SetPrev(pWork); // ������ ����
					p_Tail=pNew; // ���ο� ��尡 �� ��.
					break;
				}
				
				pWork=pWork->GetNext();
			}
		}
	}

	void Navigation(char start[], char end[]) // ��� ã�� �Լ�
	{
		Station * pWork;
		Station * START; // ��߿�
		Station * END; // ������

		int p=0;
		int start_p=0;
		int end_p=0;
		
		pWork = p_Head;

		while(1)
		{
			if(pWork==NULL) // ���������� ��ã�´ٸ�
			{
				cout << "�Է��Ͻ� �� ������ �����ϴ�." << endl;
				return;
			}

			if(strcmp (pWork->GetName() , start) == 0) // ��߿� ����
			{
				start_p=++p; // ����
				START=pWork;
			}
			
			if(strcmp (pWork->GetName() , end) == 0) // ������ ����
			{
				end_p=++p; // ����
				END=pWork;
			}

			if(start_p!=0 && end_p != 0) // ��߿��� �������� ��� �����Ǿ��ٸ�,
			{
				break;
			}

			pWork=pWork->GetNext();
			p+=1;
		}

		if(start_p < end_p) // ������
		{
			ShowList_H(START, END);
			return;
		}
		else if(start_p > end_p) // ������
		{
			ShowList_E(START, END);
			return;
		}
		else // ��ġ
		{
			cout << "�� ���� ��ġ�մϴ�." << endl;
			return;
		}
	}

	void ShowList_H(Station * Start, Station * End) // ������ ���
	{
		Station * pWork;
		pWork = Start;

		while(pWork!=End->GetNext())
		{
			cout << pWork->GetName();

			if(pWork != End)
				cout << " -> ";
			else
				cout << endl;

			pWork=pWork->GetNext();
		}
		cout << endl;
	}
	
	void ShowList_E(Station * Start, Station * End) // ������ ���
	{
		Station * pWork;
		pWork = Start;

		while(pWork!=End->GetPrev())
		{
			cout << pWork->GetName();

			if(pWork != End)
				cout << " -> ";
			else
				cout << endl;

			pWork=pWork->GetPrev();
		}
		cout << endl;
	}
};

int main()
{
	List list;
	int n_station=0; // ���� ����
	char station_p[50];
	char station_n[50];

	ifstream fin;
	fin.open("subway.txt");

	if(!fin)
	{
		cout << "������ ���� �� �����ϴ�." << endl;
		return -1;
	}

	while(!fin.eof())
	{
		fin.getline(station_p, 50, ' '); // ����� ����
		fin.getline(station_n, 50);

		if(n_station==0)
		{
			list.Insert(station_p);
			n_station+=1;
			list.Insert(station_n);
			n_station+=1;
		}
		else
		{
			list.Insert(station_n);
			n_station+=1;
		}
	}

	char start_station[50]; // �����
	char end_station[50]; // ������

	cout << "����� : ";
	cin >> start_station;

	cout << "������ : ";
	cin >> end_station;

	cout << endl;

	// ��θ� ã���ִ� �Լ�
	list.Navigation(start_station, end_station);

	return 0;
}