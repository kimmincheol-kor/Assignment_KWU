//////////////////////////////////////////////////////////////////
// File Name	: simple_ls.c					//
// Date		: 2018 / 3 / 31					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #2-1 (simple_ls)	//
// Description 	: ...						//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////
// free_list							//
// ============================================================	//
// Input :	** li -> list of file name			//
// 		i -> number of file names			//
// 								//
// Purpose :	Free for Dynamic Allocation			//
// 								//
//////////////////////////////////////////////////////////////////
void free_list(char ** li, int i)
{
	for(int a=0; a<i; a++)
	{	
		free(li[a]); // free filename allocation
	}
	free(li); // free number of file allocation
}

//////////////////////////////////////////////////////////////////
// strcmp_i							//
// ============================================================	//
// Input :	* A -> first string				//
// 		* B -> second string				//
// Output :	len -> result of compare			//
// 								//
// Purpose :	compare two strings without case		//
//////////////////////////////////////////////////////////////////
int strcmp_i(char * A, char * B)
{
	char str1[strlen(A)+1]; // temp string 1
	char str2[strlen(B)+1]; // temp string 2
	strcpy(str1, A); // temp string 1 = first
	strcpy(str2, B); // temp string 2 = second

	int len; // compare length and return value
	
	if(strlen(A) > strlen(B)) // len = shortest length
		len = strlen(B);
	else
		len = strlen(A);
	
	// change to Uppercase
	for(int i=0; i<len; i++)
	{
		if(str1[i] <= 122 && str1[i] >= 97) // first
			str1[i] = str1[i]-32;

		if(str2[i] <= 122 && str2[i] >= 97) // second
			str2[i] = str2[i]-32;
	}
	
	if(strcmp(str1, str2) > 0) // str1 > str2
		len = 1;
	else if(strcmp(str1, str2) < 0) // str2 > str1
		len = -1;
	else
		len = 0; // str1 == str2

	return len;
}

//////////////////////////////////////////////////////////////////
// sort_list							//
// ============================================================	//
// Input :	** li -> list of file name			//
// 		len -> number of file names			//
// 								//
// 								//
// Purpose :	sort the list of filenames			//
//////////////////////////////////////////////////////////////////
void sort_list(char ** li, int len)
{
	char tmp[256];
	
	// sort like bublle sort
	for (int i = 0; i < len - 1; i++) // total cycle
	{
		if (li[i][0] == '\0') // end of list
			break;

		for (int j = 0; j < len - 1; j++) // one cycle
		{	
			if (strcmp_i(li[j], li[j + 1]) == 1) // need sort ?
			{
				strcpy(tmp,  li[j]);
				strcpy(li[j],  li[j + 1]);
				strcpy(li[j + 1],  tmp);
			}
		}
	}

	return;
}

//////////////////////////////////////////////////////////////////
// view_list							//
// ============================================================	//
// Input :	** li -> list of file name			//
// 		len -> number of file names			//
// 								//
// 								//
// Purpose :	print the list of filenames			//
//////////////////////////////////////////////////////////////////
void view_list(char ** li, int len)
{
	for (int i = 0; i < len; i++) // print list of filenames
	{
		for (int j = 0; j < 256; j++) // print filename
		{
			if (li[i][j] == '\0')
				break;

			printf("%c", li[i][j]); // print character of filename
		}
		printf("\n");
	}

	return;
}

//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
// Input :	argc -> number of input of program		//
// 		argv -> input of program			//
// 								//
// 								//
// Purpose :	read filenames of folder, sort, print that.	//
//////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	DIR * dirp; // directory
	struct dirent *dir; // file

	char ** list; // list of filenames
	int cnt=0; // number of filenames

	if (argc == 1) // current directory ?
	{
		dirp = opendir("."); // open folder(current)

		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else if(dir->d_name[0] != '.') // is hidden file ?
			{
				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt+1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name)+1) );
					strcpy(list[cnt],  dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt+1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name)+1));
					strcpy(list[cnt],  dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		sort_list(list, cnt); // sort by filename

		view_list(list, cnt); // print file list to screen
		
		if(cnt != 0)
			free_list(list, cnt); // if list allocated, free list
		closedir(dirp); // close opened directory
	}
	else if (argc == 2) // user input another directory ?
	{
		dirp = opendir(argv[1]); // open folder(user input)

		if(dirp == NULL) // cannot access user input folder.
			printf("./simple_ls : cannot access '%s' : No such directory\n", argv[1]);
		else // can access user input folder
		{
			while (dir = readdir(dirp)) // read directory
			{
				if (dir->d_name == NULL) // no more file in directory ?
					break;
				else if(dir->d_name[0] != '.') // is hidden file ?
				{
					if (cnt == 0) // insert : filename(first)
					{
						//dynamic allocation for list
						list = (char**)malloc(sizeof(char*) * cnt+1);
						list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name)+1) );
						strcpy(list[cnt],  dir->d_name); // insert to list
						cnt++; // count of filenames + 1
					}
					else // insert : filename
					{
						//re-dynamic allocation for list
						list = (char**)realloc(list, sizeof(char*) * cnt+1);
						list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name)+1));
						strcpy(list[cnt],  dir->d_name); // insert to list
						cnt++; // count of filenames + 1
					}
				}
			}

			sort_list(list, cnt); // sort by filename

			view_list(list, cnt); // print file list to screen
		
			if(cnt != 0)
				free_list(list, cnt); // if list allocated, free list
		}
		closedir(dirp); // close opened directory
	}
	else
		printf("./simple_ls : only one directory path can be processed\n"); // user input is not one folder.
	
	return 0;
}

