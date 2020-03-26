#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

int main()
{
	char word[6][50];
	char quiz[50];
	char fail[50];
	int i=0, lastap=0;
	char answer1, answer2;
	char check;
	int ran1, ran2;
	srand(time(NULL));

	ifstream fin;
	fin.open("word.txt");

	if (!fin)
	{
		cout << "파일을 읽을 수 없습니다." << endl;
	}

	// input the word that in the notepad to 2-dimention array
	while (!fin.eof())
	{
		fin.getline(word[i], 50);
		i++;
	}

	// choose random word
	strcpy(quiz, word[rand() % 6]);
	strcpy(fail, quiz);

	// find number of alphabet of the word
	i=0;
	while(quiz[i]!=NULL)
	{
		i++;
		lastap=i; // length of the word
	}

	cout<<"==== Start ====" << endl;
	
	// random number
	while(1)
	{
	ran1=rand()%lastap;
	ran2=rand()%lastap;
	
	if(ran1<ran2)
		break;
	}

	answer1=quiz[ran1];
	answer2=quiz[ran2];
	quiz[ran1]='_';
	quiz[ran2]='_';

	i=0;
	while(i<4) // 4 times
	{
		cout << quiz << endl << ">> " ;
		cin >> check;

		// if alphabet is answer.
		if(check==answer1)
		{
			quiz[ran1]=answer1;
			answer1=0;
		}
		else if(check==answer2)
		{
			quiz[ran2]=answer2;
			answer2=0;
		}

		// finish the quiz
		if(answer1==0 && answer2==0)
			break;

		i++;
	}

	// fail the quiz
	if((answer1 != 0) || (answer2 != 0))
		cout << "Fail: " << fail << endl;
	else
		cout << fail << endl;


	cout << "==== End ====" << endl;

	fin.close();
	return 0;
}