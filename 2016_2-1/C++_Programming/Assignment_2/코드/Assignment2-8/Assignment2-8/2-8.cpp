#include <iostream>
#include <fstream>
#include <ctype.h>
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

int my_strncmp(char str1[], char str2[], int n)
{
	for(int i=0; i<n; i++)
	{
		// 소문자크기로 변환해서 비교
		if(tolower(str1[i]) > tolower(str2[i]))
			return 1;
		else if(tolower(str1[i]) < tolower(str2[i]))
			return -1;
		else
			continue;
	}

	return 0;
}

class MyBook
{
private:
	char title[100];
	char quantity[100];
public:
	MyBook(){}
	~MyBook(){}

	void add_book(char book_title[], char book_quantity[])
	{
		int length_title=my_strlen(book_title);
		int i;
		
		for(i=0; i<length_title; i++)
			title[i]=book_title[i];
		title[i]='\0';

		int length_quantity=my_strlen(book_quantity);
		int j;
		
		for(j=0; j<length_quantity; j++)
			quantity[j]=book_quantity[j];
		quantity[j]='\0';
	}
	
	void Show_book()
	{
		cout << title << '/' << quantity << endl;
	}

	char* get_title()
	{
		return title;
	}

	char* get_quantity()
	{
		return quantity;
	}

	void edit(char edit_q[])
	{
		int length_quantity=my_strlen(edit_q);
		int j;
		
		for(j=0; j<length_quantity; j++)
			quantity[j]=edit_q[j];
		quantity[j]='\0';
	}
};

void Save_book(MyBook *book, int n_words);
int Load_book(MyBook *book);

int main()
{
	int menu;
	char book_title[32];
	char book_quantity[32];

	int n=0;
	MyBook book[50];

	while(1)
	{
		cout << "1. Load  2. Add  3. Edit  4. Print  5. Save  6. Quit" << endl;
		cout << "Input number: ";
		cin >> menu;

		if(menu==6)
			break;

		switch(menu)
		{
		case 1:
			n=Load_book(book); // 파일 읽고, 파일에 저장된 책의 개수 반환
			cout << endl;
			break;

		case 2:
			cout << "Book title: ";
			fflush(stdin);
			gets(book_title);
			cout << "Quantity: ";
			fflush(stdin);
			cin >> book_quantity;

			book[n].add_book(book_title, book_quantity);
			n += 1;
			cout << endl;
			break;

		case 3:
			char find_book[32];
			char edit_quantity[32];
			cout << "Boot title: ";
			fflush(stdin);
			gets(find_book);

			for(int i=0; i<n; i++)
			{
				if( my_strncmp(book[i].get_title(), find_book, my_strlen(find_book)) == 0 )
				{
					cout << "Quantity: ";
					cin >> edit_quantity;

					book[i].edit(edit_quantity);

					break;
				}
				else
					continue;

				if(i==(n-1))
					cout << "ERROR : 찾을 수 없음." << endl;
			}
			cout << endl;
			break;

		case 4:
			cout << endl << "[Book List]" << endl;
			for(int i=0; i<n; i++)
				book[i].Show_book();
			cout << endl;
			break;

		case 5:
			Save_book(book, n);
			cout << endl;
			break;

		default:
			cout << "Please Select Menu <1~6>" << endl;
			break;
		}
	}

	return 0;
}

void Save_book(MyBook *book, int n_words)
{
	ofstream fout;
	fout.open("book.txt");

	for(int i=0; i<n_words; i++ )
	{
		char *title;
		title=book[i].get_title();
		char *quantity;
		quantity=book[i].get_quantity();

		fout << title << '/' << quantity;

		if(i != n_words-1) // 마지막 줄은 개행x 
			fout << endl;
	}

	fout.close();
}

int Load_book(MyBook *book)
{
	char title[32];
	char quantity[32];
	int n_words=0;

	ifstream fin;
	fin.open("book.txt");

	if (!fin)
	{
		cout << "파일을 읽을 수 없습니다." << endl;
	}
	
	while(!fin.eof())
	{
		fin.getline(title , 32 , '/');
		fin.getline(quantity, 32);
		
		book[n_words].add_book(title, quantity);
			n_words += 1;
	}

	fin.close();

	return n_words;
}
