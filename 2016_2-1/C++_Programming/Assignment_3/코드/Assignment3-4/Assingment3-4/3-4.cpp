#include <iostream>
#include <fstream>
using namespace std;

class Station
{
private:
	char * m_name; // 역이름
	Station * m_Prev; // 이전 역
	Station * m_Next; // 다음 역

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
	Station * p_Head; // 맨 앞 역
	Station * p_Tail; // 맨 끝 역

public:
	List(){p_Head=NULL;}
	~List() // 동적할당 해제
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

		if(p_Head == NULL) // 첫 삽입
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
				if(pWork->GetNext()==NULL) // 맨 끝에 삽입
				{
					pWork->SetNext(pNew); // 다음역 지정
					pNew->SetPrev(pWork); // 이전역 지정
					p_Tail=pNew; // 새로운 노드가 맨 끝.
					break;
				}
				
				pWork=pWork->GetNext();
			}
		}
	}

	void Navigation(char start[], char end[]) // 경로 찾기 함수
	{
		Station * pWork;
		Station * START; // 출발역
		Station * END; // 도착역

		int p=0;
		int start_p=0;
		int end_p=0;
		
		pWork = p_Head;

		while(1)
		{
			if(pWork==NULL) // 끝날때까지 못찾는다면
			{
				cout << "입력하신 역 정보가 없습니다." << endl;
				return;
			}

			if(strcmp (pWork->GetName() , start) == 0) // 출발역 지정
			{
				start_p=++p; // 순서
				START=pWork;
			}
			
			if(strcmp (pWork->GetName() , end) == 0) // 도착역 지정
			{
				end_p=++p; // 순서
				END=pWork;
			}

			if(start_p!=0 && end_p != 0) // 출발역과 도착역이 모두 지정되었다면,
			{
				break;
			}

			pWork=pWork->GetNext();
			p+=1;
		}

		if(start_p < end_p) // 순방향
		{
			ShowList_H(START, END);
			return;
		}
		else if(start_p > end_p) // 역방향
		{
			ShowList_E(START, END);
			return;
		}
		else // 일치
		{
			cout << "두 역이 일치합니다." << endl;
			return;
		}
	}

	void ShowList_H(Station * Start, Station * End) // 순방향 출력
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
	
	void ShowList_E(Station * Start, Station * End) // 역방향 출력
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
	int n_station=0; // 역의 개수
	char station_p[50];
	char station_n[50];

	ifstream fin;
	fin.open("subway.txt");

	if(!fin)
	{
		cout << "파일을 읽을 수 없습니다." << endl;
		return -1;
	}

	while(!fin.eof())
	{
		fin.getline(station_p, 50, ' '); // 띄어쓰기로 구분
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

	char start_station[50]; // 출발지
	char end_station[50]; // 도착지

	cout << "출발지 : ";
	cin >> start_station;

	cout << "도착지 : ";
	cin >> end_station;

	cout << endl;

	// 경로를 찾아주는 함수
	list.Navigation(start_station, end_station);

	return 0;
}