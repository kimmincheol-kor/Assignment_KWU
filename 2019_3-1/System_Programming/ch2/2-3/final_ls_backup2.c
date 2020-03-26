//////////////////////////////////////////////////////////////////
// File Name	: final_ls.c					//
// Date		: 2018 / 4 / 10					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #2-3 (final_ls)	//
// Description 	: ...						//
//////////////////////////////////////////////////////////////////
// sp2015722087/* -a  오류.
// 일부 폴더 접근 오류.

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

int flag_a = 0, flag_l = 0, flag_h = 0, flag_r = 0, flag_S = 0, flag_final=0, flag_p=0;
char origin_wd[1000];
char final_wd[1000]; // final_ls working directory

int final_ls();

struct file_format // store information of file (Full Format)
{
	char permission[11]; // mode of file
	int link; // number of hard link of file
	struct passwd * uid; // user id of owner of file
	struct group * gid; // group id of owner of file
	double size; // size of file
	char m_time[100]; // modified time of file
	char linkpath[1000]; // use at symbolic link
};

//////////////////////////////////////////////////////////////////
// check_real_path							//
// ============================================================	//
// Input :	* filename -> file name			//
// 						//
// Output :	s_cnt or -1			//
// 								//
// Purpose :	check the file name, if that having real path ?		//
//////////////////////////////////////////////////////////////////
int check_real_path(char * filename)
{
	int s_cnt = 0;
	char * real_path;
	char tmp[1000];

	strcpy(tmp, filename);

	for (int i = 0; i < strlen(tmp); i++) // check directory.
	{
		if (tmp[i] == '/')
			s_cnt = i;
	}
	if (s_cnt != 0) // find in real path folder
	{
		tmp[s_cnt] = '\0'; // devide < path > / < file >

		chdir(tmp); // change working directory to real_path
		return s_cnt; // sucess
	}
	else
		return 0; // fail
}

//////////////////////////////////////////////////////////////////
// swap							//
// ============================================================	//
// Input :	* str1 -> first string				//
// 		* str2 -> second string				//
// 		//
// 								//
// Purpose :	swap two string		//
//////////////////////////////////////////////////////////////////
void swap(char * str1, char * str2)
{
	char tmp[1000];

	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);

	return;
}

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

	if (flag_r == 1) // reverse
	{
		if (strcmp(str1, str2) > 0) // str1 > str2
			return -1;
		else if (strcmp(str1, str2) < 0) // str2 > str1
			return 1;
		else
			return 0; // str1 = str2
	}
	else // default
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
// Purpose :	sort the list of filenames by compare file names			//
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
// Input :	** li -> list of file names			//
// 			int size[] -> size of files			//
// 			len -> number of file names				//
// 								//
// Purpose :	sort the list of filenames by compare file size.			//
//////////////////////////////////////////////////////////////////
void sort_list_S(char ** li, int size[], int len)
{
	// use at swap.
	char tmp_s[256];
	int tmp_i;
	
	// sort like bublle sort
	for (int i = 0; i < len - 1; i++) // total cycle
	{
		if (li[i][0] == '\0') // end of list
			break;

		for (int j = 0; j < len - 1; j++) // one cycle
		{
			if( (size[j] < size[j+1] && flag_r != 1) || (size[j] > size[j + 1] && flag_r == 1) ) // need sort with -r
			{
				//swap file name
				strcpy(tmp_s, li[j]);
				strcpy(li[j], li[j + 1]);
				strcpy(li[j + 1], tmp_s);

				//swap file size
				tmp_i = size[j];
				size[j] = size[j + 1];
				size[j + 1] = tmp_i;
			}
			else if (size[j] == size[j + 1]) // if same size -> sort by string
			{
				if (strcmp_i(li[j], li[j + 1]) == 1) // need sort ?
				{
					// swap file name
					strcpy(tmp_s, li[j]);
					strcpy(li[j], li[j + 1]);
					strcpy(li[j + 1], tmp_s);
				}
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
	if (flag_p == -1)
		return;

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
	if (flag_p == -1)
		return;

	struct file_format * f_stat = malloc(sizeof(struct file_format)) ; // allocation for f_stat
	char * p_path; // pointer use at symbolic link

	char format_h; // use at option -h : K , M , G , T

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
	f_stat->permission[10] = '\0'; // last value of permission is NULL

	f_stat->link = buf->st_nlink; // st_nlink ~> f_stat->link
	f_stat->uid = getpwuid(buf->st_uid); // st_uid ~> f_stat->uid
	f_stat->gid = getgrgid(buf->st_gid); // st_gid ~> f_stat->gid
	f_stat->size = buf->st_size; // st_size ~> f_stat->size
	
	// make time format by st_mtime(modified time)
	strcpy(f_stat->m_time, ctime(&buf->st_mtime));
	// Month
	f_stat->m_time[0] = f_stat->m_time[4];
	f_stat->m_time[1] = f_stat->m_time[5];
	f_stat->m_time[2] = f_stat->m_time[6];
	f_stat->m_time[3] = ' ';
	// Day
	f_stat->m_time[4] = f_stat->m_time[8];
	f_stat->m_time[5] = f_stat->m_time[9];
	f_stat->m_time[6] = ' ';
	// Time
	f_stat->m_time[7] = f_stat->m_time[11];
	f_stat->m_time[8] = f_stat->m_time[12];
	f_stat->m_time[9] = f_stat->m_time[13];
	f_stat->m_time[10] = f_stat->m_time[14];
	f_stat->m_time[11] = f_stat->m_time[15];
	f_stat->m_time[12] = '\0';
	
	int check_h = 0; // number of calculation of 'size/1024'
	if (flag_h == 1) // option -h , change size format
	{
		while (1)
		{
			if (f_stat->size >= 1024)
			{
				f_stat->size = f_stat->size / 1024.0;
				check_h++;
			}
			else 
				break;
		}

		switch (check_h)
		{
		case 1: // kilo
			format_h = 'k';
			break;
		case 2: // mega
			format_h = 'M';
			break;
		case 3: // giga
			format_h = 'G';
			break;
		case 4: // tera
			format_h = 'T';
			break;
		default: // non calculation
			break;
		}
	}

	if (f_stat->permission[0] == 'l') // symbolic link ?
	{
		realpath(path, f_stat->linkpath); // bring symbolic link path at st_nlink.

		if (f_stat->linkpath == NULL)
			p_path = "Non path";
		else if ( strncmp(path, f_stat->linkpath, strlen(path) - strlen(filename) ) == 0 ) // linked file and sybolic link in same directory.
			p_path = &f_stat->linkpath[strlen(path) - strlen(filename)]; // except path, only file name.
		else // different directory.
			p_path = f_stat->linkpath; // path/filename
	
		if (flag_h == 1 && check_h != 0) // option -h : change size format
			printf("%s	%d	%s	%s	%.1f%c	%s	%s -> %s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time, filename, p_path);
		else
			printf("%s	%d	%s	%s	%d	%s	%s -> %s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, (int)f_stat->size, f_stat->m_time, filename, p_path);
	}
	else // not symbolic link
	{
		if (flag_h == 1 && check_h != 0) // option -h : change size format
			printf("%s	%d	%s	%s	%.1f%c	%s	%s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time, filename);
		else
			printf("%s	%d	%s	%s	%d	%s	%s\n", f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, (int)f_stat->size, f_stat->m_time, filename);
	}

	free(f_stat); // free allocation
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
int advanced_ls(char * folder_name)
{
	//printf("im in advanced_ls, having %s\n", folder_name);
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	int s_cnt = 0; // slash count
	int check_find=0;

	char path[1000]; // real path of file
	char pwd[1000]; // working directory
	char tmp_folder[256]; // use at copy folder_name
	struct stat buf; // store file's stat

	char * real_path; // use at point real path
	char * file_name; // use at point file name
	
	int total_size = 0; // total of size of files

	int * file_size; // use at sort by size

	if (flag_final == 1)
		chdir(final_wd);
	else
		chdir(origin_wd);

	dirp = opendir(folder_name); // open folder(user input)

	if (dirp == NULL) // is not folder
	{
		///////////////////// check : file in real path ? ///////////////////////// 
		strcpy(tmp_folder, folder_name); // copy
		s_cnt = check_real_path(tmp_folder);
		
		if (s_cnt != 0) // open real path folder
		{
			file_name = &tmp_folder[s_cnt+1]; // file name is last word in folder_name
			getcwd(pwd, sizeof(char) * 1000); // pwd = real_path
			dirp = opendir(pwd); // open real_path folder *****
		}
		else // open current folder
		{
			file_name = folder_name;
			getcwd(pwd, sizeof(char) * 1000); // pwd = current directory
			dirp = opendir(pwd); // open current folder *****
		}
		//////////////////////////////////////////////////////////////////////////////

		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(file_name, dir->d_name) == 0) // exist file
			{
				check_find = 1; // flag of find
				if(flag_l == 0 && flag_p != -1) // print just name
					printf("%s\n", dir->d_name);
				else if (flag_l == 1) // print Full Format of file
				{
					strcpy(path, pwd);
					strcat(path, "/");
					strcat(path, dir->d_name);
					lstat(path, &buf);

					view_advanced_list(path, folder_name, &buf);
				}
				
			}
			else if (fnmatch(file_name, dir->d_name, 0) == 0)
			{
				check_find = 1; // flag of find

				strcpy(path, pwd);
				strcat(path, "/");
				strcat(path, dir->d_name); // path = pwd/match name

				if (dirp != NULL && flag_final == 1) // folder && from final
					advanced_ls(path);
				else // not from final. -> just print
				{
					if (flag_l == 0 && flag_p != -1) // print just name
						printf("%s\n", dir->d_name);
					else if (flag_l == 1) // print Full Format of file
					{
						strcpy(path, pwd);
						strcat(path, "/");
						strcat(path, dir->d_name);
						lstat(path, &buf);

						view_advanced_list(path, folder_name, &buf);
					}
				}
			}
		}
		if (check_find != 1) // print error message : not folder , not file
		{
			if(flag_p != -1)
				printf("cannot access %s: No such file or directory\n", folder_name);

			closedir(dirp); // close opened directory
			return -1;
		}
		else if (flag_p == -1)
			return 1;

		closedir(dirp); // close opened directory
	}
	else // is folder
	{
		if (flag_p == -1)
		{
			closedir(dirp); // close opened directory
			return 3; //folder
		}

		chdir(folder_name); // change working directory to directory : folder_name
		getcwd(pwd, sizeof(char) * 1000); // get current working directory

		printf("\nDirectory path: %s\n", pwd); // print current working directory

		//////////////// check : is this symbolic folder ? //////////////////
		if (folder_name[0] == '/') // real path input
			strcpy(path, folder_name); // path = folder_name
		else // current folder input
		{
			getcwd(pwd, sizeof(char) * 1000);

			strcpy(path, pwd); // path = origin_wd
			strcat(path, "/"); // path = pwd/
			strcat(path, folder_name); // path = pwd/filename : real path
		}
		lstat(path, &buf); // file stat of path -> buf

		if (S_ISLNK(buf.st_mode) && flag_l == 1) // if symbolic and option l
			view_advanced_list(path, folder_name, &buf);
		/////////////////////////////////////////////////////////////////////
		else // not symbolic and option l
		{
			while (dir = readdir(dirp)) // read directory
			{
				if (dir == NULL) // no more file in directory
					break;

				if (dir->d_name[0] != '.' && flag_a == 0) // except hidden file
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
					lstat(path, &buf); // file stat of path -> buf

					file_size[cnt - 1] = buf.st_size;
					total_size += buf.st_blocks / 2;
				}
				else if (flag_a == 1) // include hidden file
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
					lstat(path, &buf); // file stat of path -> buf

					file_size[cnt - 1] = buf.st_size;
					total_size += buf.st_blocks / 2;
				}
			}
		}

		if (cnt != 0) // exist file in folder_name
		{
			if (flag_S == 1) // if option -S
				sort_list_S(list, file_size, cnt); // sort by size
			else if(flag_S == 0)
				sort_list(list, cnt); // sort by filename

			if ( flag_l == 0 ) // print filenames to screen
				view_list(list, cnt);
			else if (flag_l == 1) // print file informations to screen
			{
				printf("total : %d\n", total_size); // print total size

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

		closedir(dirp); // close opened directory
		return 3; //folder
	}
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

	struct stat buf1;
	struct stat buf2;

	struct dirent *dir; // use at pointing file

	// use at find file, and sort.
	int check1;
	int check2;

	// use at check real path file
	int s_cnt1 = 0;
	int s_cnt2 = 0;

	int type1 = 0;
	int type2 = 0;

	char pwd[1000]; // working directory
	char path[1000];

	// use at copy folder name
	char folder1[256];
	char folder2[256];

	// use at point file_name , real path in real path file
	char * file_name1;
	char * file_name2;
	char * real_path1;
	char * real_path2;

	for (int a = 0; a < cnt-1; a++)
	{
		for (int b = 0; b < cnt - 1; b++)
		{
			// reset working directory
			if (flag_final == 1) // execute sort from final_ls
				chdir(final_wd); // original working directory = executed program folder
			else // execute sort from main
				chdir(origin_wd); // original working directory = executed program folder
			getcwd(pwd, sizeof(char) * 1000); // pwd = origin_wd or final_wd

			// reset temporary data
			check1 = 0;
			check2 = 0;

			s_cnt1 = check_real_path(f_li[b]);
			s_cnt2 = check_real_path(f_li[b + 1]);

			// copy folder name
			strcpy(folder1, f_li[b]);
			strcpy(folder2, f_li[b + 1]);

			// if f_li[b], f_li[b+1] are not real path file, these are just file name
			file_name1 = f_li[b];
			file_name2 = f_li[b + 1];

			//////////// b
			if (f_li[b][strlen(f_li[b]) - 1] == '*')
			{
				flag_p = -1;
				type1 = final_ls(f_li[b]);
				flag_p = 0;
			}
			else if (f_li[b][strlen(f_li[b]) - 1] != '*')
			{
				flag_p = -1;
				type1 = advanced_ls(f_li[b]);
				flag_p = 0;
			}

			/////////// b+1
			if (f_li[b+1][strlen(f_li[b+1]) - 1] == '*')
			{
				flag_p = -1;
				type2 = final_ls(f_li[b + 1]);
				flag_p = 0;
			}
			else if (f_li[b+1][strlen(f_li[b+1]) - 1] != '*')
			{
				flag_p = -1;
				type2 = advanced_ls(f_li[b+1]);
				flag_p = 0;
			}

			if (type1 > type2)
			{
				swap(f_li[b], f_li[b + 1]);
			}
			else if (type1 == type2 && flag_final == 1)
			{
				if (type1 == 3) // Folder name sort in final_ls
				{
					if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // need sort ?
					{
						swap(f_li[b], f_li[b + 1]);
					}
				}
				else if (type1 == 1) // file sort in final_ls
				{
					if (flag_S == 1) //sort by size
					{
						chdir(final_wd);
						getcwd(pwd, sizeof(char) * 1000);

						strcpy(path, pwd); // path = pwd
						strcat(path, "/"); // path = pwd/
						strcat(path, f_li[b]); // path = pwd/filename : real path
						stat(path, &buf1); // file stat of path -> buf1

						strcpy(path, pwd); // path = pwd
						strcat(path, "/"); // path = pwd/
						strcat(path, f_li[b + 1]); // path = pwd/filename : real path
						stat(path, &buf2); // file stat of path -> buf2

						if ((buf1.st_size > buf2.st_size && flag_r == 1) || (buf1.st_size < buf2.st_size && flag_r == 0))
						{
							swap(f_li[b], f_li[b + 1]);
						}
						else if (buf1.st_size == buf2.st_size) // if same size -> sort by string
						{
							if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // need sort ?
							{
								// swap file name
								swap(f_li[b], f_li[b + 1]);
							}
						}
					}
					else // sort by string
					{
						if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // need sort ?
						{
							swap(f_li[b], f_li[b + 1]);
						}
					}
				}
			}
			


			//// compare A with B
			//if ((dirp1 != NULL) && (dirp2 != NULL) && flag_final==1) // both are folder, flag_final==1, Folder name sort
			//{
			//	if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // need sort ?
			//	{
			//		swap(f_li[b], f_li[b + 1]);
			//	}
			//}
			//else if ((dirp1 != NULL) && (dirp2 == NULL)) // f_li[b]=exist folder , f_li[b+1]=not exist folder
			//{
			//	swap(f_li[b], f_li[b + 1]);
			//}
			//else if ((dirp1 == NULL) && (dirp2 == NULL)) // both names are not exist folder
			//{
			//	///////////////////// check : file in real path ? /////////////////////////
			//	s_cnt1 = check_real_path(folder1);
			//	if (s_cnt1 != -1) // is real path input,
			//	{
			//		file_name1 = &folder1[s_cnt1 + 1]; // file name is last word in folder_name
			//		getcwd(pwd, sizeof(char) * 1000); // pwd = real_path
			//		dirp1 = opendir(pwd); // open real_path folder
			//	}
			//	else // not real path input
			//	{
			//		if (flag_final == 1)
			//			chdir(final_wd);
			//		else 
			//			chdir(origin_wd);
			//		getcwd(pwd, sizeof(char) * 1000); // pwd = origin_wd
			//		dirp1 = opendir(pwd); // open origin folder
			//	}
			//	//////////////////////////////////////////////////////////////////////////////

			//	///////////////////// check : file in real path ? /////////////////////////
			//	s_cnt2 = check_real_path(folder2);
			//	if (s_cnt2 != -1) // is real path input,
			//	{
			//		file_name2 = &folder2[s_cnt2 + 1]; // file name is last word in folder_name
			//		getcwd(pwd, sizeof(char) * 1000); // pwd = real_path
			//		dirp2 = opendir(pwd); // open real_path folder
			//	}
			//	else // not real path input
			//	{
			//		if (flag_final == 1)
			//			chdir(final_wd);
			//		else
			//			chdir(origin_wd);
			//		getcwd(pwd, sizeof(char) * 1000); // pwd = origin_wd
			//		dirp2 = opendir(pwd); // open origin folder
			//	}
			//	//////////////////////////////////////////////////////////////////////////////

			//	while (dir = readdir(dirp1)) // read directory A
			//	{
			//		if (strcmp(file_name1, dir->d_name) == 0) // if exist file,
			//			check1 = 1;
			//	}
			//	while (dir = readdir(dirp2)) // read directory B
			//	{
			//		if (strcmp(file_name2, dir->d_name) == 0) // if exist file,
			//			check2 = 1;
			//	}
			//	if ((check1 != 0) && (check2 == 0)) // f_li[b]=exist file, f_li[b+1]=Not exist file.
			//	{
			//		swap(f_li[b], f_li[b + 1]);
			//	}
			//	else if ((check1 != 0) && (check2 != 0) && flag_final == 1) // both are exist file, flag_final==1, File name sort
			//	{
			//		if (flag_S == 1) // if option -S, -> sort by size
			//		{
			//			
			//			char path[1000]; // real path of file
			//			char pwd[1000]; // working directory

			//			if (check_real_path(f_li[b]) == -1)
			//			{
			//				if (flag_final == 1)
			//					chdir(final_wd);
			//				else
			//					chdir(origin_wd);
			//			}

			//			getcwd(pwd, sizeof(char) * 1000);
			//			strcpy(path, pwd); // path = pwd
			//			strcat(path, "/"); // path = pwd/
			//			strcat(path, file_name1); // path = pwd/filename : real path
			//			lstat(path, &buf1); // file stat of path -> buf

	
			//			if (check_real_path(f_li[b] + 1) == -1)
			//			{
			//				if (flag_final == 1)
			//					chdir(final_wd);
			//				else
			//					chdir(origin_wd);
			//			}

			//			getcwd(pwd, sizeof(char) * 1000);
			//			strcpy(path, pwd); // path = pwd
			//			strcat(path, "/"); // path = pwd/
			//			strcat(path, file_name2); // path = pwd/filename : real path
			//			lstat(path, &buf2); // file stat of path -> buf

			//			if ((buf1.st_size > buf2.st_size && flag_r == 1) || (buf1.st_size < buf2.st_size && flag_r == 0))
			//			{
			//				swap(f_li[b], f_li[b + 1]);
			//			}
			//			else if (buf1.st_size == buf2.st_size) // if same size -> sort by string
			//			{
			//				if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // need sort ?
			//				{
			//					// swap file name
			//					swap(f_li[b], f_li[b + 1]);
			//				}
			//			}
			//		}
			//		else if (strcmp_i(f_li[b], f_li[b + 1]) == 1) // just name sort,
			//		{
			//			swap(f_li[b], f_li[b + 1]);
			//		}
			//	}
		
			//}
		}
	}
	return;

	//closedir(dirp1); // close opened directory
	//closedir(dirp2); // close opened directory

	//flag_final = 0; // flag down
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
int final_ls(char * input)
{
	char ** file_name; // list of file names
	char ** folder_name; // list of folder names
	int folder_cnt = 0; // number of foldernames
	int file_cnt = 0; // number of filenames

	int s_cnt = 0;
	char * real_path;

	char tmp[1000];
	
	DIR * dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	if (strlen(input) != 1)
	{
		for (int i = 0; i < strlen(input); i++) // check directory.
		{
			if (input[i] == '/')
				s_cnt = i;
		}

		if (s_cnt != strlen(input)-2) // '-/A_what*'
		{
			flag_final = 1;
			advanced_ls(input);
			flag_final = 0;
			return 2;
		}
		else // 'A_path/*'
		{
			strcpy(tmp, input);
			tmp[strlen(input) - 2] = '\0'; // tmp = A_path
		}
	}
	else // '*'
		strcpy(tmp, ".");

	if (chdir(tmp) == -1) // A_path is not folder.
	{
		if(flag_p != -1)
			printf("cannot access %s: No such directory\n", tmp);

		return -1;
	}
	else // A_path is folder
	{
		if(flag_p == -1)
			return 4;

		getcwd(final_wd, sizeof(char) * 1000); // final_wd = A_path
		dirp = opendir("."); // current working directory = A_path

		while (dir = readdir(dirp)) // read directory
		{
			// find folder name. (or file)
			if (flag_a == 1 && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) // all file
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
		{
			flag_final = 1; // flag up
			sort_folder(folder_name, folder_cnt); // sort : error -> file -> folder
		}
		
		printf("\n* Directory path: %s\n", final_wd);
		for (int i = 0; i < folder_cnt; i++) // Print folders !
		{
			chdir(final_wd);
			advanced_ls(folder_name[i]);
		}

		for (int a = 0; a < folder_cnt; a++)
		{
			free(folder_name[a]); // free folder name allocation
		}
		free(folder_name); // free number of folder allocation
		closedir(dirp);
	}
	return 4;
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
		case 'h': // include option h : change format of print file size
			flag_h++;
			break;
		case 'r': // include option r : reverse sort
			flag_r++;
			break;
		case 'S': // include option S : sort by file size
			flag_S++;
			break;
		}
	}

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

	for (int a = 0; a < folder_cnt; a++)
	{
		printf("@ Print Folder @ \n%s\n", folder_name[a]);
	}
	printf("End of Folder\n\n");
	for (int i = 0; i < folder_cnt; i++) // Print folders !
	{
		chdir(origin_wd);

		if (folder_name[i][strlen(folder_name[i]) - 1] == '*') // special case
			final_ls(folder_name[i]);
		else
			advanced_ls(folder_name[i]);
	}

	for (int a = 0; a < folder_cnt; a++)
	{
		free(folder_name[a]); // free folder name allocation
	}
	free(folder_name); // free number of folder allocation
	
	return 0;
}