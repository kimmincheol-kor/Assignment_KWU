#include <iostream>
using namespace std;

int Sum(int a, int b, int c, int d)
{
	int result=(a*1000)+(b*100)+(c*10)+(d);

	return result;
}

int main()
{
	int number[4];
	int input, output, check=0;
	int i,j,k;

	// type input
	while(1)
	{
		cout << "Input: ";
		cin >> input;

		if( 1<=input && input<10000 )
			break;
	}

	number[3]=input/1000; // 천의자리
	number[2]=input%1000/100; // 백의자리
	number[1]=input%100/10; // 십의자리
	number[0]=input%10; // 일의자리
	// 순서 : 3210
	

	if(number[3]!=0) // 네자리수라면,
	{
		if(Sum(number[3],number[2],number[0],number[1])>input) // 십의자리, 일의자리만 교체
		{
			output=Sum(number[3],number[2],number[0],number[1]);
			check++;
		}

		else if(number[0]>number[2]) // step.1
		{
			if(Sum(number[3],number[0],number[2],number[1]) < Sum(number[3],number[0],number[1],number[2]))
			{
				output=Sum(number[3],number[0],number[2],number[1]);
				check++;
			}
			else
			{
				output=Sum(number[3],number[0],number[1],number[2]);
				check++;
			}
		}
		
		else if(number[1]>number[2]) // step.2
		{
			if(Sum(number[3],number[1],number[0],number[2]) < Sum(number[3],number[1],number[2],number[0]))
			{
				output=Sum(number[3],number[1],number[0],number[2]);
				check++;
			}
			else
			{
				output=Sum(number[3],number[1],number[2],number[0]);
				check++;
			}
		}
		// 천의자리 교체
		else if(number[0]>number[3])
		{
			if(number[3]<=number[1] && Sum(number[0],number[3],number[1],number[2])>input)
			{
				output=Sum(number[0],number[3],number[1],number[2]);
				check++;
			}
			else if(number[3]<=number[2] && Sum(number[0],number[1],number[3],number[2])>input)
			{
				output=Sum(number[0],number[1],number[3],number[2]);
				check++;
			}
			else if(Sum(number[0],number[1],number[2],number[3])>input)
			{
				output=Sum(number[0],number[1],number[2],number[3]);
				check++;
			}
		}

		else if(number[1]>number[3])
		{
			if(number[3]<=number[0] && Sum(number[1],number[3],number[0],number[2])>input)
			{
				output=Sum(number[1],number[3],number[0],number[2]);
				check++;
			}
			else if(number[3]<=number[2] && Sum(number[1],number[0],number[3],number[2])>input)
			{
				output=Sum(number[1],number[0],number[3],number[2]);
				check++;
			}
			else if(Sum(number[1],number[0],number[2],number[3])>input)
			{
				output=Sum(number[1],number[0],number[2],number[3]);
				check++;
			}
		}

		else if(number[2]>number[3])
		{
			if(number[3]<=number[0] && Sum(number[2],number[3],number[0],number[1])>input)
			{
				output=Sum(number[2],number[3],number[0],number[1]);
				check++;
			}
			else if(number[3]<=number[1] && Sum(number[2],number[0],number[3],number[1])>input)
			{
				output=Sum(number[2],number[0],number[3],number[1]);
				check++;
			}
			else if(Sum(number[2],number[0],number[1],number[3])>input)
			{
				output=Sum(number[2],number[0],number[1],number[3]);
				check++;
			}
		}

	}
	
	// 세 자리수
	else if(number[2]!=0)
	{
		if(Sum(0,number[2],number[0],number[1])>input) // 십의자리, 일의자리만 교체
		{
			output=Sum(0,number[2],number[0],number[1]);
			check++;
		}

		else if(number[0]>number[2]) // step.1
		{
			if(Sum(0,number[0],number[2],number[1]) < Sum(0,number[0],number[1],number[2]))
			{
				output=Sum(0,number[0],number[2],number[1]);
				check++;
			}
			else
			{
				output=Sum(0,number[0],number[1],number[2]);
				check++;
			}
		}
		
		else if(number[1]>number[2]) // step.2
		{
			if(Sum(0,number[1],number[0],number[2]) < Sum(0,number[1],number[2],number[0]))
			{
				output=Sum(0,number[1],number[0],number[2]);
				check++;
			}
			else
			{
				output=Sum(0,number[1],number[2],number[0]);
				check++;
			}
		}
	}
	// 두자리수
	else if(number[1]!=0)
	{
		if(Sum(0,0,number[0],number[1]) > input) // 바꾼게 더 크다면,
		{
			output=Sum(0,0,number[0],number[1]);
			check++;
		} 
		//아니면 Not Possible
	}
	// 한자리수라면 Not Possible 출력
	


	if(check != 0)
		cout << "Output: " << output << endl;
	else
		cout << "Not Possible" << endl;

	return 0;
}