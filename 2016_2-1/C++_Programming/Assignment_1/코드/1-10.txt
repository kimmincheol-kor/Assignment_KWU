#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	char map[10][10]={{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0','0'}};
	int side1=0, side2=0;
	int direction;
	int ex;
	srand(time(NULL));

	map[side1][side2]='A';

	while(1) // 전체 반복문
	{
		if(map[side1][side2]=='Z')
		{
			cout << "The Program Stops : A~Z print" << endl;
			break;
		}

		while(1) // move
		{
			direction=rand()%4;
			ex=(int)map[side1][side2];

			// 대각선이 안비었다면
			if( (map[side1-1][side2-1]!='0' && map[side1-1][side2+1]!='0' && map[side1+1][side2-1]!='0' && map[side1+1][side2+1]!='0') || (side1==0 && map[side1+1][side2-1]!='0' && map[side1+1][side2+1]!='0') || (side1==9 && map[side1-1][side2-1]!='0' && map[side1-1][side2+1]!='0') || (side2==0 && map[side1+1][side2+1]!='0' && map[side1-1][side2+1]!='0') || (side2==9 && map[side1+1][side2-1]!='0' && map[side1-1][side2-1]!='0')) // 대각선이 꽉참
			{
				// 상하좌우 이동
				if(direction==0)
				{
					if(map[side1-1][side2]=='0' && side1!=0)
					{
						side1--;
						map[side1][side2]=(char)++ex;
						break;
					}
				}
				else if(direction==1)
				{
					if(map[side1][side2-1]=='0' && side2!=0)
					{
						side2--;
						map[side1][side2]=(char)++ex;
						break;
					}
				}
				else if(direction==2)
				{
					if(map[side1+1][side2]=='0' && side1!=9)
					{
						side1++;
						map[side1][side2]=(char)++ex;
						break;
					}
				}
				else if(direction==3)
				{
					if(map[side1][side2+1]=='0' && side2!=9)
					{
						side2++;
						map[side1][side2]=(char)++ex;
						break;
					}
				}
				
				if((map[side1][side2+1]!='0' && map[side1+1][side2]!='0' && map[side1][side2-1]!='0' && map[side1-1][side2]!='0') || ((side1==0 && (map[side1][side2+1]!='0' && map[side1+1][side2]!='0' && map[side1][side2-1]!='0' )) || (side1==9 && (map[side1][side2+1]!='0' && map[side1][side2-1]!='0' && map[side1-1][side2]!='0')) || (side2==0 && (map[side1][side2+1]!='0' && map[side1+1][side2]!='0' && map[side1-1][side2]!='0')) || (side2==9 && (map[side1+1][side2]!='0' && map[side1][side2-1]!='0' && map[side1-1][side2]!='0'))) ) // 대각선꽉참 -> 상하좌우 꽉참 -> 종료
				{
					cout << "The Program Stops! : No more way" << endl;

					// 맵그리기
					for(int i=0; i<10; i++)
					{
						for(int j=0; j<10; j++)
						{
							if(map[i][j]!='0')
								cout << map[i][j] << " ";
							else
								cout << map[i][j] << " ";
						}
						cout << endl ;
					}
					cout << endl ;

					return 0;
				}
			}
			// 대각선 이동
			else if(direction==0)
			{
				if(map[side1-1][side2-1]=='0' && side1!=0 && side2!=0)
				{
					side1--;
					side2--;
					map[side1][side2]=(char)++ex;
					break;
				}
			}
			else if(direction==1 && side1!=0 && side2!=9)
			{
				if(map[side1-1][side2+1]=='0')
				{
					side1--;
					side2++;
					map[side1][side2]=(char)++ex;
					break;
				}
			}
			else if(direction==2)
			{
				if(map[side1+1][side2-1]=='0' && side1!=9 && side2!=0)
				{
					side1++;
					side2--;
					map[side1][side2]=(char)++ex;
					break;
				}
			}
			else if(direction==3)
			{
				if(map[side1+1][side2+1]=='0' && side1!=9 && side2!=9)
				{
					side1++;
					side2++;
					map[side1][side2]=(char)++ex;
					break;
				}
			}
		} // end of move
		
	} // end of big while

	// 맵그리기
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
		if(map[i][j]!='0')
			cout << (char)map[i][j] << " ";
		else
			cout << (char)map[i][j] << " ";
		}
		cout << endl ;
	}
	cout << endl ;

	return 0;
}