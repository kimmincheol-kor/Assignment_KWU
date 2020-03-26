//////////////////////////////////////////////////////////////////
// File Name	: Fri_4-3_2015722087.c					//
// Date		: 2018 / 6 / 10					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #4-3 (Log file and Semaphore)	//
// Description 	: Write Management Process and information of connection to Log file.				//
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

#include<sys/shm.h>
#include<sys/ipc.h>
#include<pthread.h>

#include<fcntl.h>
#include<semaphore.h>

#include <sys/time.h>

#define URL_LEN 256
#define BUFSIZE 1024
#define PORTNO   40302

// set pthread_mutex_t value.
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

// information struct of connection.
struct client_inf {
	int num; // connection number
	char ip_addr[16]; // ip address
	int pid; // process id for client
	int port; // port for client
	char time[25]; // ctime of time that connected
};

// sharing data struct.
typedef struct Shm_Data {
	int num_request; // number of connection that server with clients
	int CurIdleNum; // number of idle process(child)
	int CurBusyNum; // number of busy process(child)
	int CurTotalNum; // number of child process
	struct client_inf history[100]; // history struct array.
}SH_DATA;

// global variables
char ** accessible_ip; // store ip from accessible.usr
int num_accessible = 0; // number of ip from accessible.usr

struct client_inf array[10]; // store latest connected client information
int socket_fd; // socket decriptor
int client_fd;
char ROOT_PATH[BUFSIZE] = { 0, };

static int MaxChilds=0; // max Number of child
static int MaxIdleNum=0; // max Number of Idel
static int MinIdleNum=0; // min Number of Idel
static int StartProcess=0; // Number of process that made when server started
static int MaxHistory=0; // max Number of History

static pid_t *child_pids; // store pid of child process

int flag_find_idle=0;

SH_DATA *sh = NULL;

struct client_inf input; // store new client information

char tmp_time[25];

pid_t parent_pid;

pid_t child_make();

FILE * LOG_FILE;
const char * LOG = "server_log.txt";
sem_t *mysem;

char log_string[1024];
char tmp_string[1024];


//////////////////////////////////////////////////////////////////
// void log_write							//
// ============================================================	//
//			input : arg -> string that write to Log				//
//																//
// Purpose : write to Log file.				//
//////////////////////////////////////////////////////////////////
void log_write(void * arg)
{
	mysem = sem_open("mysem", O_RDWR);
	sem_wait(mysem);

	LOG_FILE = fopen(LOG, "a");
	
	fprintf(LOG_FILE, "%s", (char *)arg);
	
	fclose(LOG_FILE);
	
	sem_post(mysem);
	sem_close(mysem);
	
	return;
}

//////////////////////////////////////////////////////////////////
// void check_idle								//
// ============================================================	//
//																//
// Purpose : check Current IDLE Process Number	//
//////////////////////////////////////////////////////////////////
void check_idle(void * arg)
{
	pthread_mutex_lock(&counter_mutex);
	/////////////////////////////////////////////////////

	if(sh->CurTotalNum > MaxChilds) // check MaxChild
		kill(child_pids[flag_find_idle], SIGUSR2);
	else
	{
		if(sh->CurIdleNum > MaxIdleNum) // check MaxIdleNum
			kill(child_pids[flag_find_idle], SIGUSR2);
		if(sh->CurIdleNum < MinIdleNum) // check MinIdleNum
		{
			sh->CurIdleNum++;
			sh->CurTotalNum++;
			pthread_mutex_unlock(&counter_mutex);
			child_pids[sh->CurTotalNum-1] = child_make(); // fork
			return;
		}
	}
	
	//////////////////////////////////////////////////////////////
	pthread_mutex_unlock(&counter_mutex);
	
	return;
}

//////////////////////////////////////////////////////////////////
// void disconnect_client								//
// ============================================================	//
//																//
// Purpose : disconnect with client		//
//////////////////////////////////////////////////////////////////
void disconnect_client(void * arg)
{
	pthread_mutex_lock(&counter_mutex);
	//////////////////////////////////////////////////////////////
	
	// busy -> idle
	sh->CurIdleNum++;
	sh->CurBusyNum--;
	
	////////////////////////////////////////////////////////////////
	pthread_mutex_unlock(&counter_mutex);
	
	kill(getppid(), 30);
	
	return;
}

//////////////////////////////////////////////////////////////////
// void connect_client								//
// ============================================================	//
//																//
// Purpose : connect with client		//
//////////////////////////////////////////////////////////////////
void connect_client(void * arg)
{
	pthread_mutex_lock(&counter_mutex);
	//////////////////////////////////////////////////////
	
	// idle -> busy
	sh->CurIdleNum--;
	sh->CurBusyNum++;
	sh->num_request++; // number of request + 1
	
	input.num = sh->num_request;
	
	// input new history to sharing memory.
	if(sh->num_request > MaxHistory) // not exist empty slot, delete first,
	{
		for (int i = 0; i < MaxHistory-1; i++) // start checking from last data
		{
			sh->history[i] = sh->history[i+1];
		}
		sh->history[MaxHistory-1] = input;
	}
	else // if exist empty slot, input to last slot,
	{
		sh->history[sh->num_request-1] = input;
	}
	
	//////////////////////////////////////////////////////////
	pthread_mutex_unlock(&counter_mutex);
	
	kill(getppid(), 30); // send signal 30 to parent
	
	return;
}

//////////////////////////////////////////////////////////////////
// void print_client								//
// ============================================================	//
//																//
// Purpose : print informations of in_array[]		//
//////////////////////////////////////////////////////////////////
void print_client(void * arg)
{
	int repeat; // number of repeat
	pthread_t tid;

	if (sh->num_request > MaxHistory) // if num > 10
		repeat = MaxHistory; // largest number 10
	else // if num < 10
		repeat = sh->num_request; // repeat
		
	// print title of Connection history
	puts("\r\n================ Connection History ================");
	puts("No.	IP		PID	PORT	TIME");
	
	sprintf(log_string, "\r\n================ Connection History ================\r\n");
	sprintf(tmp_string, "No.	IP		PID	PORT	TIME\r\n");
	strcat(log_string, tmp_string);

	//mysem = sem_open("mysem", 2);
	// print all of informaion of client in in_array[]
	for (int i = repeat-1; i >= 0; i--)
	{
		if(sh->history[i].num <= sh->num_request && sh->history[i].num > 0)
		{
			printf("%d	%s	%d	%d	%s", sh->history[i].num, sh->history[i].ip_addr, sh->history[i].pid, sh->history[i].port, sh->history[i].time);
			sprintf(tmp_string, "%d	%s	%d	%d	%s\r\n", sh->history[i].num, sh->history[i].ip_addr, sh->history[i].pid, sh->history[i].port, sh->history[i].time);
			strcat(log_string, tmp_string);
		}
	}
	
	sprintf(tmp_string, "====================================================\r\n");
	strcat(log_string, tmp_string);
	
	pthread_create(&tid, NULL, (void *)log_write, log_string);
	pthread_join(tid, NULL);

	return;
}

//////////////////////////////////////////////////////////////////
// void reduce_idle								//
// ============================================================	//
//																//
// Purpose : reduce idle process.		//
//////////////////////////////////////////////////////////////////
void reduce_idle(void * arg)
{
	pthread_t tid;
	pid_t tmp_pid;
	int status;
	
	tmp_pid = waitpid(-1, &status, 0); // wait for any child process
	for(int i=0; i < sh->CurTotalNum; i++)
	{
		if(child_pids[i] == tmp_pid && tmp_pid != 0) // find dead child in pid array
		{
			child_pids[i] = 0; // reset
			
			while(child_pids[i+1] != 0) // move forward in array
			{
				child_pids[i] = child_pids[i+1];
				i++;
			}
			
			printf("\r\n[%s] %d process is teminated\r\n", tmp_time, tmp_pid); // terminated message
			sprintf(log_string, "\r\n[%s] %d process is teminated\r\n", tmp_time, tmp_pid);
			
			
			// reduce number
			sh->CurIdleNum--;
			sh->CurTotalNum--;
			
			printf("[%s] idleProcessCount : %d", tmp_time, sh->CurIdleNum);
			printf("\r\n");
			
			sprintf(tmp_string, "[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
			strcat(log_string, tmp_string);
			
			pthread_create(&tid, NULL, (void *)log_write, log_string);
			pthread_join(tid, NULL);
			
			flag_find_idle = 0;
				
			break;
		}
	}

	return;
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
	pthread_t tid;
	
	if (sig == 29) // 29 Signal
	{
		// close client before exit.
		if (client_fd > 0)
		{
			close(client_fd);
		}

		exit(0);
	}

	if(sig == SIGUSR2) // User2 Signal : find idle -> kill
	{
		if (client_fd < 0) // Idle
		{
			kill(getppid(), SIGUSR1);
			exit(0);
		}
		else // busy
			kill(getppid(), SIGUSR2);
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
	// make time string
	t = time(NULL);
	strcpy(tmp_time, ctime(&t));
	tmp_time[24] = '\0';
		
	int status;
	int shm_id;

	pid_t tmp_pid;
	
	pthread_t tid;
	
	if (getpid() == parent_pid) // parent only
	{
		if (sig == SIGINT) // SIGINT signal
		{
			if (num_accessible > 0) // free accessible_ip array
			{
				for (int i = 0; i < num_accessible; i++)
					free(accessible_ip[i]);

				free(accessible_ip);
			}

			if (sh->CurTotalNum > 0) // kill child
			{
				for (int a = 0; a < sh->CurTotalNum; a++)
				{ // wait for child.
					kill(child_pids[a], 29);
					waitpid(child_pids[a], &status, 0);
					printf("\r\n[%s] %d process is teminated", tmp_time, child_pids[a]); // terminated message
					printf("\r\n[%s] TotalProcessCount : %d", tmp_time, sh->CurTotalNum-1-a);
					
					sprintf(log_string, "\r\n[%s] %d process is teminated", tmp_time, child_pids[a]); // terminated message
					sprintf(tmp_string, "\r\n[%s] TotalProcessCount : %d", tmp_time, sh->CurTotalNum-1-a);
					strcat(log_string, tmp_string);
					
					pthread_create(&tid, NULL, (void *)log_write, log_string);
					pthread_join(tid, NULL);
					
				}
				free(child_pids); // free child_pids
			}
			// delete sharing memory
			shm_id = shmget((key_t)40302, sizeof(SH_DATA), 0666|IPC_CREAT);
			shmctl(shm_id, IPC_RMID, 0);

			close(socket_fd);

			printf("\r\n[%s] Server is terminated\r\n", tmp_time); // terminated message
			
			sprintf(log_string, "\r\n[%s] Server is terminated\r\n", tmp_time);
			pthread_create(&tid, NULL, (void *)log_write, log_string);
			pthread_join(tid, NULL);
			
			exit(10);
		}

		if (sig == SIGALRM) // Alarm Signal
		{
			alarm(10); // alarm again, ten seconds later.
			
			if (sh->num_request > 0) // if request exist,
			{
				// use thread that print_client()
				pthread_create(&tid, NULL, (void *)print_client, NULL);
				pthread_join(tid, NULL);
			}
		}
		
		if (sig == SIGUSR1) // Child signal : im idle
		{
			// kill
			pthread_create(&tid, NULL, (void *)reduce_idle, NULL);
			pthread_join(tid, NULL);
		}
		
		if (sig == SIGUSR2) // Child signal : im busy
		{
			// check next child
			flag_find_idle++;
			kill(child_pids[flag_find_idle], SIGUSR2);
		}
		
		if( sig == 30 ) // check idle
		{
			// if CurIdleNum changed, do check_idle().
			pthread_create(&tid, NULL, (void *)check_idle, NULL);
			pthread_join(tid, NULL);
		}
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

	int flag_access = 0; // check accessible flag

	struct in_addr inet_client_address;
	char buf[BUFSIZE] = { 0, };
	char tmp[BUFSIZE] = { 0, };
	char input_buf[BUFSIZE] = { 0, };
	char method[20] = { 0, };
	char url[256] = { 0, };
	char * tok = NULL;

	char response_message[BUFSIZE] = { 0, };
	char response_header[BUFSIZE] = { 0, };
	char path[BUFSIZE] = { 0, };
	int result;
	
	int shm_id;
	void * shared_memory;
	
	pthread_t tid;
	
	struct timeval tp_start, tp_end;
	
	// ready to get signal
	signal(SIGUSR1, signalHandler_c);
	signal(SIGUSR2, signalHandler_c);
	signal(29, signalHandler_c);

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
			printf("Server: accept failed.\r\n");
			continue;
		}
		gettimeofday(&tp_start, NULL);
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

			strcpy(url, tok);
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
			sprintf(response_header, "HTTP/1.1 404 ERROR\r\r\nServer:2019 web server\r\r\nContent-length:%lu\r\r\nContent-type:text/html\r\r\n\r\r\n", strlen(response_message));

			// send ERROR response message
			write(client_fd, response_header, strlen(response_header));
			write(client_fd, response_message, strlen(response_message));

			close(client_fd);
			continue;
		}
		
		// Access sharing memory
		shm_id = shmget((key_t)40302, sizeof(SH_DATA), 0666|IPC_CREAT);
		if(shm_id == -1) // error
			return;
		shared_memory = shmat(shm_id, (void*)0, 0666|IPC_CREAT);
		sh = (SH_DATA *)shared_memory;

		// make history struct of connection
		strcpy(input.ip_addr, inet_ntoa(inet_client_address));
		input.num = 0;
		input.pid = getpid();
		input.port = client_addr.sin_port;
		strcpy(input.time, ctime(&t));
		
		// make time string
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';
		
		// create thread that doing connect_client().
		pthread_create(&tid, NULL, (void *)connect_client, NULL);
		pthread_join(tid, NULL);

		// new client
		puts("\r\n==================== New Client ====================");
		printf("TIME : %s\r\n", tmp_time);
		printf("URL : %s\r\n", url);
		printf("IP : %s\r\n", inet_ntoa(inet_client_address));
		printf("Port : %d\r\n", client_addr.sin_port);
		printf("PID : %d\r\n", getpid());
		puts("====================================================\r\n");
		
		printf("[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		
		/////////////  Make LOG String  ///////////////////
		sprintf(log_string, "\r\n==================== New Client ====================\r\n");
		sprintf(tmp_string, "TIME : %s\r\n", tmp_time);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "URL : %s\r\n", url);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "IP : %s\r\n", inet_ntoa(inet_client_address));
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "Port : %d\r\n", client_addr.sin_port);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "PID : %d\r\n", getpid());
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "====================================================\r\n\r\n");
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		strcat(log_string, tmp_string);
		
		pthread_create(&tid, NULL, (void *)log_write, log_string);
		pthread_join(tid, NULL);
		/////////////  End of Logging  ///////////////////

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
			sprintf(response_header, "HTTP/1.1 200 OK\r\r\nServer:2019 web server\r\r\nContent-length:%lu\r\r\nContent-type:image/*\r\r\n\r\r\n", (long unsigned)image_size);
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
			sprintf(response_header, "HTTP/1.1 200 OK\r\r\nServer:2019 web server\r\r\nContent-length:%lu\r\r\nContent-type:text/html\r\r\n\r\r\n", strlen(response_html));
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
			sprintf(response_header, "HTTP/1.1 200 OK\r\r\nServer:2019 web server\r\r\nContent-length:%lu\r\r\nContent-type:text/plain\r\r\n\r\r\n", (long unsigned)file_size);
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
			sprintf(response_header, "HTTP/1.1 404 ERROR\r\r\nServer:2019 web server\r\r\nContent-length:%lu\r\r\nContent-type:text/html\r\r\n\r\r\n", strlen(response_message));

			// send ERROR response message
			write(client_fd, response_header, strlen(response_header));
			write(client_fd, response_message, strlen(response_message));
		}
		
		gettimeofday(&tp_end, NULL);
		sleep(5);
		
		// make time string
		t = time(NULL);
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';
		
		// create thread that doing disconnect_client().
		pthread_create(&tid, NULL, (void *)disconnect_client, NULL);
		pthread_join(tid, NULL);
		
		// disconnected
		puts("\r\n================ Disconnected Client ===============");
		printf("TIME : %s\r\n", tmp_time);
		printf("URL : %s\r\n", url);
		printf("IP : %s\r\n", inet_ntoa(inet_client_address));
		printf("Port : %d\r\n", client_addr.sin_port);
		printf("PID : %d\r\n", getpid());
		printf("CONNECTING TIME : %d(us)\r\n", (int)(tp_end.tv_usec - tp_start.tv_usec));
		puts("====================================================\r\n");
		
		printf("[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		
		/////////////  Make LOG String  ///////////////////
		sprintf(log_string, "\r\n================ Disconnected Client ===============\r\n");
		sprintf(tmp_string, "TIME : %s\r\n", tmp_time);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "URL : %s\r\n", url);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "IP : %s\r\n", inet_ntoa(inet_client_address));
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "Port : %d\r\n", client_addr.sin_port);
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "PID : %d\r\n", getpid());
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "CONNECTING TIME : %d(us)\r\n", (int)(tp_end.tv_usec - tp_start.tv_usec));
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "====================================================\r\n\r\n");
		strcat(log_string, tmp_string);
		sprintf(tmp_string, "[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		strcat(log_string, tmp_string);
		
		pthread_create(&tid, NULL, (void *)log_write, log_string);
		pthread_join(tid, NULL);
		/////////////// End of Logging ////////////////////
		
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
	pthread_t tid;

	// make time string
	time_t t;
	t = time(NULL);

	if ((pid = fork()) > 0) // parent,
	{
		// make time string
		strcpy(tmp_time, ctime(&t));
		tmp_time[24] = '\0';

		printf("[%s] %d process is forked.\r\n", tmp_time, pid);
		printf("[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		
		sprintf(log_string, "[%s] %d process is forked.\r\n", tmp_time, pid);
		sprintf(tmp_string, "[%s] idleProcessCount : %d\r\n", tmp_time, sh->CurIdleNum);
		strcat(log_string, tmp_string);
		
		pthread_create(&tid, NULL, (void *)log_write, log_string);
		pthread_join(tid, NULL);
		
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
	LOG_FILE = fopen(LOG, "w"); // file open to write
	
	parent_pid = getpid();

	time_t t;
	t = time(NULL);

	// make time string
	strcpy(tmp_time, ctime(&t));
	tmp_time[24] = '\0';

	printf("[%s] Server is started.\r\n", tmp_time);
	fprintf(LOG_FILE, "[%s] Server is started.\r\n", tmp_time);
	fclose(LOG_FILE);

	FILE * accessible;	// accessible.usr file
	FILE * httpd;
	char file_line[16]; // line of file
	char * httpd_value;
	
	int shm_id;
	void *shared_memory = (void*)0;
	
	pthread_t tid_t;

	// store accessible ip
	accessible = fopen("accessible.usr", "r"); // file open.
	if (accessible == NULL)
	{
		puts("accessible error");
		return;
	}
	while (1)
	{
		if (feof(accessible) != 0) // if end of file, break.
			break;

		fgets(file_line, sizeof(char) * 16, accessible); // get line

		// dynamic allocation
		if (num_accessible == 0) // first line
			accessible_ip = (char**)malloc(sizeof(char*));
		else // not first line
			accessible_ip = (char**)realloc(accessible_ip, sizeof(char*) * num_accessible + 1);

		accessible_ip[num_accessible] = (char*)malloc(sizeof(char) * (16));

		// add to accessible_ip array.
		strcpy(accessible_ip[num_accessible], file_line);

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
	// end of store accessible ip
	
	// get httpd.conf data
	httpd = fopen("httpd.conf", "r"); // file open.
	if (httpd == NULL)
	{
		puts("httpd error");
		return;
	}
	while (1)
	{
		if (feof(httpd) != 0) // if end of file, break.
			break;

		fgets(file_line, sizeof(char) * 16, httpd); // get line
		
		for (int i = 0; i < 16; i++) // '\r\n' -> '\0'
		{
			if (file_line[i] == '\r' || file_line[i] == '\n')
			{
				file_line[i] = '\0';
				break;
			}
		}
		
		// Find value of httpd.conf
		if(strncmp(file_line, "MaxChilds", 9) == 0)
		{
			httpd_value = &file_line[11];
			MaxChilds = atoi(httpd_value);
		}
		else if(strncmp(file_line, "MaxIdleNum", 10) == 0)
		{
			httpd_value = &file_line[12];
			MaxIdleNum = atoi(httpd_value);
		}
		else if(strncmp(file_line, "MinIdleNum", 10) == 0)
		{
			httpd_value = &file_line[12];
			MinIdleNum = atoi(httpd_value);
		}
		else if(strncmp(file_line, "StartServers", 12) == 0)
		{
			httpd_value = &file_line[14];
			StartProcess = atoi(httpd_value);
		}
		else if(strncmp(file_line, "MaxHistory", 10) == 0)
		{
			httpd_value = &file_line[12];
			MaxHistory = atoi(httpd_value);
		}
	}
	fclose(httpd); // close file
	// end of get httpd.conf data
	
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
		printf("server: can't bind local address.\r\n");
		return;
	}

	// ready to accept connection, queue size = 5
	listen(socket_fd, 5);
	
	// Access Sharing Memory
	shm_id = shmget((key_t)40302, sizeof(SH_DATA), 0666|IPC_CREAT);
	if(shm_id == -1) // error
		return;
	shared_memory = shmat(shm_id, (void*)0, 0);
	sh = (SH_DATA *)shared_memory;
	
	// set semaphore
	mysem = sem_open("mysem", O_CREAT | O_EXCL, 0700, 1);
	sem_close(mysem);
	
	// reset data of sharing memonry
	sh->num_request = 0;
	sh->CurBusyNum = 0;
	sh->CurIdleNum = 0;
	sh->CurTotalNum = 0;

	alarm(10);
	signal(SIGPIPE, SIG_IGN);

	// Allocation that size = MaxChilds
	child_pids = (pid_t *)malloc(MaxChilds * sizeof(pid_t));
	
	// Make child
	for (int i = 0; i < StartProcess; i++)
	{
		// new child -> Idle ++, Total ++
		sh->CurIdleNum++;
		sh->CurTotalNum++;
		child_pids[i] = child_make();
	}
	
	
	for(int j = StartProcess ; j < MaxChilds; j++)
		child_pids[j] = 0;

	// siganl handle
	signal(SIGUSR1, signalHandler_p);
	signal(SIGUSR2, signalHandler_p);
	signal(30, signalHandler_p);
	signal(SIGALRM, signalHandler_p);
	signal(SIGINT, signalHandler_p);
	
	// pause.
	for (; ; )
		pause();
}