#include <iostream>
using namespace std;

int main()
{
	char input[50];
	int Ntotal=0, Nn=0;
	int i=0, j=0;
	int alpha='a', count=0;
	double value=0;

	cout << "Input : ";
	gets(input);

	// count Total alphabet
	while(1)
	{
		if(input[i]==NULL)
			break;
		else
		{
			if(input[i]<='z' && input[i]>='a')
				Ntotal++;
		}
		i++;
	}

	// print output
	cout << "Output" << endl;
	while(alpha <= 'z')
	{
		//count each number of character
		j=0;
		count=0;
		while(1)
		{
			if(input[j]==alpha)
				count++;
			else if(input[j]==NULL)
				break;

			j++;
		}

		value=(double)count/Ntotal;
		
		// print each alphabet's value
		if(value!=0)
		{
			cout.precision(6);
			cout << (char)alpha << "    " << value << endl;
			alpha++;
		}
		else
			alpha++;
	}

	return 0;
}