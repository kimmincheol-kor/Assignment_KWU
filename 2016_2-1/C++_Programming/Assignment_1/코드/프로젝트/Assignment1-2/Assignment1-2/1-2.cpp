#include <iostream>
using namespace std;

int main()
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int out_x, out_y;

	cout << "Input" << endl;

	//좌표입력
	cout << "[1]: ";
	cin >> x1;
	cin >> y1;

	cout << "[2]: ";
	cin >> x2;
	cin >> y2;
	
	cout << "[3]: ";
	cin >> x3;
	cin >> y3;

	cout << "Output" << endl;
	if( (x1==x2 && y1==y2) || (x1==x3 && y1==y3) || (x3==x2 && y3==y2) ) // 같은점이있을때
	{
		cout << "Not rectangle" << endl;
		return 0;
	}

	//두점을 지나는 직선 외에 한점(위치가 혼자 다른점)
	if (((x1 == x2) + (x2 == x3) + (x1 == x3)) == 1)
	{
		if (x1 == x2)
			out_x = x3;

		if (x2 == x3)
			out_x = x1;

		if (x1 == x3)
			out_x = x2;
	}
	else
	{
		cout << "Not rectangle" << endl;
		return 0;
	}

	//두점을 지나는 직선외에 한점(높이가 혼자 다른 점)
	if (((y1 == y2) + (y2 == y3) + (y1 == y3)) == 1)
	{
		if (y1 == y2)
			out_y = y3;

		if (y2 == y3)
			out_y = y1;

		if (y1 == y3)
			out_y = y2;
	}
	else
	{
		cout << "Not rectangle" << endl;
		return 0;
	}

	// 결과
	cout << "[4]: " << out_x << " " << out_y << endl;

	return 0;
}