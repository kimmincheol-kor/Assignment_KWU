#include <iostream>
using namespace std;

char * my_strtok(char * str)
{
	char delimiter1='&';
	char delimiter2='?';
	static char * pstr; // 계속 남아있을 주소
	
	if(pstr==NULL) // 첫 실행
		pstr=str;
	else // 두번째 실행부터 저장되어 있는 pstr로 진행
		str=pstr;

	while(*pstr!=NULL)
	{
		if( *pstr==delimiter1 || *pstr==delimiter2 ) // 문자가 토큰이라면,
		{
			*pstr='\0'; // 그 자리는 NULL로 = str 의 그자리도 NULL로 바뀜
			pstr+=1; // pstr이 가르키는 주소 +1 = NULL의 다음 값을 가리킴.
			return str; // 처음~NULL 까지 리턴
		}
		pstr+=1; // 다음 문자
	}

	return str; // 토크에 걸리지않는다면 그대로 출력 = 마지막 문장
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
	n_element+=1; // 마지막 요소

	if(n_element >= 1)
	{
		// 동적 할당
		char **name = new char * [n_element];
		for(int i=0; i<n_element; i++)
			name[i] = new char [64];

		char **value = new char * [n_element];
		for(int i=0; i<n_element; i++)
			value[i] = new char [64];

		// 나누자!
		for(int i=0; i<n_element; i++)
		{
			if(i==0) // 처음
				point=my_strtok(url);
			else // 나중
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

		// search의 글자수 세기
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
				cout << "ERROR : 찾을 수 없음" << endl;
		}

		// 동적할당 해제
		for(int i=0; i<n_element; i++)
			delete [] name[i];
		delete [] name;

		for(int i=0; i<n_element; i++)
			delete [] value[i];
		delete [] value;
	}

	return 0;
}