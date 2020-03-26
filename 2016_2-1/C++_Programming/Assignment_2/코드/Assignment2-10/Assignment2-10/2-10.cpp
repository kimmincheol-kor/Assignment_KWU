#include <iostream>
#include <fstream>
using namespace std;

class WORD
{
public:
	char name[100];
	WORD * next;

	WORD()
	{
		*name=NULL;
		next=NULL;
	}
	~WORD()
	{

	}

	void setName(char * arr)
	{
		for(int i=0; i<100; i++)
		{
			name[i]=arr[i];

			if(name[i]=='\0')
				break;
		}
	}
};

class List
{
public:
	WORD * head;

	List()
	{
		head=NULL;
	}
	~List()
	{
		WORD * pWork;
		WORD * pTemp;

		pTemp=head;

		while( pTemp != NULL )
		{
			pWork=pTemp;
			pTemp=pWork->next;
			delete pWork;
			cout << "DELETE !!" << endl;
		}

	}

	void insert(char *arr) // �����ؼ� �μ�Ʈ.
	{
		if(head==NULL) // ó��
		{
			WORD * pNew = new WORD;
				
			pNew->setName(arr);

			head=pNew;
		}
		else // ó���� �ƴϸ�
		{
			WORD * pWork;
			WORD * pSmall;
			WORD * pBig;
			
			WORD * pNew = new WORD;
			pNew->setName(arr);

			pWork = head;
			
			while(1)
			{
				if( strcmp( pNew->name , head->name ) <= 0 ) // ��庸�� ������,
				{
					pNew->next=head;
					head=pNew;
					break;
				}
				
				if( pWork->next == NULL) // ������ Ŭ��,
				{
					pWork -> next = pNew;
					break;
				}

				if( strcmp( pNew->name , pWork->next->name ) <= 0 && strcmp( pNew->name , pWork->name ) >= 0 ) // ���̿� ����,
				{
					pSmall = pWork;
					pBig = pWork->next;

					pSmall->next = pNew;
					pNew->next = pBig;

					break;
				}
				pWork = pWork->next;
			}
		}

	}
};

int main()
{
	ifstream fin;
	fin.open("palindrome.txt");

	char line[255];
	
	int n_word=0;
	char first, last;
	
	int start_p[30];
	int end_p[30];
	int cnt=0;
	int p_delete;
	int a=0;

	WORD word[100];
	List list;

	if (!fin)
	{
		cout << "������ ���� �� �����ϴ�." << endl;
	}

	while(!fin.eof())
	{
		fin.getline(line, 255);
	}

	// �ܾ� ����(n_word), �� �ܾ��� ������(start_p), ����(end_p) ã��
	for(int i=0; line[i]!=NULL; i++)
	{
		if(i==0)
		{
			first=line[0];
			start_p[cnt]=0;
		}

		if(line[i]==' ')
		{
			if(line[i-1]==',')
				last=line[i-2];
			else
				last=line[i-1];
			
			if( first == last ) // ù���ڿ� �����ڰ� ���ٸ�
			{
				end_p[cnt]=i;
				for(int i=0; i<(end_p[cnt]-start_p[cnt])/2; i++) // ��Ī���� Ȯ��
				{
					if(line[start_p[cnt]+i] == line[end_p[cnt]-i-1])
					{
						a+=1;
					}
					else // ��Ī�� �ƴ϶��,
					{
						a=0;
						break;
					}
				}

				if(end_p[cnt]-1 != start_p[cnt] && a!=0) // �ѱ��ڵ� �ƴϰ�, ��Ī�� �ƴ϶��,
				{
					cnt += 1;
					n_word+=1;
				}
			}

			first=line[i+1];
			start_p[cnt]=i+1;
		}

		if(line[i]=='.')
			break;
	}

	if( n_word > 0 )
	{
		// �ܾ� ���� -> word[][]
		for(int i=0; i<n_word; i++)
		{
			cnt=0;
			for(int k=start_p[i]; k<end_p[i]; k++, cnt++)
				word[i].name[cnt]=line[k];
			word[i].name[cnt]='\0'; // NULL ó��
		}

		
		// ��ũ�帮��Ʈ
		for(int i=0; i<n_word; i++)
			list.insert(word[i].name);

		WORD * pWork;
		while(1) // Print , Delete
		{
			pWork=list.head;
		
			cout << "list : ";
			for(int i=0; i<n_word; i++) // ���
			{
				cout << pWork->name;
			

				if( pWork->next != NULL )
				{
					cout << " -> " ;
					pWork=pWork->next;
				}
				else
				{
					cout << endl;
					break;
				}
			}

			cout << "Delete?: "; 
			cin >> p_delete; // ������ ��ġ �Է�

			if(p_delete < 0 || p_delete > n_word) // ��ġ ����ó��
			{
				cout << "Pleaes Input again." << endl << endl;
				continue;
			}
			
			if(p_delete==0) // 0 �Է½� ����
				break;

			pWork=list.head;
			for(int i=0; i<p_delete; i++)
			{
				if(i==p_delete-2) // �߰� ��� ����
				{
					WORD * pTemp = new WORD;
					
					pTemp->setName(pWork->next->name);
					pTemp->next=pWork->next->next;
					
					delete pWork->next;
					n_word-=1;
				
					pWork->next = pTemp->next;

					delete pTemp;
				
					break;
				}
				else if(i==0 && p_delete==1) // ù��° ��� ����
				{
					if( pWork->next == NULL )
						list.head=NULL;
					else
						list.head=pWork->next;

					delete pWork;
					n_word-=1;
				}
					
				pWork = pWork->next;
			}

			cout << endl;

			if(n_word==0) // ���� �ܾ���� 0��.
			{
				cout << "���� �ܾ �����ϴ�." << endl;
				break;
			}
		}

	}
	else // �ܾ���� 0��.
		cout << "ERROR : �ܾ ã�� �� ����." << endl;

	return 0;
}