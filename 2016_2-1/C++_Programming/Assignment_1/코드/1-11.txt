#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int length;
	int num;

	num=1;

	while(1)
	{
		cout << "Please enter the length of square side: ";
		cin >> length;

		if(3<=length && length<=15)
			break;
	}
	//동적할당
	int **Snail=new int*[length];
	for(int i=0; i<length; i++)
		Snail[i]=new int[length];

	for(int i=0; i<(length/2)+1; i++) // 중간까지 반복
	{
		for(int j=0; j<length-(i*2); j++) // 오른쪽으로
			Snail[i][j+i]=num++;
		
		for(int j=0; j<length-1-(i*2); j++) // 아래로
			Snail[j+1+i][length-i-1]=num++;
		
		for(int j=0; j<length-1-(i*2); j++) // 왼쪽으로
			Snail[length-1-i][length-2-i-j]=num++;
		
		for(int j=0; j<length-2-(i*2); j++) // 위로
			Snail[length-2-i-j][i]=num++;
	}


	//출력
	for (int i=0; i<length; i++)
	{
		for (int j=0; j<length; j++)
		{
			cout << setw(3) << Snail[i][j] << "  ";
		}
		cout << endl;
	}

	//메모리해제
	for(int i=0; i<length; i++)
			delete [] Snail[i];
	delete [] Snail;

	return 0;
}