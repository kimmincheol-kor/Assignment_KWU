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
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


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
	if (strcmp(A, ".") == 0 && strcmp(B, "..") == 0)
		return -1;
	else if (strcmp(A, "..") == 0 && strcmp(B, ".") == 0)
		return 1;
	else if (strcmp(A, "..") == 0)
		return -1;
	else if (strcmp(B, "..") == 0)
		return 1;
	else if (strcmp(A, ".") == 0)
		return -1;
	else if (strcmp(B, ".") == 0)
		return 1;

	char str1[strlen(A)+1]; // temp string 1
	char str2[strlen(B)+1]; // temp string 2

	if (A[0] == '.')
		strcpy(str1, &A[1]);
	else
		strcpy(str1, A); // temp string 1 = first

	if(B[0] == '.')
		strcpy(str2, &B[1]);
	else
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
		return 1;
	else if(strcmp(str1, str2) < 0) // str2 > str1
		return -1;
	else
		return 0; // str1 = str2
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

struct file_format
{
	char permission [10];
	int link;
	struct passwd * uid;
	struct group * gid;
	int size;
	char m_time[100];
};

void view_advanced_list(char * filename, struct stat * buf)
{
	struct file_format * f_stat = malloc(sizeof(struct file_format)) ;

	/*디렉토리인지 파일인지 검사*/
	if (S_ISDIR(buf->st_mode))
		f_stat->permission[0] = 'd';
	else if (S_ISLNK(buf->st_mode))
		f_stat->permission[0] = 'l';
	else if (S_ISCHR(buf->st_mode))
		f_stat->permission[0] = 'c';
	else if (S_ISBLK(buf->st_mode))
		f_stat->permission[0] = 'b';
	else if (S_ISSOCK(buf->st_mode))
		f_stat->permission[0] = 's';
	else if (S_ISFIFO(buf->st_mode))
		f_stat->permission[0] = 'P';
	else
		f_stat->permission[0] = '-';
	/*사용자 권한 검사*/
	if (buf->st_mode & S_IRUSR)
		f_stat->permission[1] = 'r';
	else
		f_stat->permission[1] = '-';
	if (buf->st_mode & S_IWUSR)
		f_stat->permission[2] = 'w';
	else
		f_stat->permission[2] = '-';
	if (buf->st_mode & S_IXUSR)
		f_stat->permission[3] = 'x';
	else if (buf->st_mode & S_ISUID)
		f_stat->permission[3] = 's';
	else
		f_stat->permission[3] = '-';

	/*그룹 권한 검사*/
	if (buf->st_mode & S_IRGRP)
		f_stat->permission[4] = 'r';
	else
		f_stat->permission[4] = '-';
	if (buf->st_mode & S_IWGRP)
		f_stat->permission[5] = 'w';
	else
		f_stat->permission[5] = '-';
	if (buf->st_mode & S_IXGRP)
		f_stat->permission[6] = 'x';
	else if (buf->st_mode & S_ISGID)
		f_stat->permission[6] = 's';
	else
		f_stat->permission[6] = '-';
	/*일반사용자 권한 검사*/
	if (buf->st_mode & S_IROTH)
		f_stat->permission[7] = 'r';
	else
		f_stat->permission[7] = '-';
	if (buf->st_mode & S_IWOTH)
		f_stat->permission[8] = 'w';
	else
		f_stat->permission[8] = '-';

	if (buf->st_mode & S_IXOTH) //stiky bit 설정
	{
		if (buf->st_mode & S_ISVTX)
			f_stat->permission[9] = 't';
		else
			f_stat->permission[9] = 'x';
	}
	else
	{
		if (buf->st_mode & S_ISVTX)
			f_stat->permission[9] = 'T';
		else
			f_stat->permission[9] = '-';
	}

	f_stat->permission[10] = '\0';


	f_stat->link = buf->st_nlink;
	f_stat->uid = getpwuid(buf->st_uid);
	f_stat->gid = getgrgid(buf->st_gid);
	f_stat->size = buf->st_size;

	strcpy(f_stat->m_time, ctime(&buf->st_mtime));
	f_stat->m_time[0] = f_stat->m_time[4];
	f_stat->m_time[1] = f_stat->m_time[5];
	f_stat->m_time[2] = f_stat->m_time[6];
	f_stat->m_time[3] = ' ';
	f_stat->m_time[4] = f_stat->m_time[8];
	f_stat->m_time[5] = f_stat->m_time[9];
	f_stat->m_time[6] = ' ';
	f_stat->m_time[7] = f_stat->m_time[11];
	f_stat->m_time[8] = f_stat->m_time[12];
	f_stat->m_time[9] = f_stat->m_time[13];
	f_stat->m_time[10] = f_stat->m_time[14];
	f_stat->m_time[11] = f_stat->m_time[15];
	f_stat->m_time[12] = '\0';
	
	printf("%s	%d	%s	%s	%d	%s	%s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, f_stat->m_time, filename);

	free(f_stat);
}

void Opt_l(char * folder_name)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	char * cd_name; // name of current directory

	dirp = opendir(folder_name); // open folder(user input)
	char pwd[256];

	struct stat buf;

	char path[256];
	int total_size=0;

	if (dirp == NULL) // 폴더가 아니다. -> 파일 찾기
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0)
			{
				strcpy(path, ".");
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				view_advanced_list(dir->d_name, &buf);

				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // 폴더다
	{
		chdir(folder_name);
		getcwd(pwd, sizeof(char) * 256);
		printf("Directory path: %s\n", pwd);

		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else if (dir->d_name[0] != '.') // is hidden file ?
			{
				strcpy(path, folder_name);
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				total_size += (buf.st_blocks/2);

				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		printf("total : %d\n", total_size);

		sort_list(list, cnt); // sort by filename
		
		//////////////////////////// 상세정보 출력
		for (int i = 0; i < cnt; i++)
		{
			strcpy(path, folder_name);
			strcat(path, "/");
			strcat(path, list[i]);
			stat(path, &buf);

			view_advanced_list(list[i], &buf);
		}
		////////////////////////////////////////////////

		if (cnt != 0)
			free_list(list, cnt); // if list allocated, free list
	}

	closedir(dirp); // close opened directory
}

void Opt_al(char * folder_name)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	char * cd_name; // name of current directory

	dirp = opendir(folder_name); // open folder(user input)
	char pwd[256];

	struct stat buf;

	char path[256];
	int total_size = 0;

	if (dirp == NULL) // 폴더가 아니다. -> 파일 찾기
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0)
			{
				strcpy(path, ".");
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				view_advanced_list(dir->d_name, &buf);

				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // 폴더다
	{
		chdir(folder_name);
		getcwd(pwd, sizeof(char) * 256);
		printf("Directory path: %s\n", pwd);

		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else
			{
				strcpy(path, folder_name);
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				total_size += (buf.st_blocks / 2);

				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		printf("total : %d\n", total_size);

		sort_list(list, cnt); // sort by filename

		//////////////////////////// 상세정보 출력
		for (int i = 0; i < cnt; i++)
		{
			strcpy(path, folder_name);
			strcat(path, "/");
			strcat(path, list[i]);
			stat(path, &buf);

			view_advanced_list(list[i], &buf);
		}
		////////////////////////////////////////////////

		if (cnt != 0)
			free_list(list, cnt); // if list allocated, free list
	}

	closedir(dirp); // close opened directory
}

void Opt_a(char * folder_name)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	char * cd_name; // name of current directory

	dirp = opendir(folder_name); // open folder(user input)

	if (dirp == NULL) // 폴더가 아니다. -> 파일 찾기
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0)
			{
				printf("%s\n", folder_name);
				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // 폴더다
	{
		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else
			{
				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		sort_list(list, cnt); // sort by filename
		view_list(list, cnt); // print file list to screen

		if (cnt != 0)
			free_list(list, cnt); // if list allocated, free list
	}

	closedir(dirp); // close opened directory
}

void Opt_default(char * folder_name)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	char * cd_name; // name of current directory

	dirp = opendir(folder_name); // open folder(user input)

	if (dirp == NULL) // 폴더가 아니다. -> 파일 찾기
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0)
			{
				printf("%s\n", folder_name);
				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // 폴더다
	{
		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else if (dir->d_name[0] != '.') // is hidden file ?
			{
				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		sort_list(list, cnt); // sort by filename
		view_list(list, cnt); // print file list to screen

		if (cnt != 0)
			free_list(list, cnt); // if list allocated, free list
	}

	closedir(dirp); // close opened directory
}

void advanced_ls(char * folder_name, int option)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	char * cd_name; // name of current directory
	char path[256];
	dirp = opendir(folder_name); // open folder(user input)
	char pwd[256];
	struct stat buf;
	
	int total_size = 0;

	if (dirp == NULL) // 폴더가 아니다. -> 파일 찾기
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0)
			{
				if(option == 1 || option == 0)
					printf("%s\n", folder_name);
				else if (option == 2 || option == 3)
				{
					strcpy(path, ".");
					strcat(path, "/");
					strcat(path, dir->d_name);
					stat(path, &buf);

					view_advanced_list(dir->d_name, &buf);
				}
				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // 폴더다
	{
		if (option == 2 || option == 3)
		{
			chdir(folder_name);
			getcwd(pwd, sizeof(char) * 256);
			printf("Directory path: %s\n", pwd);
		}

		while (dir = readdir(dirp)) // read directory
		{
			if (dir->d_name == NULL) // no more file in directory ?
				break;
			else if (dir->d_name[0] != '.' && (option == 2 || option == 0)) // 히든 파일 제외
			{
				strcpy(path, folder_name);
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				total_size += (buf.st_blocks / 2);

				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
			else if (option == 1 || option == 3) // 히든 파일 포함
			{
				strcpy(path, folder_name);
				strcat(path, "/");
				strcat(path, dir->d_name);
				stat(path, &buf);

				total_size += (buf.st_blocks / 2);

				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (strlen(dir->d_name) + 1));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1
				}
			}
		}

		sort_list(list, cnt); // sort by filename
		
		if (option == 0 || option == 1)
			view_list(list, cnt); // print file list to screen
		else if (option == 2 || option == 3)
		{
			printf("total : %d\n", total_size);

			for (int i = 0; i < cnt; i++)
			{
				strcpy(path, folder_name);
				strcat(path, "/");
				strcat(path, list[i]);
				stat(path, &buf);

				view_advanced_list(list[i], &buf);
			}
		}
	
		if (cnt != 0)
		{
			for (int a = 0; a < cnt; a++)
			{
				free(list[a]); // free filename allocation
			}
			free(list); // free number of file allocation
		}
	}

	closedir(dirp); // close opened directory
}

//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
// Input :	argc -> number of input of program		//
// 		argv -> input of program								//
// 																//
//																//
// Purpose :	read filenames of folder, sort, print that.	//
//////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])//
{
	char ** folder_name; // list of folder names
	int folder_cnt = 0; // number of foldernames
	int opt = 0, flag_a = 0, flag_l = 0;

	while ((opt = getopt(argc, argv, "al")) != -1)
	{
		switch (opt)
		{
		case 'a':
			flag_a++;
			break;
		case 'l':
			flag_l++;
			break;
		}
	}

	for(int i = 1; i < argc; i++ ) // 명령어 개수 만큼 반복 -> 옵션, 폴더명 구하기
	{
		if ( (argv[i][0] != '-' && argv[i][0] != '.') || strcmp(argv[i], ".") == 0 || strcmp(argv[i], "..") == 0) // 폴더명이다.
		{
			if(folder_cnt == 0) // 첫 동적할당
				folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
			else // 동적 재할당
				folder_name = (char**)realloc(folder_name, sizeof(char*) * folder_cnt + 1);

			folder_name[folder_cnt] = (char*)malloc(sizeof(char) * (strlen(argv[i]) + 1));
			strcpy(folder_name[folder_cnt], argv[i]); // insert to list
			folder_cnt++; // count of folder number + 1
		}
	}

	if (folder_cnt == 0) // if not exist folder name -> current
	{
		folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
		folder_name[folder_cnt] = (char*)malloc(sizeof(char));
		strcpy(folder_name[folder_cnt], "."); // insert to list
		folder_cnt++; // count of folder number + 1
	}

	for (int i = 0; i < folder_cnt; i++)
	{
		if (flag_a == 1 && flag_l == 0) // option : a
			advanced_ls(folder_name[i], 1); //Opt_a(folder_name[i], 1); //
		else if (flag_a == 0 && flag_l == 1) // option : l
			advanced_ls(folder_name[i], 2); //Opt_l(folder_name[i], 2); //
		else if (flag_a == 1 && flag_l == 1) // option : al, la
			advanced_ls(folder_name[i], 3); //Opt_al(folder_name[i], 3); //
		else if (flag_a == 0 && flag_l == 0) // option : default
			advanced_ls(folder_name[i], 0); //Opt_default(folder_name[i], 0); //
		else
		{
			printf("no option \n");
			break;
		}
	}

	if(folder_cnt != 0)
		free_list(folder_name, folder_cnt); // free allocation

	return 0;
}

