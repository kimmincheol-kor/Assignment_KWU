#include <iostream>
#include <fstream>
using namespace std;

int My_strcmp(const char *str1, const char *str2)
{
	for(int i=0; str1[i]!=NULL && str2[i]!=NULL; i++)
	{
		// �ҹ���ũ��� ��ȯ�ؼ� ��
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
	ifstream fin; // ���� �б�
	fin.open("phone_book.txt");
	ofstream fout; // ���Ͽ� ���
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
	cin >> select; // �޴� ����

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

			if(My_strcmp(Name, Phonebook_Name)==0) // ����ڰ� �Է��� �ܾ�� ���ٸ� ���
			{
 				fout << Name << ' ' << Phonebook_Number << endl;
				cnt += 1;
			}
		}
		if(cnt==0)
			cout << "ERROR : ã�� �� ����." << endl;
		break;


	case 2: // Phone
		cout << "Phone: ";
		cin >> Number;
		cnt=0;
		while(!fin.eof())
		{
			fin.getline(Phonebook_Name, 32, ',');
			fin.getline(Phonebook_Number, 16);
			
			if(My_strcmp(Number, Phonebook_Number)==0) // ����ڰ� �Է��� ��ȣ�� ���ٸ� ���
			{
				if(cnt != 0) // ���� ��ȣ�� �ϳ��� �ƴҶ�,
				{
					cout << "�ߺ��� ��ȣ �Դϴ�." << endl;
					break;
				}

				fout << Name << ' ' << Number << endl;
				cnt+=1;

				cout << "����Ǿ����ϴ�." << endl;
			}
		}
		if(cnt==0)
			cout << "ERROR : ã�� �� ����." << endl;
		break;

	default:
		cout << "Error : Pleaese Input 1 or 2." << endl;
		break;
	}

	fin.close();
	fout.close();

	return 0;
}