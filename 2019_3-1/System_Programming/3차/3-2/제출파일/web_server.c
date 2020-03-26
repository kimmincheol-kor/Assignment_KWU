//////////////////////////////////////////////////////////////////
// File Name	: web_server.c					//
// Date		: 2018 / 5 / 9					//
// Authuor	: Kim Min Cheol					//
// Student ID	: 2015722087					//
// -------------------------------------------------------	//
// Title : System Programming Assignment #3-2 (basic web server)	//
// Description 	: web server that use html_ls, send result to browser client				//
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
#include "html_ls.h"

#define URL_LEN 256
#define BUFSIZE 1024
#define PORTNO   40302


//////////////////////////////////////////////////////////////////
// main								//
// ============================================================	//
// 		//
// 										//
// 																//
//																//
// Purpose :	accept connection from client, send response message that response for request message	//
//////////////////////////////////////////////////////////////////
int main()
{
	struct sockaddr_in server_addr, client_addr;
	int socket_fd, client_fd;
	int len, len_out;
	int opt = 1;
	pid_t pid;
	int status;
	char ROOT_PATH[BUFSIZE] = {0, };
	
	getcwd(ROOT_PATH, BUFSIZE);

	if ((socket_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Server: Can't open stream socket.");
		return 0;
	}

	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORTNO);

	if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("server: can't bind local address.\n");
		return 0;
	}
	listen(socket_fd, 5);

	while (1) // always on
	{
		chdir(ROOT_PATH);
		len = sizeof(client_addr);
		client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &len); // wait for connect
		if (client_fd < 0)
		{
			printf("Server: accept failed.\n");
			return 0;
		}
		
		pid = fork(); // fork.
		if (pid < 0) // error
		{
			close(client_fd);
			return -1;
		}
		else if (pid == 0) // child process
		{
			struct in_addr inet_client_address;
			char buf[BUFSIZE] = {0, };
			char tmp[BUFSIZE] = {0, };
			char response_message[BUFSIZE] = {0, };
			char response_header[BUFSIZE] = {0, };
			char input[BUFSIZE] = {0, };
			char path[BUFSIZE] = {0, };
			char method[20] = {0, };
			char * tok =NULL;
			int result;
			
			inet_client_address.s_addr = client_addr.sin_addr.s_addr;
			read(client_fd, buf, BUFSIZE);
			strcpy(tmp,buf);
			
			tok = strtok(tmp," ");
			strcpy(method, tok);
			if(strcmp(method, "GET")==0)
			{
				tok = strtok(NULL, " ");
				if(strcmp(tok, "/favicon.ico")==0 || strcmp(tok, "/E")==0) // ignore /favicon.ico
				{
					close(client_fd);
					return 0;
				}
				else if(strcmp(tok, "/$EXIT")==0)
				{
					close(client_fd);
					return 10;
				}
				strcpy(input, tok);
			}
			else // not GET request
			{
				close(client_fd);
				return 0;
			}
			
			printf("[%s : %d] client was connected.\n", inet_ntoa(inet_client_address), client_addr.sin_port);
			puts("=============================================\n\n");
			printf("Request from [%s : %d]\n", inet_ntoa(inet_client_address), client_addr.sin_port);
			puts(buf);
			puts("=============================================");
			
			strcpy(path, ROOT_PATH); // default : path = ROOT_PATH
			if(strcmp(input, "/") != 0) // not ROOT_PATH,
				strcat(path, input); // path = ROOT_PATH/input
			
			chdir(ROOT_PATH);
			result = html_ls(path, ROOT_PATH); // execute html_ls
			chdir(ROOT_PATH);

			if( ( (fnmatch("*.jpg",input+1,FNM_CASEFOLD)==0) || (fnmatch("*.PNG",input+1,FNM_CASEFOLD)==0) || (fnmatch("*.jpeg",input+1,FNM_CASEFOLD)==0) ) && result==1 ) // image
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
				while(fread(image_line,1, BUFSIZE, img) != 0)
				{
					write(client_fd, image_line, BUFSIZE);
				}
				fclose(img);
			}
			else if(result == 3) // folder
			{
				FILE * folder;
				folder = fopen(HTML_FILE, "rt");
				char response_html[BUFSIZE*BUFSIZE];
				char html_line[BUFSIZE];
				
				// make reponse html message
				if(fgets(html_line, BUFSIZE, folder) != NULL)
						strcpy(response_html, html_line);
				while(1)
				{
					if(fgets(html_line, BUFSIZE, folder) != NULL)
						strcat(response_html, html_line);
					else
						break;
				}
				//printf("%s", response_html);
				// send response header, html message
				sprintf(response_header, "HTTP/1.1 200 OK\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_html));
				write(client_fd, response_header, strlen(response_header));
				write(client_fd, response_html, strlen(response_html));
				
				fclose(folder);
			}
			else if(result != -1) // file
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
				while(fread(file_line,1, BUFSIZE, file) != 0)
				{
					write(client_fd, file_line, BUFSIZE);
				}
				fclose(file);
			}
			else // ERROR
			{
				// make ERROR response message
				sprintf(response_message, "<h1>Not Found</h1><br>The request URL %s was not found on this server<br>HTTP 404 - Not Page Found", input);
				sprintf(response_header, "HTTP/1.1 404 ERROR\r\nServer:2019 web server\r\nContent-length:%lu\r\nContent-type:text/html\r\n\r\n", strlen(response_message));
				
				// send ERROR response message
				write(client_fd, response_header, strlen(response_header));
				write(client_fd, response_message, strlen(response_message));
			}
			printf("[%s : %d] client was disconnected.\n\n", inet_ntoa(inet_client_address), client_addr.sin_port);
			close(client_fd);
			return 0;
		}
		else // parent process
		{
			wait(&status);
			close(client_fd);
			if(status == 2560)
				break;
		}
	}
	close(socket_fd);
	return 0;
}