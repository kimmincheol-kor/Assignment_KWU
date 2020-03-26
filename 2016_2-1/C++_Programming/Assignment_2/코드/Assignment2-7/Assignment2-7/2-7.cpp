#include <iostream>
using namespace std;

int my_strlen(char arr[])
{
	int count=0;

	for(int i=0; arr[i]!=NULL; i++)
	{
		count+=1;
	}

	return count;
}

class MyCar
{
private:
	char* m_Model;
	char* m_Color;
	int m_Number;

public:
	MyCar(char* model, char* color, int num)
	{
		int i,j;

		// 길이만큼 동적할당
		m_Model=new char[my_strlen(model)];
		m_Color=new char[my_strlen(color)];

		// 길이만큼 복사
		for(i=0; i<my_strlen(model); i++)
		{
			m_Model[i]=model[i];
		}
		m_Model[i]='\0';

		// 길이만큼 복사
		for(j=0; j<my_strlen(color); j++)
		{
			m_Color[j]=color[j];
		}
		m_Color[j]='\0';
		m_Number=num;
	}

	~MyCar() // default destructor
	{
	}

	char* getModel()
	{
		return m_Model;
	}

	char* getColor()
	{
		return m_Color;
	}

	int getNumber()
	{
		return m_Number;
	}
};

int main()
{
	char model[3][16];
	char color[3][16];
	int num[3];

	// Input
	for(int i=0; i<3; i++) 
	{
		cout << "Input Car information" << endl;

		cout << "Input Model : ";
		cin >> model[i];

		cout << "Input Color : ";
		cin >> color[i];

		cout << "Input Number : ";
		cin >> num[i];
	}

	// Input to class
	MyCar Mc1(model[0],color[0], num[0]);
	MyCar Mc2(model[1],color[1], num[1]);
	MyCar Mc3(model[2],color[2], num[2]);

	// 출력
	cout << "Display members of Class MyCar" << endl;
	cout << "< " << Mc1.getModel() << " >" << endl;
	cout << "Car's Color : " << Mc1.getColor() << endl;
	cout << "Car's Number : " << Mc1.getNumber() << endl;
	cout << endl;

	cout << "< " << Mc2.getModel() << " >" << endl;
	cout << "Car's Color : " << Mc2.getColor() << endl;
	cout << "Car's Number : " << Mc2.getNumber() << endl;
	cout << endl;

	cout << "< " << Mc3.getModel() << " >" << endl;
	cout << "Car's Color : " << Mc3.getColor() << endl;
	cout << "Car's Number : " << Mc3.getNumber() << endl;
	cout << endl;
}