#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int My_strcmp(const char *str1, const char *str2)
{
	for(int i=0; i<15; i++)
	{
		// 소문자크기로 변환해서 비교
		if(tolower(str1[i]) > tolower(str2[i]))
			return 1;
		else if(tolower(str1[i]) < tolower(str2[i]))
			return -1;
		else
			continue;
	}

	return 0;
}

int main()
{
	char file[30];
	char data[6][16];
	char line[255];

	cout << "Text file: ";
	gets(file); // 텍스트파일 이름 입력

	ifstream fin;
	fin.open(file);

	if (!fin)
	{
		cout << "파일을 읽을 수 없습니다." << endl;
	}
	
	// 파일 -> 배열 읽어오기
	int i=0,j=0;
	while(!fin.eof())
	{
		fin.getline(line, 255);
		int check=0;
		for(int t=0; t<255; t++)
		{
			if(line[t]==' ' || line[t]==NULL)
			{
				j=0;
				for(int k=check; k<t; k++, j++)
				{
					data[i][j]=line[k];
				}
				data[i][j]='\0';
				i++;
				check=t+1;
			}
			
			if(line[t]==NULL)
				break;
		}
	}

	// 정렬
	for(int k=0; k<6; k++)
	{
		for(int t=0; t<5; t++)
		{
			if( My_strcmp(data[t],data[t+1]) == 1 )
			{
				char temp;
				for(int r=0; r<16; r++)
				{
					temp=data[t][r];
					data[t][r]=data[t+1][r];
					data[t+1][r]=temp;
				}
			}
		}
	}

	// 출력
	for(int r=0; r<6; r++)
	{
		for(int k=0; k<16; k++)
		{
			if( data[r][k]!=NULL)
				cout << data[r][k];
			else
				break;
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}