#include <iostream>
#include <fstream>
using namespace std;

int My_strcmp(const char *str1, const char *str2)
{
	for(int i=0; str1[i]!=NULL && str2[i]!=NULL; i++)
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
	ifstream fin; // 파일 읽기
	fin.open("phone_book.txt");
	ofstream fout; // 파일에 출력
	fout.open("output.txt");

	int cnt=0;

	if(!fin)
	{
		return -1;
	}

	int select;
	char Name[32], Number[16];
	char Phonebook_Name[32], Phonebook_Number[16];

	cout << "Select (1:Name, 2:Phone): ";
	cin >> select; // 메뉴 선택

	switch(select)
	{
	case 1: // Name
		cout << "Name: ";
		cin >> Name;
		cnt=0;
		while(!fin.eof())
		{
			fin.getline(Phonebook_Name, 32, ',');
			fin.getline(Phonebook_Number, 16);

			if(My_strcmp(Name, Phonebook_Name)==0) // 사용자가 입력한 단어와 같다면 출력
			{
 				fout << Name << ' ' << Phonebook_Number << endl;
				cnt += 1;
			}
		}
		if(cnt==0)
			cout << "ERROR : 찾을 수 없음." << endl;
		break;


	case 2: // Phone
		cout << "Phone: ";
		cin >> Number;
		cnt=0;
		while(!fin.eof())
		{
			fin.getline(Phonebook_Name, 32, ',');
			fin.getline(Phonebook_Number, 16);
			
			if(My_strcmp(Number, Phonebook_Number)==0) // 사용자가 입력한 번호와 같다면 출력
			{
				if(cnt != 0) // 같은 번호가 하나가 아닐때,
				{
					cout << "중복된 번호 입니다." << endl;
					break;
				}

				fout << Name << ' ' << Number << endl;
				cnt+=1;

				cout << "저장되었습니다." << endl;
			}
		}
		if(cnt==0)
			cout << "ERROR : 찾을 수 없음." << endl;
		break;

	default:
		cout << "Error : Pleaese Input 1 or 2." << endl;
		break;
	}

	fin.close();
	fout.close();

	return 0;
}