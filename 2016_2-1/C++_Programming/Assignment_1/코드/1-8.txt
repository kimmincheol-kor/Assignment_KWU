#include <iostream>
#include <math.h>
using namespace std;

double Rounding(double x, int digit) // 반올림함수
{
    return ( floor((x)*pow(float(10),digit)+0.5f ) / pow(float(10), digit));
}


double Distance(int x1, int y1, int x2, int y2)
{
	double ex;
	double result;

	ex=(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));

	result=sqrt(ex);

	return result;
}

double Slope(int x1, int y1, int x2, int y2)
{
	double result;

	result=((double)(y2-y1)/(x2-x1));

	return result;
}

double Area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double area;
	double a,b,c;
	double ex;
	double perimeter;

	a=Distance(x1, y1, x2, y2);
	b=Distance(x1, y1, x3, y3);
	c=Distance(x2, y2, x3, y3);

	perimeter=(a+b+c)/2;

	ex=(perimeter*(perimeter-a)*(perimeter-b)*(perimeter-c));

	area=sqrt(ex);

	return area;
}

int main()
{
	int p1_x, p1_y;
	int p2_x, p2_y;
	int p3_x, p3_y;
	int sp_x, sp_y;
	double A,B,C;
	double AP,BP,CP;
	double Area_ABC, Area_1, Area_2, Area_3;
	double slope12, slope13, slope23, slope1s, slope2s, slope3s;

	// input three point and form triangle
	while(1)
	{
		cout << "input point1 : ";
		cin >> p1_x >> p1_y;

		cout << "input point2 : ";
		cin >> p2_x >> p2_y;

		cout << "input point3 : ";
		cin >> p3_x >> p3_y;

		// 세변의 길이 구하기
		A=Distance(p1_x, p1_y, p2_x, p2_y);
		B=Distance(p1_x, p1_y, p3_x, p3_y);
		C=Distance(p2_x, p2_y, p3_x, p3_y);
	
		// 삼각형이 성립하는지 확인
		if(A+B>C && A+C>B && B+C>A)
		{
			cout << "Three points can form a triangle." << endl;
			break;
		}
		else
			cout << "Three points can't form a triangle." << endl;
	}

	// 전체 삼각형의 넓이
	Area_ABC=Area(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);

	cout << "Input a point : ";
	cin >> sp_x >> sp_y;
	
	// 기울기 구하기
	slope12=Slope(p1_x, p1_y, p2_x, p2_y);
	slope23=Slope(p3_x, p3_y, p2_x, p2_y);
	slope13=Slope(p1_x, p1_y, p3_x, p3_y);
	slope1s=Slope(p1_x, p1_y, sp_x, sp_y);
	slope2s=Slope(p2_x, p2_y, sp_x, sp_y);
	slope3s=Slope(p3_x, p3_y, sp_x, sp_y);

	// 점p로 의해 나눠진 삼각형 3개의 넓이
	Area_1=Area(p1_x, p1_y, p2_x, p2_y, sp_x, sp_y);
	Area_2=Area(p1_x, p1_y, sp_x, sp_y, p3_x, p3_y);
	Area_3=Area(sp_x, sp_y, p2_x, p2_y, p3_x, p3_y);

	// 반올림
	Area_ABC=Rounding(Area_ABC, 3);
	Area_1=Rounding(Area_1, 3);
	Area_2=Rounding(Area_2, 3);
	Area_3=Rounding(Area_3, 3);
	

	if( slope12 == slope1s || slope13 == slope1s || slope12 == slope2s || slope23 == slope2s || slope13 == slope3s || slope23 == slope3s )
		cout << "The point is in the triangle" << endl;
	else if(Area_ABC==(Area_1+Area_2+Area_3))
		cout << "The point is in the triangle" << endl;
	else
		cout << "The point is not in the triangle" << endl;

	return 0;
}