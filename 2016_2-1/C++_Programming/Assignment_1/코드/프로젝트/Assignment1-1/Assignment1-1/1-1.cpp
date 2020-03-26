#include <iostream>
using namespace std;

int main()
{
	char word[10];
	int i=0, j=0;
	int endnum;

	cout << "Input : ";
	gets(word);

	// check length of word
	while(1)
	{
		if(word[i+1]==NULL)
		{
			endnum=i;
			break;
		}
		else
			i++;
	}

	// print
	while(j<endnum+1)
	{
		cout << word[j] ;
		
		if(word[j+1]!=NULL)
			cout << word[j+1];
		else
			cout << word[j-endnum];
		
		if(word[j+1]!=NULL && word[j+2]!=NULL)
			cout << word[j+2];
		else if(word[1]==NULL)
			cout << word[0];
		else
			cout << word[(j-endnum)+1];
		
		cout << endl;

		j++;
	}
	
	return 0;
}