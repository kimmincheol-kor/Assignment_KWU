#include <iostream>
#include <fstream>
using namespace std;

#include "class.h"

int main()
{
	char input1[10];
	char input2[10];
	char move[100];

	ifstream fin;
	fin.open("puzzle.info");

	if(!fin)
	{
		return -1;
	}

	while(!fin.eof())
	{
		fin.getline(input1, 10, 'X'); // ����ũ��
		fin.getline(input2, 10); // ����ũ��

		fin.getline(move, 100); // ���� ��ɾ�
	}

	MyBoard m_board(atoi(input1),atoi(input2)); // �⺻ �� ����

	for(int i=0; i<100; i++) // ����
	{
		if(move[i]=='u')
		{
			m_board.Up();
		}
		else if(move[i]=='d')
		{
			m_board.Down();
		}
		else if(move[i]=='l')
		{
			m_board.Left();
		}
		else if(move[i]=='r')
		{
			m_board.Right();
		}
		else if(move[i]==NULL)
			break;
		else
			continue;
	}

	char menu;
	int check;

	while(1)
	{
		m_board.ShowBoard(); // ���� ���

		cout << "�޴� (w:up  a:left  s:down  d:right)" << endl;
		cout << "�Է� : ";
		cin >> menu;
		cout << endl;

		// �̵�
		if(menu=='w')
		{
			m_board.Up();
		}
		else if(menu=='s')
		{
			m_board.Down();
		}
		else if(menu=='a')
		{
			m_board.Left();
		}
		else if(menu=='d')
		{
			m_board.Right();
		}
		else if(menu=='0') // 0�� �Է��ϸ� ����
		{
			cout << "����" << endl;
			break;
		}
		else // ��ɾ� ���� �Է�
		{
			cout << "����� �Է��ϼ���." << endl;
			continue;
		}

		// �� ������� üũ.
		check=m_board.CheckEnd();
		if(check==0)
		{
			m_board.ShowBoard();
			cout << "�ϼ�" << endl;
			break;
		}
	}

	return 0;
}