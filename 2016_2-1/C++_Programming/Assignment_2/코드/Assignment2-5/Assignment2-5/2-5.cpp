#include <iostream>
using namespace std;

void copy(char *sentence, char *word, int start, int length);
void swapWord(char *word[], int *length_words, int index1, int index2);

int main()
{
	char sentence[1000];
	int n_words=0;
	int length_words[100];
	int length_sentence=0;
	int j=0;

	cout << "Input sentence: ";
	gets(sentence);

	// 문장길이(length_sentence), 단어개수(n_words), 단어길이(length_words) 구하기
	for(int i=0; i<1000; i++)
	{
		if(sentence[i]==' ')
		{
			length_words[n_words++]=( i - j );
			j=i+1;
		}

		if(sentence[i]=='.')
		{
			length_words[n_words++]=( i - j );
			length_sentence=i;
			break;
		}
	}

	if(n_words>=2)
	{
		// 동적할당
		char **word= new char * [n_words];
		for(int i=0; i<n_words; i++)
			word[i]=new char[32];

		// 문장에서 단어 복사
		for(int i=0, start=0; i<n_words; i++)
		{
			copy(sentence, word[i], start, length_words[i]);
			start += (length_words[i]+1);
		}

		// 스위치 입력
		int word1, word2;
		while(1)
		{
			cout << "Switch locations: ";
			cin >> word1 >> word2;
			if(word1 > n_words || word2 > n_words || word1<0 || word2<0)
			{
				cout << "다시 입력해주세요." << endl;
			}
			else
				break;
		}

		word1--; word2--;

		cout << endl;

		cout << "Switched sentence" << endl;
	
		// swap 함수
		swapWord(word, length_words, word1, word2);

		// 문장출력
		for(int i=0; i<n_words; i++)
		{
			for(int j=0; j<length_words[i]; j++)
				cout << word[i][j];

			if(i == n_words-1)
				cout << "." << endl;
			else
				cout << " ";
		}

		// 동적할당 해제
		for(int i=0; i<n_words; i++)
			delete [] word[i];
		delete [] word;
	}
	else
		cout << "단어의 개수가 2개 이상이어야 합니다." << endl;

	return 0;
}

void copy(char *sentence, char *word, int start, int length) // 복사 함수
{
	int i = 0;
	for(int j=start; i<length; i++, j++)
	{
		word[i]=sentence[j];
	}
	word[i] = '\0';
}

void swapWord(char *word[], int *length_words, int index1, int index2) // 스왑 함수
{
	char *temp = word[index1];
	word[index1] = word[index2];
	word[index2] = temp;

	int temp_length = length_words[index1];
	length_words[index1] = length_words[index2];
	length_words[index2] = temp_length;
}