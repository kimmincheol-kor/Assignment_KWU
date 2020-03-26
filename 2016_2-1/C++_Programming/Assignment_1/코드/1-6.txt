#include <iostream>
using namespace std;

int main()
{
	int size;
	int output=0;
	int *length;
	int i=0, j=0, k=0;

	cout << "Input the size of array: ";
	cin >> size;

	// dynamic allocation
	length=new int[size];
	cout << "Input: ";
	for(int i=0; i<size; i++)
	{
		cin >> length[i];
	}

	//check point (important)
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size-1; j++)
		{
			for(k=j+1; k<size; k++)
			{
				// length[i] , length[j], length[k]
				if( (length[i] < (length[j]+length[k])) && (length[j] < (length[i]+length[k])) && (length[k] < (length[j]+length[i])) )
					output++;
			}
		}		
	}

	//result
	if(output!=0)
		cout << "Output: " << output << endl;
	else
		cout << "No Output" << endl;

	// ÇØÁ¦
	delete []length;
	return 0;
}