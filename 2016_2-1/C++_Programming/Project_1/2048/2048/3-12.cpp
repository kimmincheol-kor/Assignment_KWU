#include <iostream>
using namespace std;
#include "Board.h"


void main()
{
	MyBoard m_Board;
	int move;
	int check=1;
	int end;
	cout << "[START]" << endl;

	while(1)
	{
		if(check != 0) // ù ����, �̵� ������ ��쿡�� ������ ����
			m_Board.Random();
		m_Board.ShowBoard(); // ���� ���
		
		end = m_Board.CheckEnd(); // 2048�� �����ϴ���, �̵��� �Ұ������� üũ -> Win Lose ���
		
		if(end == 1)
		{
			cout << "Win!!" << endl;
			break;
		}
		else if(end == -1)
		{
			cout << "Lose!!" << endl;
			break;
		}

		check=0;

		cout << "[MENU]\n" << "1.Up  2.Down  3.Left  4.Right" << endl;
		cout << "Input >> ";
		cin >> move;
		cout << endl;

		switch(move) // �����̱�
		{
		case -1:
			break;

		case 1:
			check=m_Board.Up();
			if(check == 0)
				cout << "�� �������� �̵��Ұ�" << endl << endl;
			break;

		case 2:
			check=m_Board.Down();
			if(check == 0)
				cout << "�� �������� �̵��Ұ�" << endl << endl;
			break;

		case 3:
			check=m_Board.Left();
			if(check == 0)
				cout << "�� �������� �̵��Ұ�" << endl << endl;
			break;

		case 4:
			check=m_Board.Right();
			if(check == 0)
				cout << "�� �������� �̵��Ұ�" << endl << endl;
			break;

		default:
			cout << "�߸��� �Է��Դϴ�" << endl << endl;
			break;
		}
		
		if(move == -1)
			break;
	}

	cout << "[program exit]" << endl; // ���α׷� ����
}