//////////////////////////////////////////////////////////////////
// File Name	: Fri_4-1_2015722087.c					//
// Date		: 2018 / 5 / 27					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #4-1 (pre-forked web server)	//
// Description 	: web_server that forked before connect with client.				//
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
char ** accessible_ip; // store ip from accessible.usr
int num_accessible = 0; // number of ip from accessible.usr
int num_request = 0; // number of connection that server with clients
struct client_inf array[10]; // store latest connected client information
int socket_fd; // socket decriptor
int client_fd;
char ROOT_PATH[BUFSIZE] = { 0, };

static int maxNchildren; // max Number of child
static pid_t *child_pids; // store pid of child process

//////////////////////////////////////////////////////////////////
// void add_client								//
// ============================================================	//
//		input : in_array[] -> array that store client information	//			
//				input -> new information of new client	//
//				num -> number of request = number of information in in_array[]	//
//																//
// Purpose : add new information to in_array[]		//
//////////////////////////////////////////////////////////////////
void add_client(struct client_inf in_array[], struct client_inf input, int num)
{
	if(num > 10) // not exist empty slot, delete first,
	{
		for (int i = 0; i < 9; i++) // start checking from last data
		{
			in_array[i] = in_array[i+1];
		}
		in_array[9] = input;
	}
	else // if exist empty slot, input to last slot,
	{
		in_array[num-1] = input;
	}
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
	int repeat; // number of repeat

	if (num > 10) // if num > 10
		repeat = 10; // largest number 10
	else // if num < 10
		repeat = num; // repeat

	// print all of informaion of client in in_array[]
	for (int i = 0; i < repeat ; i++)
	{
		printf("%d	%s	%d	%d	%s", in_array[i].num, in_array[i].ip_addr, in_array[i].pid, in_array[i].port, in_array[i].time);
	}
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
	if (sig == SIGINT) // SIGINT Signal
	{
		return;
	}

	if (sig == SIGUSR1) // User 1 signal
	{
		if (num_request > 0) // if request exist,
		{
			print_client(array, num_request); // print Array.
		}
	}
	
	if (sig == SIGUSR2) // User 2 signal
	{
		// close client before exit.
		if (client_fd > 0)
			close(client_fd);

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
	time_t t;
	char tmp_time[25];
	int status;

	if (sig == SIGINT) // SIGINC signal
	{
		// make time string
		t = time(NULL);
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';

		if (num_accessible > 0) // free accessible_ip array
		{
			for (int i = 0; i < num_accessible; i++)
				free(accessible_ip[i]);

			free(accessible_ip);
		}

		if (maxNchildren > 0)
		{
			for (int a = 0; a < maxNchildren; a++)
			{ // wait for child.
				kill(child_pids[a], SIGUSR2);
				waitpid(child_pids[a], &status, 0);
				printf("\n[%s] %d process is teminated", tmp_time, child_pids[a]); // terminated message
			}
			free(child_pids); // free child_pids
		}

		close(socket_fd);
		printf("\n[%s] Server is terminated\n", tmp_time); // terminated message
		exit(10);
	}

	if (sig == SIGALRM) // Alarm Signal
	{
		alarm(10); // alarm again, ten seconds later.

		// print title of Connection history
		puts("\n================ Connection History ================");
		puts("No.	IP		PID	PORT	TIME");

		for (int i = 0; i < maxNchildren; i++)
			kill(child_pids[i], SIGUSR1); // send signal to child
	}
}

//////////////////////////////////////////////////////////////////
// child_main								//
// ============================================================	//
//														//
// Purpose :	accept connection from client, send response message that response for request message	//
//////////////////////////////////////////////////////////////////
void child_main()
{
	int addrlen;
	struct sockaddr_in client_addr;
	addrlen = sizeof(client_addr);

	struct in_addr tmp_address;
	time_t t;
	char tmp_time[25];

	int flag_access = 0; // check accessible flag

	struct in_addr inet_client_address;
	char buf[BUFSIZE] = { 0, };
	char tmp[BUFSIZE] = { 0, };
	char input_buf[BUFSIZE] = { 0, };
	char method[20] = { 0, };
	char * tok = NULL;

	struct client_inf input; // store new client information

	char response_message[BUFSIZE] = { 0, };
	char response_header[BUFSIZE] = { 0, };
	char path[BUFSIZE] = { 0, };
	int result;

	// ready to get signal
	signal(SIGUSR1, signalHandler_c);
	signal(SIGUSR2, signalHandler_c);
	signal(SIGINT, signalHandler_c);

	while (1) // always on
	{
		// Reset data
		chdir(ROOT_PATH);

		flag_access = 0;
		strcpy(buf, "\0");
		strcpy(tmp, "\0");
		strcpy(input_buf, "\0");
		strcpy(method, "\0");
		tok = NULL;

		strcpy(response_message, "\0");
		strcpy(response_header, "\0");
		strcpy(path, "\0");
		result = -9;
		client_fd = -9;

		// ready to accept.
		client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &addrlen); // wait for connect
		if (client_fd < 0)
		{
			printf("Server: accept failed.\n");
			continue;
		}
		t = time(NULL);

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
		for (int a = 0; a < num_accessible; a++)
		{
			if (strcmp(accessible_ip[a], inet_ntoa(inet_client_address)) == 0 || fnmatch(accessible_ip[a], inet_ntoa(inet_client_address), 0) == 0)
				flag_access = 1;
		}

		if (flag_access == 0) // can't accept
		{
			// make ERROR response message
			sprintf(response_message, "<h1>Access denied</h1><h1>Your IP : %s</h1>You have no permission to access this web server.<br>HTTP 403.6 - Forbidden : IP address reject", inet_ntoa(inet_client_address));
			sprintf(response_header, "HTTP/1.1 404 ERROR\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_message));

			// send ERROR response message
			write(client_fd, response_header, strlen(response_header));
			write(client_fd, response_message, strlen(response_message));

			close(client_fd);
			continue;
		}

		// store log of connection
		num_request++; // number of request + 1
		
		strcpy(input.ip_addr, inet_ntoa(inet_client_address));
		input.num = num_request;
		input.pid = getpid();
		input.port = client_addr.sin_port;
		strcpy(input.time, ctime(&t));

		add_client(array, input, num_request); // add information
		
		// make time string
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';

		// new client
		puts("\n==================== New Client ====================");
		printf("[%s]\nIP : %s\nPort : %d\n", tmp_time, inet_ntoa(inet_client_address), client_addr.sin_port);
		puts("====================================================\n");

		// check path
		strcpy(path, ROOT_PATH); // default : path = ROOT_PATH
		if (strcmp(input_buf, "/") != 0) // not ROOT_PATH,
			strcat(path, input_buf); // path = ROOT_PATH/input

		chdir(ROOT_PATH);
		result = html_ls(path, ROOT_PATH); // execute html_ls
		chdir(ROOT_PATH);

		if (result == -9)
		{
			close(client_fd);
			continue;
		}

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

		// make time string
		t = time(NULL);
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';

		// disconnected
		puts("================ Disconnected Client ===============");
		printf("[%s]\nIP : %s\nPort : %d\n", tmp_time, inet_ntoa(inet_client_address), client_addr.sin_port);
		puts("====================================================\n");

		close(client_fd);
	}
	return;
}

//////////////////////////////////////////////////////////////////
// child_make								//
// ============================================================	//
//			output : pid_t pid -> pid of child
//														//
// Purpose :	make child, parent->return pid, child->child_main()	//
//////////////////////////////////////////////////////////////////
pid_t child_make()
{
	pid_t pid;

	// make time string
	time_t t;
	char tmp_time[25];
	t = time(NULL);

	if ((pid = fork()) > 0) // parent,
	{
		// make time string
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';

		printf("[%s] %d process is forked.\n", tmp_time, pid);
		return pid;
	}

	// child,
	child_main();
}

//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
//														//
// Purpose :	make socket, make 5 child, and manage.	//
//////////////////////////////////////////////////////////////////
void main()
{
	struct sockaddr_in server_addr;
	int opt = 1;

	time_t t;
	char tmp_time[25];
	t = time(NULL);

	// make time string
	strcpy(tmp_time, ctime(&t));
	tmp_time[24] = '\0';

	printf("[%s] Server is started.\n", tmp_time);

	FILE * accessible;	// accessible.usr file
	char line_ip[16]; // line of file

	// store accessible ip
	accessible = fopen("accessible.usr", "r"); // file open.
	if (accessible == NULL)
	{
		puts("file error");
		return;
	}

	while (1)
	{
		if (feof(accessible) != 0) // if end of file, break.
			break;

		fgets(line_ip, sizeof(char) * 16, accessible); // get line

		// dynamic allocation
		if (num_accessible == 0) // first line
			accessible_ip = (char**)malloc(sizeof(char*));
		else // not first line
			accessible_ip = (char**)realloc(accessible_ip, sizeof(char*) * num_accessible + 1);

		accessible_ip[num_accessible] = (char*)malloc(sizeof(char) * (16));

		// add to accessible_ip array.
		strcpy(accessible_ip[num_accessible], line_ip);

		for (int i = 0; i < 16; i++)
		{ // '\r\n' -> '\0'
			if (accessible_ip[num_accessible][i] == '\r' || accessible_ip[num_accessible][i] == '\n')
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
		return;
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
		return;
	}

	// ready to accept connection, queue size = 5
	listen(socket_fd, 5);

	maxNchildren = 5;
	child_pids = (pid_t *)malloc(maxNchildren * sizeof(pid_t));

	alarm(10);

	// make 5 child,
	for (int i = 0; i < maxNchildren; i++)
		child_pids[i] = child_make();

	// siganl handle
	signal(SIGALRM, signalHandler_p);
	signal(SIGINT, signalHandler_p);

	// pause.
	for (; ; )
		pause();
}