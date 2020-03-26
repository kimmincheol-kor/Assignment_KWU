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
		fin.getline(input1, 10, 'X'); // 세로크기
		fin.getline(input2, 10); // 가로크기

		fin.getline(move, 100); // 섞는 명령어
	}

	MyBoard m_board(atoi(input1),atoi(input2)); // 기본 판 생성

	for(int i=0; i<100; i++) // 섞기
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
		m_board.ShowBoard(); // 보드 출력

		cout << "메뉴 (w:up  a:left  s:down  d:right)" << endl;
		cout << "입력 : ";
		cin >> menu;
		cout << endl;

		// 이동
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
		else if(menu=='0') // 0을 입력하면 종료
		{
			cout << "종료" << endl;
			break;
		}
		else // 명령어 밖의 입력
		{
			cout << "제대로 입력하세요." << endl;
			continue;
		}

		// 다 맞췄는지 체크.
		check=m_board.CheckEnd();
		if(check==0)
		{
			m_board.ShowBoard();
			cout << "완성" << endl;
			break;
		}
	}

	return 0;
}