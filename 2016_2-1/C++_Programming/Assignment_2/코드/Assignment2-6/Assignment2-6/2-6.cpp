#include <iostream>
using namespace std;

char * my_strtok(char * str)
{
	char delimiter1='&';
	char delimiter2='?';
	static char * pstr; // ��� �������� �ּ�
	
	if(pstr==NULL) // ù ����
		pstr=str;
	else // �ι�° ������� ����Ǿ� �ִ� pstr�� ����
		str=pstr;

	while(*pstr!=NULL)
	{
		if( *pstr==delimiter1 || *pstr==delimiter2 ) // ���ڰ� ��ū�̶��,
		{
			*pstr='\0'; // �� �ڸ��� NULL�� = str �� ���ڸ��� NULL�� �ٲ�
			pstr+=1; // pstr�� ����Ű�� �ּ� +1 = NULL�� ���� ���� ����Ŵ.
			return str; // ó��~NULL ���� ����
		}
		pstr+=1; // ���� ����
	}

	return str; // ��ũ�� �ɸ����ʴ´ٸ� �״�� ��� = ������ ����
}

int main()
{
	char url[512], search[32];
	int menu;
	char *point;
	int n_element=0;
	char element[20][100];
	int len_element[20];
	int len_search=0;
	int count=0;
	
	cout << "Input URL : ";
	gets(url);

	// calculate number of elements
	for(int i=0; i<512; i++)
	{
		if(url[i]=='&' || url[i]=='?')
			n_element+=1;
	}
	n_element+=1; // ������ ���

	if(n_element >= 1)
	{
		// ���� �Ҵ�
		char **name = new char * [n_element];
		for(int i=0; i<n_element; i++)
			name[i] = new char [64];

		char **value = new char * [n_element];
		for(int i=0; i<n_element; i++)
			value[i] = new char [64];

		// ������!
		for(int i=0; i<n_element; i++)
		{
			if(i==0) // ó��
				point=my_strtok(url);
			else // ����
				point=my_strtok(NULL);

			cout << point << endl;

			int a=0;
			while(*point!=NULL)
			{
				element[i][a]=*point;
				point++;
				a++;
			}
			element[i][a]='\0';
			len_element[i]=a;
		}

		// Search Data
		cout << endl << "Search data : ";
		cin >> search;

		// search�� ���ڼ� ����
		int a=0;
		while(search[a]!=NULL)
		{
			len_search+=1;
			a++;
		}

		for(int i=0; i<20; i++)
		{
			count = 0;
			for(int j=0; j<len_search; j++)
			{
				if(element[i][j]==search[j])
					count+=1;
			}

			if(count == len_search)
			{
				for(int k=0; k<100; k++)
				{
					if(element[i][k]==NULL)
						break;

					if(element[i][k]=='=')
					{
						cout << " is ";
						k++;
					}
					cout << element[i][k];
				}
				cout << endl;
				break;
			}
			
			if(i==19)
				cout << "ERROR : ã�� �� ����" << endl;
		}

		// �����Ҵ� ����
		for(int i=0; i<n_element; i++)
			delete [] name[i];
		delete [] name;

		for(int i=0; i<n_element; i++)
			delete [] value[i];
		delete [] value;
	}

	return 0;
}