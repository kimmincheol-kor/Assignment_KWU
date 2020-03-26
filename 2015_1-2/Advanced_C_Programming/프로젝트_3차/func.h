typedef struct PB
{
	char name[32];
	int age;
	char number[16];
	struct PB *next;
}PhoneBook;

PhoneBook * Delete();

int Insert();
int Update();
int Search();
int Print();
int Save();
void Free_memory();
void Phonebook_Load();
