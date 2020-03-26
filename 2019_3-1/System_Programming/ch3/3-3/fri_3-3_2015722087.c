//////////////////////////////////////////////////////////////////
// File Name	: Fri_3-3_2015722087.c					//
// Date		: 2018 / 5 / 15					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #3-3 (advanced web server)	//
// Description 	: advanced web server that use html_ls, send result to browser client				//
//////////////////////////////////////////////////////////////////

#define _GNU_SOURCE

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<time.h>
#include<signal.h>
#include "html_ls.h"

#define URL_LEN 256
#define BUFSIZE 1024
#define PORTNO   40302

// information of client struct.
struct client_inf {
	int num; // connection number
	char ip_addr[16]; // ip address
	int pid; // process id for client
	int port; // port for client
	char time[25]; // ctime of time that connected
};

// global variables
int num_request = 0; // number of connection that server with clients
struct client_inf array[10]; // store latest connected client information
int * array_pid; // store child pid
int socket_fd; // socket decriptor
char ** accessible_ip; // store ip from accessible.usr
int num_accessible=0; // number of ip from accessible.usr
int wait_num=0;
int status = 0;

//////////////////////////////////////////////////////////////////
// void add_client								//
// ============================================================	//
//		input : in_array[] -> array that store client information	//												//
//				input -> new information of new client	//
//				num -> number of request = number of information in in_array[]	//
//																//
// Purpose : add new information to in_array[]		//
//////////////////////////////////////////////////////////////////
void add_client(struct client_inf in_array[], struct client_inf input, int num)
{
	for (int i = 9; i >= 0; i--) // start checking from last data
	{
		if (i < num) // number of request > i
		{
			if (i != 9) // except in_array[9] -> delete.
			{
				in_array[i + 1] = in_array[i]; // move to upper memory
				in_array[i + 1].num = in_array[i].num+1;
			}
		}
	}
	in_array[0] = input; // new data added
}

//////////////////////////////////////////////////////////////////
// void print_client								//
// ============================================================	//
//		input : in_array[] -> array that store client information	//	
//				num -> number of request = number of information in in_array[]	//
//																//
// Purpose : print informations of in_array[]		//
//////////////////////////////////////////////////////////////////
void print_client(struct client_inf in_array[], int num)
{
	puts("================ Connection History ================");
	printf("Number of request(s) : %d\n", num);
	puts("No.	IP		PID	PORT	TIME");
	
	int repeat; // number of repeat
	
	if(num > 10) // if num > 10
		repeat = 10; // largest number 10
	else // if num < 10
		repeat = num; // repeat
		
	// print all of informaion of client in in_array[]
	for (int i = 0; i < repeat; i++)
	{
		printf("%d	%s	%d	%d	%s", in_array[i].num, in_array[i].ip_addr, in_array[i].pid, in_array[i].port, in_array[i].time);
	}
	puts("====================================================\n");
}

//////////////////////////////////////////////////////////////////
// void signalHandler_c								//
// ============================================================	//
//		input : sig -> Signal	//	
//														//
// Purpose :	handle a signal	//
//////////////////////////////////////////////////////////////////
void signalHandler_c(int sig)
{
	if(sig == SIGINT) // SIGINT Signal
	{
		exit(0);
	}
	if(sig == SIGTSTP) // SIGTSTP Signal
	{
		exit(0);
	}
}

//////////////////////////////////////////////////////////////////
// void signalHandler_p								//
// ============================================================	//
//		input : sig -> Signal	//	
//														//
// Purpose :	handle a signal	//
//////////////////////////////////////////////////////////////////
void signalHandler_p(int sig)
{	
	if(sig == SIGINT) // wait for child, exit. Signal
	{
		if(num_accessible > 0)
		{
			for(int i=0; i<num_accessible; i++)
				free(accessible_ip[i]);
			
			free(accessible_ip);
		}
		if(num_request > 0)
		{
			for (int a = 0; a < num_request; a++)
			{ // wait for child.
				waitpid(array_pid[a], &status, 0);
			}
			free(array_pid);
		}
		close(socket_fd);
		exit(10);	
	}
	if(sig == SIGTSTP) // kill the child, exit Signal
	{
		if(num_accessible > 0)
		{
			for(int i=0; i<num_accessible; i++)
				free(accessible_ip[i]);
			
			free(accessible_ip);
		}
		if(num_request > 0)
		{
			for (int a = 0; a < num_request; a++)
			{
				kill(array_pid[a], SIGINT);
				waitpid(array_pid[a], &status, WNOHANG);
			}
			free(array_pid);
		}
		close(socket_fd);
		exit(10);
	}
	if(sig == SIGALRM) // Alarm Signal
	{
		alarm(10); // alarm again, ten seconds later.
		if(num_request > 0)
		{
			print_client(array, num_request); // print Array.
		}
	}
}


//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
//														//
// Purpose :	accept connection from client, send response message that response for request message	//
//////////////////////////////////////////////////////////////////
int main()
{
	struct sockaddr_in server_addr, client_addr;
	int client_fd;
	int len, len_out;
	int opt = 1;
	pid_t pid;
	char ROOT_PATH[BUFSIZE] = { 0, };
	
	struct in_addr tmp_address;
	
	time_t t;
	struct in_addr inet_client_address;
	char buf[BUFSIZE] = { 0, };
	char tmp[BUFSIZE] = { 0, };
	char input_buf[BUFSIZE] = { 0, };
	char method[20] = { 0, };
	char * tok = NULL;
	
	struct client_inf input; // store new client information
	
	int flag_access=0; // check accessible flag
	FILE * accessible;	// accessible.usr file
	char line_ip[16]; // line of file
	
	accessible = fopen("accessible.usr", "r"); // file open.
	if(accessible == NULL)
	{
		puts("file error");
		return -1;
	}
	
	while(1)
	{
		if(feof(accessible) != 0) // if end of file, break.
			break;
		
		fgets(line_ip, sizeof(char)*16, accessible); // get line
		
		// dynamic allocation
		if(num_accessible == 0) // first line
			accessible_ip = (char**)malloc(sizeof(char*));
		else // not first line
			accessible_ip = (char**)realloc(accessible_ip, sizeof(char*) * num_accessible + 1);
		
		accessible_ip[num_accessible] = (char*)malloc(sizeof(char) * (16));
		
		// add to accessible_ip array.
		strcpy(accessible_ip[num_accessible], line_ip);
		
		for(int i=0; i<16; i++)
		{ // '\r\n' -> '\0'
			if(accessible_ip[num_accessible][i] == '\r' || accessible_ip[num_accessible][i] == '\n')
			{
				accessible_ip[num_accessible][i] = '\0';
				break;
			}
		}
		
		num_accessible++; // num ++
	}
	fclose(accessible); // close file

	getcwd(ROOT_PATH, BUFSIZE); // get ROOT_PATH

	//creat socket, socket_fd = socket descriptor
	if ((socket_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Server: Can't open stream socket.");
		return 0;
	}

	// set option of socket
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORTNO);
	
	// associate address with socket
	if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("server: can't bind local address.\n");
		return 0;
	}

	// ready to accept connection, queue size = 5
	listen(socket_fd, 5);
	
	// ready to get signal
	alarm(10);
	signal(SIGALRM, signalHandler_p);
	signal(SIGINT, signalHandler_p);
	signal(SIGTSTP, signalHandler_p);
	
	while (1) // always on
	{
		chdir(ROOT_PATH);
		len = sizeof(client_addr);
		
		// ready to accept.
		client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &len); // wait for connect
		if (client_fd < 0)
		{
			printf("Server: accept failed.\n");
			return 0;
		}
		
		// Reset data
		t = time(NULL);
		strcpy(buf, "\0");
		strcpy(tmp, "\0");
		strcpy(input_buf, "\0");
		strcpy(method, "\0");
		tok = NULL;
		
		inet_client_address.s_addr = client_addr.sin_addr.s_addr;
		read(client_fd, buf, BUFSIZE);
		strcpy(tmp, buf);

		// Exception check
		tok = strtok(tmp, " ");
		strcpy(method, tok);
		if (strcmp(method, "GET") == 0)
		{
			tok = strtok(NULL, " ");
			if (strcmp(tok, "/favicon.ico") == 0 || strcmp(tok, "/E") == 0) // ignore /favicon.ico
			{
				close(client_fd);
				continue;
			}
			else if (strcmp(tok, "/$EXIT") == 0)
			{
				close(client_fd);
				break;
			}
			
			strcpy(input_buf, tok);
		}
		else // not GET request
		{
			close(client_fd);
			continue;
		}
		
		// Accessible check
		for(int a=0; a<num_accessible; a++)
		{
			if(strcmp(accessible_ip[a], inet_ntoa(inet_client_address))==0 || fnmatch(accessible_ip[a], inet_ntoa(inet_client_address), 0) == 0)
				flag_access = 1;
		}
		
		if(flag_access == 0) // can't accept
		{
			char response_message[BUFSIZE] = { 0, };
			char response_header[BUFSIZE] = { 0, };
			// make ERROR response message
			sprintf(response_message, "<h1>Access denied</h1><h1>Your IP : %s</h1>You have no permission to access this web server.<br>HTTP 403.6 - Forbidden : IP address reject", inet_ntoa(inet_client_address));
			sprintf(response_header, "HTTP/1.1 404 ERROR\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_message));

			// send ERROR response message
			write(client_fd, response_header, strlen(response_header));
			write(client_fd, response_message, strlen(response_message));
				
			continue;
		}

		pid = fork(); // fork !!

		if (pid < 0) // fork error
		{
			puts("fork error");
			close(client_fd);
			continue;
		}
		else if (pid == 0) // child process
		{
			// ready to get signal
			signal(SIGINT, signalHandler_c);
			signal(SIGTSTP, signalHandler_c);
			
			char response_message[BUFSIZE] = { 0, };
			char response_header[BUFSIZE] = { 0, };
			char path[BUFSIZE] = { 0, };
			int result;
		
			// new client
			puts("==================== New Client ====================");
			printf("IP : %s\nPort : %d\n", inet_ntoa(inet_client_address), client_addr.sin_port);
			puts("====================================================\n");
			
			// check path
			strcpy(path, ROOT_PATH); // default : path = ROOT_PATH
			if (strcmp(input_buf, "/") != 0) // not ROOT_PATH,
				strcat(path, input_buf); // path = ROOT_PATH/input

			chdir(ROOT_PATH);
			result = html_ls(path, ROOT_PATH); // execute html_ls
			chdir(ROOT_PATH);

			if (((fnmatch("*.jpg", input_buf + 1, FNM_CASEFOLD) == 0) || (fnmatch("*.PNG", input_buf + 1, FNM_CASEFOLD) == 0) || (fnmatch("*.jpeg", input_buf + 1, FNM_CASEFOLD) == 0)) && result == 1) // image
			{
				FILE * img;
				int image_size;
				char image_line[BUFSIZE];
				img = fopen(path, "r");

				fseek(img, 0, SEEK_END);
				image_size = ftell(img); // find image size
				fseek(img, 0, SEEK_SET);

				// send response header message
				sprintf(response_header, "HTTP/1.1 200 OK\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:image/*\r\n\r\n", (long unsigned)image_size);
				write(client_fd, response_header, strlen(response_header));

				// send image file
				while (fread(image_line, 1, BUFSIZE, img) != 0)
				{
					write(client_fd, image_line, BUFSIZE);
				}
				fclose(img);
			}
			else if (result == 3) // folder
			{
				FILE * folder;
				folder = fopen(HTML_FILE, "rt");
				char response_html[BUFSIZE*BUFSIZE];
				char html_line[BUFSIZE];

				// make reponse html message
				if (fgets(html_line, BUFSIZE, folder) != NULL)
					strcpy(response_html, html_line);
				while (1)
				{
					if (fgets(html_line, BUFSIZE, folder) != NULL)
						strcat(response_html, html_line);
					else
						break;
				}

				// send response header, html message
				sprintf(response_header, "HTTP/1.1 200 OK\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_html));
				write(client_fd, response_header, strlen(response_header));
				write(client_fd, response_html, strlen(response_html));

				fclose(folder);
			}
			else if (result != -1) // file, text
			{
				FILE * file;
				file = fopen(path, "r");
				int file_size;
				char response_file[BUFSIZE*BUFSIZE];
				char file_line[BUFSIZE];

				fseek(file, 0, SEEK_END);
				file_size = ftell(file); // find file size
				fseek(file, 0, SEEK_SET);

				// send response header message
				sprintf(response_header, "HTTP/1.1 200 OK\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/plain\r\n\r\n", (long unsigned)file_size);
				write(client_fd, response_header, strlen(response_header));

				// send text file or binary file
				while (fread(file_line, 1, BUFSIZE, file) != 0)
				{
					write(client_fd, file_line, BUFSIZE);
				}
				fclose(file);
			}
			else // ERROR
			{
				// make ERROR response message
				sprintf(response_message, "<h1>Not Found</h1><br>The request URL %s was not found on this server<br>HTTP 404 - Not Page Found", input_buf);
				sprintf(response_header, "HTTP/1.1 404 ERROR\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_message));

				// send ERROR response message
				write(client_fd, response_header, strlen(response_header));
				write(client_fd, response_message, strlen(response_message));
			}
		
			// disconnected
			puts("================ Disconnected Client ===============");
			printf("IP : %s\nPort : %d\n", inet_ntoa(inet_client_address), client_addr.sin_port);
			puts("====================================================\n");
			
			close(client_fd);
			return 0;
		}
		else // parent process
		{	
			// store log of connection
			strcpy(input.ip_addr, inet_ntoa(inet_client_address));
			
			num_request++; // number of request + 1

			input.num = 1;
			input.pid = pid;
			input.port = client_addr.sin_port;
			strcpy(input.time, ctime(&t));

			add_client(array, input, num_request); // add information
			
			// store child pid to array
			if (num_request == 1)
			{
				array_pid = (int *)malloc(sizeof(int));
				array_pid[0] = pid;
			}
			else if (num_request > 1)
			{
				array_pid = (int *)realloc(array_pid, sizeof(int)*num_request);
				array_pid[num_request - 1] = pid;
			}
			
			for(int a=wait_num; a<num_request; a++)
			{
				status = 100;
				waitpid(array_pid[a], &status, WNOHANG);
				if(status != 100) // wait.
					wait_num = a+1;
				else
					break;
			}
		}
	}
	
	// free memory allocation, wait child.
	if(num_accessible > 0)
	{
		for(int i=0; i<num_accessible; i++ )
			free(accessible_ip[i]);
		
		free(accessible_ip);
	}
	if(num_request > 0)
	{
		for (int a = 0; a < num_request; a++)
		{
			waitpid(array_pid[a], &status, 0);
		}
		free(array_pid);
	}
	close(socket_fd);
	return 10;	
}
