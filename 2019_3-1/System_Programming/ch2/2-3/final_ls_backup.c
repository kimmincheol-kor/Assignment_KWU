//////////////////////////////////////////////////////////////////
// File Name	: advanced_ls.c					//
// Date		: 2018 / 4 / 8					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #2-2 (advanced_ls)	//
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
#include <fnmatch.h>

int flag_a = 0, flag_l = 0, flag_h = 0, flag_r = 0, flag_S = 0;
char origin_wd[1000];

struct file_format // store information of file (Full Format)
{
	char permission[11]; // mode of file
	int link; // number of hard link of file
	struct passwd * uid; // user id of owner of file
	struct group * gid; // group id of owner of file
	int size; // size of file
	char m_time[100]; // modified time of file
	char linkpath[1000]; // use at symbolic link
};

//////////////////////////////////////////////////////////////////
// strcmp_i							//
// ============================================================	//
// Input :	* A -> first string				//
// 		* B -> second string				//
// Output :	result of compare			//
// 								//
// Purpose :	compare two strings without case		//
//////////////////////////////////////////////////////////////////
int strcmp_i(char * A, char * B)
{
	////////////     exception case           /////////////
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
	/////////////////////////////////////////////////////////

	char str1[strlen(A)+1]; // temp string 1
	char str2[strlen(B)+1]; // temp string 2
	int len; // compare length and return value

	// temp string 1 = A
	if (A[0] == '.') // except '.'
		strcpy(str1, &A[1]);
	else
		strcpy(str1, A); 

	// temp string 2 = B
	if(B[0] == '.') // except '.'
		strcpy(str2, &B[1]);
	else
		strcpy(str2, B); 

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

	if (flag_r == 1)
	{
		if (strcmp(str1, str2) > 0) // str1 > str2
			return -1;
		else if (strcmp(str1, str2) < 0) // str2 > str1
			return 1;
		else
			return 0; // str1 = str2
	}
	else
	{
		if (strcmp(str1, str2) > 0) // str1 > str2
			return 1;
		else if (strcmp(str1, str2) < 0) // str2 > str1
			return -1;
		else
			return 0; // str1 = str2
	}
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
				strcpy(tmp, li[j]);
				strcpy(li[j], li[j + 1]);
				strcpy(li[j + 1], tmp);
			}
		}
	}
	return;
}

//////////////////////////////////////////////////////////////////
// sort_list_S							//
// ============================================================	//
// Input :	** li -> list of file name			//
// 		len -> number of file names			//
// 								//
// 								//
// Purpose :	sort the list of filenames			//
//////////////////////////////////////////////////////////////////
void sort_list_S(char ** li, int size[], int len)
{
	char tmp_s[256];
	int tmp_i;
	// sort like bublle sort
	for (int i = 0; i < len - 1; i++) // total cycle
	{
		if (li[i][0] == '\0') // end of list
			break;

		for (int j = 0; j < len - 1; j++) // one cycle
		{
			if (size[j] < size[j+1]) // need sort ?
			{
				strcpy(tmp_s, li[j]);
				strcpy(li[j], li[j + 1]);
				strcpy(li[j + 1], tmp_s);

				tmp_i = size[j];
				size[j] = size[j + 1];
				size[j + 1] = tmp_i;
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
// view_advanced_list							//
// ============================================================	//
// Input :	* path -> path of file			//
// 			* filename -> file name			//
// 			* buf -> struct stat pointer that have file information					//
// 								//
// Purpose :	print the Full Format of file		//
//////////////////////////////////////////////////////////////////
void view_advanced_list(char * path, char * filename, struct stat * buf)
{
	struct file_format * f_stat = malloc(sizeof(struct file_format)) ; // allocation for f_stat
	char * p_path; // pointer use at symbolic link

	// Type
	if (S_ISSOCK(buf->st_mode)) // socket
		f_stat->permission[0] = 's';
	else if (S_ISLNK(buf->st_mode)) // symbolic link
		f_stat->permission[0] = 'l';
	else if (S_ISBLK(buf->st_mode)) // block device
		f_stat->permission[0] = 'b';
	else if (S_ISDIR(buf->st_mode)) // directory
		f_stat->permission[0] = 'd';
	else if (S_ISCHR(buf->st_mode)) // character device
		f_stat->permission[0] = 'c';
	else if (S_ISFIFO(buf->st_mode)) // FIFO
		f_stat->permission[0] = 'P';
	else // regular
		f_stat->permission[0] = '-';

	// User permission
	if (buf->st_mode & S_IRUSR) // read permission : owner
		f_stat->permission[1] = 'r';
	else
		f_stat->permission[1] = '-';
	
	if (buf->st_mode & S_IWUSR) // write permission : owner
		f_stat->permission[2] = 'w';
	else
		f_stat->permission[2] = '-';
	
	if (buf->st_mode & S_IXUSR) // execute permission : owner
		f_stat->permission[3] = 'x';
	else
		f_stat->permission[3] = '-';

	// Group permission
	if (buf->st_mode & S_IRGRP) // read permission : group
		f_stat->permission[4] = 'r';
	else
		f_stat->permission[4] = '-';
	
	if (buf->st_mode & S_IWGRP) // write permission : group
		f_stat->permission[5] = 'w';
	else
		f_stat->permission[5] = '-';
	
	if (buf->st_mode & S_IXGRP) // execute permission : group
		f_stat->permission[6] = 'x';
	else
		f_stat->permission[6] = '-';

	// Other permission
	if (buf->st_mode & S_IROTH) // read permission : other
		f_stat->permission[7] = 'r';
	else
		f_stat->permission[7] = '-';
	
	if (buf->st_mode & S_IWOTH) // write permission : other
		f_stat->permission[8] = 'w';
	else
		f_stat->permission[8] = '-';

	if (buf->st_mode & S_IXOTH) // execute permission : other
		f_stat->permission[9] = 'x';
	else
		f_stat->permission[9] = '-';

	f_stat->permission[10] = '\0';


	f_stat->link = buf->st_nlink; // st_nlink -> f_stat->link
	f_stat->uid = getpwuid(buf->st_uid); // st_uid -> f_stat->uid
	f_stat->gid = getgrgid(buf->st_gid); // st_gid -> f_stat->gid
	f_stat->size = buf->st_size; // st_size -> f_stat->size
	
	// make time format by st_mtime(modified time)
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
	
	int check_h=0;
	char format_h;
	if (flag_h == 1)
	{
		while (1)
		{
			if (f_stat->size >= 1024)
			{
				f_stat->size = f_stat->size / 1024;
				check_h++;
			}
			else 
				break;
		}
		switch (check_h)
		{
		case 1:
			format_h = 'K';
			break;
		case 2:
			format_h = 'M';
			break;
		case 3:
			format_h = 'G';
			break;
		case 4:
			format_h = 'T';
			break;
		default:
			break;
		}
	}

	if (f_stat->permission[0] == 'l') // symbolic link ?
	{
		realpath(path, f_stat->linkpath);
		if (f_stat->linkpath == NULL)
			p_path = "Non path";
		else if ( strncmp(path, f_stat->linkpath, strlen(path) - strlen(filename) ) == 0 ) // same directory.
			p_path = &f_stat->linkpath[strlen(path) - strlen(filename)];
		else // different directory.
			p_path = f_stat->linkpath;
	
		if (flag_h == 1)
			printf("%s	%d	%s	%s	%d%c	%s	%s -> %s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time, filename, p_path);
		else
			printf("%s	%d	%s	%s	%d	%s	%s -> %s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, f_stat->m_time, filename, p_path);
	}
	else // not symbolic link
	{
		if (flag_h == 1)
			printf("%s	%d	%s	%s	%d%c	%s	%s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time, filename);
		else
			printf("%s	%d	%s	%s	%d	%s	%s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, f_stat->m_time, filename);
	}

	free(f_stat);
}

//////////////////////////////////////////////////////////////////
// advanced_ls							//
// ============================================================	//
// Input :	* folder_name -> folder name that using at search		//
// 			option -> 1: -a , 2: -l, 3: -la, 0: default			//
// 								//
// 								//
// Purpose :	bring file names from folder, and make list that having file names.		//
//////////////////////////////////////////////////////////////////
void advanced_ls(char * folder_name, int option)
{
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames

	char path[1000]; // real path of file
	char pwd[1000]; // working directory
	struct stat buf; // store file's stat
	
	int total_size = 0; // total of size of files

	int * file_size;

	dirp = opendir(folder_name); // open folder(user input)

	if (dirp == NULL) // is not folder
	{
		dirp = opendir("."); // open current folder
		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(folder_name, dir->d_name) == 0) // exist file
			{
				if(flag_l == 0) // print just name
					printf("%s\n", folder_name);
				else if (flag_l == 1) // print Full Format of file
				{
					strcpy(path, ".");
					strcat(path, "/");
					strcat(path, dir->d_name);
					lstat(path, &buf);

					view_advanced_list(path, dir->d_name, &buf);
				}
				closedir(dirp); // close opened directory
				return;
			}
		}
		printf("cannot access %s: No such file or directory\n", folder_name);
	}
	else // is folder
	{
		chdir(folder_name);
		getcwd(pwd, sizeof(char) * 1000);

		printf("\nDirectory path: %s\n", pwd);

		while (dir = readdir(dirp)) // read directory
		{
			if (dir == NULL) // no more file in directory ?
				break;
			
			if (dir->d_name[0] != '.' && flag_a == 0) // except hidden
			{
				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (256));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1

					file_size = (int*)malloc(sizeof(int) * cnt);
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (256));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1

					file_size = (int*)realloc(file_size, sizeof(int) * cnt);
				}

				// total size += file size
				strcpy(path, pwd); // path = pwd
				strcat(path, "/"); // path = pwd/
				strcat(path, dir->d_name); // path = pwd/filename : real path
				stat(path, &buf); // file stat of path -> buf

				file_size[cnt - 1] = buf.st_size;
				total_size += buf.st_blocks / 2;
			}
			else if ( flag_a == 1 ) // include hidden
			{
				if (cnt == 0) // insert : filename(first)
				{
					//dynamic allocation for list
					list = (char**)malloc(sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (256));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1

					file_size = (int*)malloc(sizeof(int) * cnt);
				}
				else // insert : filename
				{
					//re-dynamic allocation for list
					list = (char**)realloc(list, sizeof(char*) * cnt + 1);
					list[cnt] = (char*)malloc(sizeof(char) * (256));
					strcpy(list[cnt], dir->d_name); // insert to list
					cnt++; // count of filenames + 1

					file_size = (int*)realloc(file_size, sizeof(int) * cnt);
				}

				// total size += file size
				strcpy(path, pwd); // path = pwd
				strcat(path, "/"); // path = pwd/
				strcat(path, dir->d_name); // path = pwd/filename : real path
				stat(path, &buf); // file stat of path -> buf

				file_size[cnt - 1] = buf.st_size;
				total_size += buf.st_blocks / 2;
			}
		}

		if (cnt != 0)
		{
			if (flag_S == 1)
				sort_list_S(list, file_size, cnt);
			else
				sort_list(list, cnt); // sort by filename

			if ( flag_l == 0 ) // print filenames to screen
				view_list(list, cnt);
			else if (flag_l == 1) // print file informations to screen
			{
				printf("total : %d\n", total_size);

				for (int i = 0; i < cnt; i++)
				{
					strcpy(path, pwd); // path = pwd
					strcat(path, "/"); // path = pwd/
					strcat(path, list[i]); // path = pwd/filename : real path
					lstat(path, &buf); // file stat of path -> buf

					view_advanced_list(path, list[i], &buf);
				}
			}

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
// sort_folder							//
// ============================================================	//
// Input :	** f_li -> list of folder names		//
// 			cnt -> number of folders in list			//
// 								//
// 								//
// Purpose :	sort folder name list by Error -> File -> Folder		//
//////////////////////////////////////////////////////////////////
void sort_folder(char ** f_li, int cnt)
{
	// Sort [ Error : not folder, file -> File : not folder -> Folder. ]

	DIR * dirp1; // use at open directory
	DIR * dirp2; // use at open directory

	struct dirent *dir; // use at pointing file

	// use at find file, and sort.
	int check1;
	int check2;

	char tmp[256];

	for (int a = 0; a < cnt-1; a++)
	{
		for (int b = 0; b < cnt - 1; b++)
		{
			// reset
			check1 = 0;
			check2 = 0;

			dirp1 = opendir(f_li[b]); // open folder(user input)
			dirp2 = opendir(f_li[b+1]); // open folder(user input)

			if ((dirp1!=NULL) && (dirp2==NULL)) // f_li[b]=exist folder , f_li[b+1]=not exist folder
			{
				strcpy(tmp, f_li[b]);
				strcpy(f_li[b], f_li[b+1]);
				strcpy(f_li[b+1], tmp);
			}
			else if ((dirp1 == NULL) && (dirp2 == NULL)) // both names are not exist folder
			{
				dirp1 = opendir("."); // open current folder
				while (dir = readdir(dirp1)) // read directory
				{
					if (strcmp(f_li[b], dir->d_name) == 0) // if exist file,
						check1 = 1;
					if (strcmp(f_li[b + 1], dir->d_name) == 0) // if exist file,
						check2 = 1;
				}

				if ((check1 != 0) && (check2 == 0)) // f_li[b]=exist file, f_li[b+1]=Not exist file.
				{ // swap
					strcpy(tmp, f_li[b]);
					strcpy(f_li[b], f_li[b + 1]);
					strcpy(f_li[b + 1], tmp);
				}
			}
		}
	}

	closedir(dirp1); // close opened directory
	closedir(dirp2); // close opened directory
}

//////////////////////////////////////////////////////////////////
// final_ls							//
// ============================================================	//
// Input :	* folder_name -> folder name that using at search		//
// 			option -> 1: -a , 2: -l, 3: -la, 0: default			//
// 								//
// 								//
// Purpose :	bring file names from folder, and make list that having file names.		//
//////////////////////////////////////////////////////////////////
void final_ls(char * input, int option)
{
	char ** file_name; // list of file names
	char ** folder_name; // list of folder names
	int folder_cnt = 0; // number of foldernames
	int file_cnt = 0; // number of filenames

	char final_wd[1000]; // final_ls working directory
	char tmp[1000];
	
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	getcwd(final_wd, sizeof(char) * 1000);
	printf("1. final_wd = %s\n", final_wd);

	if (strlen(input) != 1) // 'asdasd/*'
	{
		for (int i = 0; i < strlen(input) - 2; i++)
		{
			tmp[i] = input[i];
		}
		tmp[strlen(input) - 2] = '\0';
	}
	else
		strcpy(tmp, ".");

	

	if (chdir(tmp) == -1) // not folder
	{
		printf("cannot access %s: No such directory\n", tmp);
		closedir(dirp);
	}
	else // folder
	{
		getcwd(final_wd, sizeof(char) * 1000);
		printf("2. final_wd = %s\ntmp = %s\n", final_wd, tmp);
		dirp = opendir(final_wd);

		while (dir = readdir(dirp)) // read directory
		{
			// find folder name. (or file)
			if (flag_a == 1) // all file
			{
				if (folder_cnt == 0) // first input
					folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
				else // not first input
					folder_name = (char**)realloc(folder_name, sizeof(char*) * folder_cnt + 1);

				folder_name[folder_cnt] = (char*)malloc(sizeof(char) * 256);

				strcpy(folder_name[folder_cnt], dir->d_name); // insert to list
				folder_cnt++; // count of folder number + 1
			}
			else if (*dir->d_name != '.' && flag_a != 1) // not all file
			{
				if (folder_cnt == 0) // first input
					folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
				else // not first input
					folder_name = (char**)realloc(folder_name, sizeof(char*) * folder_cnt + 1);

				folder_name[folder_cnt] = (char*)malloc(sizeof(char) * 256);

				strcpy(folder_name[folder_cnt], dir->d_name); // insert to list
				folder_cnt++; // count of folder number + 1
			}
		}

		if (folder_cnt > 1) // number of folder > 1
			sort_folder(folder_name, folder_cnt); // sort : error -> file -> folder

		for (int i = 0; i < folder_cnt; i++) // Print folders !
		{
			chdir(final_wd);
			advanced_ls(folder_name[i], option);
		}

		for (int a = 0; a < folder_cnt; a++)
		{
			free(folder_name[a]); // free folder name allocation
		}
		free(folder_name); // free number of folder allocation
	}

	closedir(dirp);//
}

//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
// Input :	argc -> number of input of program		//
// 		argv -> input of program								//
// 																//
//																//
// Purpose :	make folder list, use it at print file list of a folder.	//
//////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])//
{
	getcwd(origin_wd, sizeof(char) * 1000); // original working directory

	char ** folder_name; // list of folder names
	int folder_cnt = 0; // number of foldernames
	int opt = 0;

	while ((opt = getopt(argc, argv, "alhrS")) != -1) // get option
	{
		switch (opt)
		{
		case 'a': // include option a : print all file (include hidden)
			flag_a++;
			break;
		case 'l': // include option l : print all format of file
			flag_l++;
			break;
		case 'h': // include option l : print all format of file
			flag_h++;
			break;
		case 'r': // include option l : print all format of file
			flag_r++;
			break;
		case 'S': // include option l : print all format of file
			flag_S++;
			break;
		}
	}

	if (flag_a == 1 && flag_l == 0 && flag_h == 0 && flag_r == 0 && flag_S == 0) // option : a
		opt = 1;
	else if (flag_a == 0 && flag_l == 1 && flag_h == 0 && flag_r == 0 && flag_S == 0) // option : l
		opt = 2;
	else if (flag_a == 1 && flag_l == 1 && flag_h == 0 && flag_r == 0 && flag_S == 0) // option : al, la
		opt = 3;
	else if (flag_a == 0 && flag_l == 0 && flag_h == 0 && flag_r == 0 && flag_S == 0) // option : default
		opt = 0;

	for (int i = 1; i < argc; i++) // user input -> folder_name
	{
		// find folder name. (or file)
		if (argv[i][0] != '-' || strcmp(argv[i], ".") == 0 || strcmp(argv[i], "..") == 0)
		{
			if (folder_cnt == 0) // first input
				folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
			else // not first input
				folder_name = (char**)realloc(folder_name, sizeof(char*) * folder_cnt + 1);

			folder_name[folder_cnt] = (char*)malloc(sizeof(char) * 256);
			strcpy(folder_name[folder_cnt], argv[i]); // insert to list
			folder_cnt++; // count of folder number + 1
		}
	}

	if (folder_cnt == 0) // if not exist folder name -> current
	{
		folder_name = (char**)malloc(sizeof(char*) * folder_cnt + 1);
		folder_name[folder_cnt] = (char*)malloc(sizeof(char) * 256);
		strcpy(folder_name[folder_cnt], "."); // insert to list
		folder_cnt++; // count of folder number + 1
	}
	else if (folder_cnt > 1) // number of folder > 1
		sort_folder(folder_name, folder_cnt); // sort : error -> file -> folder

	for (int i = 0; i < folder_cnt; i++) // Print folders !
	{
		chdir(origin_wd);

		if (folder_name[i][strlen(folder_name[i]) - 1] == '*') // special case
			final_ls(folder_name[i], opt);
		else
			advanced_ls(folder_name[i], opt);
	}

	for (int a = 0; a < folder_cnt; a++)
	{
		free(folder_name[a]); // free folder name allocation
	}
	free(folder_name); // free number of folder allocation

	return 0;
}