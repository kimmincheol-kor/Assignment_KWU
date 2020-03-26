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

	// �������(length_sentence), �ܾ��(n_words), �ܾ����(length_words) ���ϱ�
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
		// �����Ҵ�
		char **word= new char * [n_words];
		for(int i=0; i<n_words; i++)
			word[i]=new char[32];

		// ���忡�� �ܾ� ����
		for(int i=0, start=0; i<n_words; i++)
		{
			copy(sentence, word[i], start, length_words[i]);
			start += (length_words[i]+1);
		}

		// ����ġ �Է�
		int word1, word2;
		while(1)
		{
			cout << "Switch locations: ";
			cin >> word1 >> word2;
			if(word1 > n_words || word2 > n_words || word1<0 || word2<0)
			{
				cout << "�ٽ� �Է����ּ���." << endl;
			}
			else
				break;
		}

		word1--; word2--;

		cout << endl;

		cout << "Switched sentence" << endl;
	
		// swap �Լ�
		swapWord(word, length_words, word1, word2);

		// �������
		for(int i=0; i<n_words; i++)
		{
			for(int j=0; j<length_words[i]; j++)
				cout << word[i][j];

			if(i == n_words-1)
				cout << "." << endl;
			else
				cout << " ";
		}

		// �����Ҵ� ����
		for(int i=0; i<n_words; i++)
			delete [] word[i];
		delete [] word;
	}
	else
		cout << "�ܾ��� ������ 2�� �̻��̾�� �մϴ�." << endl;

	return 0;
}

void copy(char *sentence, char *word, int start, int length) // ���� �Լ�
{
	int i = 0;
	for(int j=start; i<length; i++, j++)
	{
		word[i]=sentence[j];
	}
	word[i] = '\0';
}

void swapWord(char *word[], int *length_words, int index1, int index2) // ���� �Լ�
{
	char *temp = word[index1];
	word[index1] = word[index2];
	word[index2] = temp;

	int temp_length = length_words[index1];
	length_words[index1] = length_words[index2];
	length_words[index2] = temp_length;
}