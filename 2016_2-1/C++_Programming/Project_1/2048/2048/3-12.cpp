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
		if(check != 0) // 첫 실행, 이동 성공한 경우에만 랜덤값 생성
			m_Board.Random();
		m_Board.ShowBoard(); // 보드 출력
		
		end = m_Board.CheckEnd(); // 2048이 존재하는지, 이동이 불가능한지 체크 -> Win Lose 출력
		
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

		switch(move) // 움직이기
		{
		case -1:
			break;

		case 1:
			check=m_Board.Up();
			if(check == 0)
				cout << "이 방향으로 이동불가" << endl << endl;
			break;

		case 2:
			check=m_Board.Down();
			if(check == 0)
				cout << "이 방향으로 이동불가" << endl << endl;
			break;

		case 3:
			check=m_Board.Left();
			if(check == 0)
				cout << "이 방향으로 이동불가" << endl << endl;
			break;

		case 4:
			check=m_Board.Right();
			if(check == 0)
				cout << "이 방향으로 이동불가" << endl << endl;
			break;

		default:
			cout << "잘못된 입력입니다" << endl << endl;
			break;
		}
		
		if(move == -1)
			break;
	}

	cout << "[program exit]" << endl; // 프로그램 종료
}