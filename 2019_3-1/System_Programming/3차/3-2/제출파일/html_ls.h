//////////////////////////////////////////////////////////////////
// File Name	: html_ls.h					//
// Date		: 2018 / 5 / 9					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #3-2 (basic web server)	//
// Description 	: use assignment #2-3, print result at HTML file.				//
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

#define HTML_FILE "html_ls.html" // define html file name

char dir_table[1000];
int flag_a = 0, flag_l = 0, flag_h = 0, flag_r = 0, flag_S = 0, flag_final = 0, flag_p = 0, flag_table = 1, flag_onlyerror = 1;
char origin_wd[1000]; // origin working directory (program executed directory)
char final_wd[1000]; // final_ls working directory
FILE * file;
int final_ls();
char * message;

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
// Output :	s_cnt or 0			//
// 								//
// Purpose :	check the file name, if that having real path ?		//
//////////////////////////////////////////////////////////////////
int check_real_path(char * filename)
{
	int s_cnt = 0; // check slash '/' index
	char tmp[1000];

	strcpy(tmp, filename); // copy

	for (int i = 0; i < strlen(tmp); i++) // check directory.
	{
		if (tmp[i] == '/')
			s_cnt = i; // largest index
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
// 			* B -> second string				//
// Output :	output -> result of compare			//
// 								//
// Purpose :	compare two strings without case		//
//////////////////////////////////////////////////////////////////
int strcmp_i(char * A, char * B)
{
	int output = -100;
	////////////     exception case           /////////////
	if (strcmp(A, ".") == 0 && strcmp(B, "..") == 0)
		output = -1;
	else if (strcmp(A, "..") == 0 && strcmp(B, ".") == 0)
		output = 1;
	else if (strcmp(A, "..") == 0)
		output = -1;
	else if (strcmp(B, "..") == 0)
		output = 1;
	else if (strcmp(A, ".") == 0)
		output = -1;
	else if (strcmp(B, ".") == 0)
		output = 1;
	/////////////////////////////////////////////////////////

	if (output != -100) // exception case
	{
		if (flag_r == 1)
			output *= -1;

		return output;
	}

	char str1[strlen(A) + 1]; // temp string 1
	char str2[strlen(B) + 1]; // temp string 2
	int len; // compare length and return value

	// temp string 1 = A
	if (A[0] == '.') // except '.'
		strcpy(str1, &A[1]);
	else
		strcpy(str1, A);

	// temp string 2 = B
	if (B[0] == '.') // except '.'
		strcpy(str2, &B[1]);
	else
		strcpy(str2, B);

	if (strlen(A) > strlen(B)) // len = shortest length
		len = strlen(B);
	else
		len = strlen(A);

	// change to Uppercase
	for (int i = 0; i < len; i++)
	{
		if (str1[i] <= 122 && str1[i] >= 97) // first
			str1[i] = str1[i] - 32;

		if (str2[i] <= 122 && str2[i] >= 97) // second
			str2[i] = str2[i] - 32;
	}

	if (strcmp(str1, str2) > 0) // str1 > str2
		output = 1;
	else if (strcmp(str1, str2) < 0) // str2 > str1
		output = -1;
	else
		output = 0; // str1 = str2

	if (flag_r == 1)
		output *= -1;

	return output;
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
			if ((size[j] < size[j + 1] && flag_r != 1) || (size[j] > size[j + 1] && flag_r == 1)) // need sort with -r
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
	if (flag_p == -1 || strcmp(filename, HTML_FILE) == 0)
		return;

	struct file_format * f_stat = malloc(sizeof(struct file_format)); // allocation for f_stat
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
	
	
	char backup_path[1024];
	
	if (f_stat->permission[0] == 'l') // symbolic link -> green color
	{
		realpath(path, f_stat->linkpath); // bring symbolic link path at st_nlink.
		
		if (f_stat->linkpath == NULL)
			p_path = "Non path";
		else if ( strncmp( origin_wd, f_stat->linkpath, strlen(origin_wd) ) == 0 ) // linked file and sybolic link in same directory.
		{
			p_path = &f_stat->linkpath[strlen(origin_wd)]; // except path, only file name.
			strcpy(backup_path, path);
			strcpy(path, p_path);
			
			// if same folder, print only file name
			if( strncmp( backup_path, f_stat->linkpath, strlen(backup_path) - strlen(filename) ) == 0 )
				p_path = &f_stat->linkpath[strlen(backup_path) - strlen(filename)];
		}
		else // different directory.
		{
			strcpy(path, "ANNOTHER_PATH_ERROR");
			p_path = f_stat->linkpath; // path/filename
		}
		
		if (flag_l == 0) // not -l option
			fprintf(file, "<tr style=color:green><td><a href=%s>%s</a></td></tr>\r\n", path, filename); // print only filename
		else  // l option
		{
			if (flag_h == 1 && check_h != 0) // option -h : change size format
				fprintf(file, "<tr style=color:green><td><a href=%s>%s -> %s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%.1f%c</td><td>%s</td></tr>\r\n", path, filename, p_path, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time);
			else // not option -h
				fprintf(file, "<tr style=color:green><td><a href=%s>%s -> %s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%d</td><td>%s</td></tr>\r\n", path, filename, p_path, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, (int)f_stat->size, f_stat->m_time);
		}
	}
	else // not symbolic link
	{
		path=path+strlen(origin_wd);
		if (flag_l == 0) // not -l option
		{
			if (f_stat->permission[0] == 'd') // directory
				fprintf(file, "<tr style=color:blue><td><a href=%s>%s</a></td></tr>\r\n", path, filename); // print character of filename
			else // other
				fprintf(file, "<tr style=color:red><td><a href=%s>%s</a></td></tr>\r\n", path, filename); // print character of filename
		}
		else // l option.
		{
			if (f_stat->permission[0] == 'd') // directory
			{
				if (flag_h == 1 && check_h != 0) // option -h : change size format
					fprintf(file, "<tr style=color:blue><td><a href=%s>%s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%.1f%c</td><td>%s</td></tr>\r\n", path, filename, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time);
				else // not option -h
					fprintf(file, "<tr style=color:blue><td><a href=%s>%s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%d</td><td>%s</td></tr>\r\n", path, filename, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, (int)f_stat->size, f_stat->m_time);
			}
			else // other
			{
				if (flag_h == 1 && check_h != 0) // option -h : change size format
					fprintf(file, "<tr style=color:red><td><a href=%s>%s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%.1f%c</td><td>%s</td></tr>\r\n", path, filename, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, f_stat->size, format_h, f_stat->m_time);
				else // not option -h
					fprintf(file, "<tr style=color:red><td><a href=%s>%s</a></td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%d</td><td>%s</td></tr>\r\n", path, filename, f_stat->permission, f_stat->link, f_stat->uid->pw_name, f_stat->gid->gr_name, (int)f_stat->size, f_stat->m_time);
			}
		}
	}

	free(f_stat); // free allocation
}

//////////////////////////////////////////////////////////////////
// advanced_ls							//
// ============================================================	//
// Input :	* folder_name -> folder name that using at search		//
// 			option -> 1: -a , 2: -l, 3: -la, 0: default			//
// 	output : int -1 : error 1 : file 2 : fnmatch file 3: folder 4: fnmatch folder							//
// 								//
// Purpose :	bring file names from folder, and make list that having file names.		//
//////////////////////////////////////////////////////////////////
int advanced_ls(char * folder_name)
{
	DIR * dirp; // use at open directory
	DIR * tmp_dirp; // use at open directory
	struct dirent *dir; // use at pointing file

	char ** list; // list of file names
	int cnt = 0; // number of filenames
	int s_cnt = 0; // slash count
	int check_find=0; // flag of log : find file ?

	char tmp_name[256];
	char path[1000]; // real path of file
	char pwd[1000]; // working directory
	char tmp_folder[256]; // use at copy folder_name
	struct stat buf; // store file's stat

	char * real_path; // use at point real path
	char * file_name; // use at point file name
	
	int total_size = 0; // total of size of files

	int * file_size; // use at sort by size

	dirp = opendir(folder_name); // open folder(user input

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

		// ignore HTML FILE.
		if (strcmp(file_name, HTML_FILE) == 0)
			return 1;

		while (dir = readdir(dirp)) // read directory
		{
			if (strcmp(file_name, dir->d_name) == 0) // exist file
			{
				if (flag_p != -1)
				{
					// check different directory.
					if (dir_table != NULL && strcmp(dir_table, pwd) != 0 && flag_table == 0)
					{
						fputs("</table>\r\n", file);
						flag_table = 1; // if close table -> set flag_table.
						fputs("<br>\r\n", file);
					}
				}

				if (flag_table == 1 && flag_p != -1) // not made table. -> make table
				{
					// print directory path
					fprintf(file, "<br>Directory path: %s<br>\r\n", pwd);
					strcpy(dir_table, pwd);

					// make table.
					if (flag_l == 0) // -l option.
						fputs("<table border=\"1\">\r\n<tr><th>File Name</th></tr>\r\n", file);
					else // not -l option
						fputs("<table border=\"1\">\r\n<tr><th>File Name</th><th>Permission</th><th>Link</th><th>Owner</th><th>Group</th><th>Size</th><th>Last Modified</th></tr>\r\n", file);

					flag_table = 0; // this mean : made table.
				}

				check_find = 1; // flag of find
				if (flag_l == 0 && flag_p != -1) // print just name
				{
					strcpy(path, pwd);
					strcat(path, "/");
					strcat(path, dir->d_name); // path = path / filename
					lstat(path, &buf);

					// print
					view_advanced_list(path, file_name, &buf);
				}
				else if (flag_l == 1) // print Full Format of file
				{
					strcpy(path, pwd);
					strcat(path, "/");
					strcat(path, dir->d_name); // path = path / filename
					lstat(path, &buf);

					// print
					view_advanced_list(path, file_name, &buf);
				}
			}
			else if (fnmatch(file_name, dir->d_name, 0) == 0 && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) // if match,
			{
				if (flag_p != -1)
				{
					// check different directory.
					if (dir_table != NULL && strcmp(dir_table, pwd) != 0 && flag_table == 0)
					{
						fputs("</table>\r\n", file);
						flag_table = 1; // if close table -> set flag_table.
						fputs("<br>\r\n", file);
					}
				}

				if (flag_table == 1 && flag_p != -1) // not made table.
				{
					// print directory
					fprintf(file, "<br>Directory path: %s<br>\r\n", pwd);
					strcpy(dir_table, pwd);

					// make table.
					if (flag_l == 0) // -l option
						fputs("<table border=\"1\">\r\n<tr><th>File Name</th></tr>\r\n", file);
					else // -l option
						fputs("<table border=\"1\">\r\n<tr><th>File Name</th><th>Permission</th><th>Link</th><th>Owner</th><th>Group</th><th>Size</th><th>Last Modified</th></tr>\r\n", file);

					flag_table = 0; // this mean : made table.
 				}

				check_find = 1; // flag of find
				if (strcmp(final_wd, origin_wd) != 0 && strlen(final_wd) != 0) // not origin_wd
				{
					strcpy(path, pwd);
					strcat(path, "/");
					strcat(path, dir->d_name); // path = pwd/match name
				}
				else
					strcpy(path, dir->d_name); // path = match name

				tmp_dirp = opendir(path); // open path

				if (tmp_dirp != NULL ) // is folder,
				{
					closedir(tmp_dirp);
					check_find = advanced_ls(path); // check_find = 3, do advanced_ls().
				}
				else // file.
				{
					check_find = 1;
					strcpy(tmp_name, path);
					if (flag_l == 0 && flag_p != -1) // print just name
					{
						strcpy(path, pwd);
						strcat(path, "/");
						strcat(path, dir->d_name);
						lstat(path, &buf);

						view_advanced_list(path, dir->d_name, &buf);
					}
					else if (flag_l == 1) // print Full Format of file
					{
						strcpy(path, pwd);
						strcat(path, "/");
						strcat(path, dir->d_name);
						lstat(path, &buf);

						view_advanced_list(path, dir->d_name, &buf);
					}
				}
			}
		}

		if (check_find == 0) // print error message : not folder , not file
		{
			if(flag_p != -1) // allow print
				printf("cannot access %s: No such file or directory\r\n", folder_name);
			
			closedir(dirp); // close opened directory
			return -1;
		}
		
		closedir(dirp); // close opened directory
		return check_find;
	}
	else // is folder
	{
		if (flag_p == -1) // not print => return
		{
			closedir(dirp); // close opened directory
			return 3; //folder
		}

		if (flag_table == 0) // if table made.
		{
			fputs("</table>\r\n", file); // close table.
			flag_table = 1; // reset
		}

		chdir(folder_name); // change working directory to directory : folder_name
		getcwd(pwd, sizeof(char) * 1000); // get current working directory

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

		if (flag_final == 1)
			strcpy(path, pwd);

		lstat(path, &buf); // file stat of path -> buf

		if (S_ISLNK(buf.st_mode) && flag_l == 1) // if symbolic and option l
			view_advanced_list(path, folder_name, &buf);
		/////////////////////////////////////////////////////////////////////
		else // not symbolic and option l
		{
			while (dir = readdir(dirp)) // read directory
			{
				if (strcmp(dir->d_name, HTML_FILE) == 0)
					continue;

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

		// print directory path of folder
		getcwd(pwd, sizeof(char) * 1000);
		fprintf(file, "<br>Directory path: %s<br>\r\n", pwd);

		if (cnt != 0) // exist file in folder_name
		{
			if (flag_S == 1) // if option -S
				sort_list_S(list, file_size, cnt); // sort by size
			else if(flag_S == 0) // not option -S
				sort_list(list, cnt); // sort by filename

			fprintf(file, "total : %d<br>\r\n", total_size); // print total size
			
			// make table.
			if(flag_l == 1) // option -l 
				fprintf(file,"<table border=\"1\">\r\n<tr><th>File Name</th><th>Permission</th><th>Link</th><th>Owner</th><th>Group</th><th>Size</th><th>Last Modified</th></tr>\r\n");
			else // not option -l
				fputs("<table border=\"1\">\r\n<tr><th>File Name</th></tr>\r\n", file);

			// print all file in folder.
			for (int i = 0; i < cnt; i++)
			{
				strcpy(path, pwd); // path = pwd
				strcat(path, "/"); // path = pwd/
				strcat(path, list[i]); // path = pwd/filename : real path
				lstat(path, &buf); // file stat of path -> buf
				view_advanced_list(path, list[i], &buf);
			}
			fputs("</table>\r\n", file); // close table.
			flag_table = 1; // set flag. -> not made table
		}
	}
	closedir(dirp); // close opened directory
	return 3; //folder
}


//////////////////////////////////////////////////////////////////
// html_ls								//
// ============================================================	//
// Input :	path -> target path		//
// 		ROOT_PATH -> directory of web server file								//
// 																//
//																//
// Purpose :	find path file or folder, print to HTML FILE	//
//////////////////////////////////////////////////////////////////
int html_ls(char * path, char * ROOT_PATH)//
{
	strcpy(origin_wd, ROOT_PATH); // origin_wd = ROOT_PATH
	chdir(origin_wd);
	int result_ls; // result of ls

	file = fopen(HTML_FILE, "w"); // file open to write
	if (file == 0) // ERROR
	{
		printf("ERROR : cannot open HTML FILE.\n");
		return -1;
	}
	
	fputs("<html>\r\n<head>\r\n<title> ", file);
	fprintf(file, "%s", path);
	fputs("</title>\r\n</head>\r\n<body>\r\n", file);
	
	flag_l = 1;
	if (strcmp(path, ROOT_PATH) != 0 && path != NULL) // path != ROOT_PATH
		flag_a = 1;
	
	flag_p = -1;
	result_ls = advanced_ls(path); // execute ls -> make HTML FILE
	flag_p = 0;
	
	if(result_ls == -1) // ERROR
		fprintf(file, "<h1>Not Found</h1><br>The request URL %s was not found on this server<br>HTTP 404 - Not Page Found", path+strlen(origin_wd));
	else // NOT ERROR
	{
		if (strcmp(path, ROOT_PATH) != 0 && path != NULL)
			fputs("<h1>System Programming Http</h1><br>", file);
		else
			fputs("<h1>Welcome to System Programming Http</h1><br>", file);
		
		result_ls = advanced_ls(path); // execute ls -> make HTML FILE
	}
	
	if (flag_table == 0) // if table not close
		fputs("</table>\r\n", file);
		
	//fprintf(file, "<br><h3><a href=%s> Close_Server </a></h3>", "$EXIT");
	fputs("</body>\r\n", file); // close body

	fputs("</html>", file); // close html
	fclose(file); // clse file.
	return result_ls; // end of program
}
