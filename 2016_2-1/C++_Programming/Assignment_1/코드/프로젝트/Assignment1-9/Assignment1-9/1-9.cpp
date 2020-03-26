#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int Yoon(int year)
{
	if(year%400==0 || ((year%100)!=0)&&((year%4)==0)) 
		return 1;// 윤년이면 1반환
	else
		return 0; // 윤년아니면 0반환
}

int days_month(int year, int month) // 해당년,달의 일수 계산
{
	if(month==4 || month==6 || month==9 || month==11)
		return 30;
	else if(month==2 && Yoon(year)==1)
		return 29;
	else if(month==2 && Yoon(year)==0)
		return 28;
	else
		return 31;
}

int days_total(int year, int month, int day)
{
	int year2=year-2010;
	int total=365*year2+4; // 금요일부터니까 +4 부터 시작

	for(int i=1; i<=year2; i++) // 지난연도에 윤년 확인
	{
		if(Yoon(year-i)==1) // 윤년이면 하루더
			total++;
	}

	for(int i=1; i<month; i++)
	{
		total+=days_month(year, i); // 달의 날짜수 더함
	}

	return total;
}

int week(int year, int month, int day) // 첫날이 무슨 요일인지 리턴
{
	return (days_total(year, month, day)%7);
}

void Calendar(int year, int month)
{
	int days=days_month(year,month);
	int i;
	int day=1-week(year, month, 1);
	
	cout << "월 화 수 목 금 토 일" << endl;
	for(i=0; day<=days; i++,day++)
	{
		if(day<1) // 첫날 요일까지 공백
			cout << "  ";
		else  // 날짜 입력
			cout << setw(2) << day;

		if((i%7)==6) // 7번 출력하면 줄바꿈
			cout << endl;
		else // 아니면 다시 공백
			cout << " ";
	}
}

void Calendar_text(int year, int month) // 파일에입력
{
	ofstream fout;
	fout.open("calendar.txt");

	int days=days_month(year,month);
	int i;
	int day=1-week(year, month, 1);
	// day 값이 1이면 월요일, 0이면 화요일 -1이면 수요일 ,,, 마이너스된만큼 공백출력을 위해.
	
	fout << "월 화 수 목 금 토 일" << endl;
	for(i=0; day<=days; i++,day++)
	{
		if(day<1)
			fout << "  ";
		else 
			fout << setw(2) << day;

		if((i%7)==6)
			fout << endl;
		else
			fout << " ";
	}
	fout<<endl;
	fout.close();
}

int main()
{
	int year, month, day;
	int week[7]={1,2,3,4,5,6,7};
	
	cout << "Enter the year : ";
	cin >> year;

	cout << "Enter the month : ";
	cin >> month;

	if(year<2010 || year>2020 || month>12 || month<1)
	{
		cout << "Input Error : year=2010~2020, month=1~12" << endl;
		return 0;
	}

	cout << endl;
	
	Calendar(year, month); // 달력 출력
	Calendar_text(year, month); // 파일에 출력

	cout << endl;

	return 0;
}