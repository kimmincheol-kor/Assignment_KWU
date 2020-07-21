// Include Header
#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"
#include <time.h>
#include <windows.h>

// Define Constant
#define TASK_STK_SIZE 512
#define N_TASKS 6
#define N_MSG 100

/* 
=============== Set Variables & Function Prototype ===============
*/

// Massage Queue Variable
OS_EVENT *msg_q[N_TASKS-2];
void *msg_arr[N_TASKS-2][N_MSG];
// Semaphore Variable
OS_EVENT *sem;
// Task Stacks
OS_STK  TaskStk[N_TASKS][TASK_STK_SIZE];
// Seat Variable
int total_used_seat = 0;
short b_seat[N_TASKS-2][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

// Function Prototype
void Manager(void *data);
void Train(void *data);
void Train_2(void *data);
void Train_3(void *data);
void Train_4(void *data);
void Sender(void *data);

/* 
=============== Main Function ===============
*/
int main(void)
{
	// Initialize OS.
    OSInit();

	// Make massage queue.
	INT16U iter=0;
	for(iter=0; iter<4; iter++) // Make 4 Msg Queue
	{
		// create Msg Queue (memory, size)
		msg_q[iter] = OSQCreate(msg_arr[iter], (INT16U)N_MSG);
	
		if(msg_q[iter] == 0) // if Fail to Make Msg Queue
			return -1;
	}
	
	// Make Semaphore
	sem = OSSemCreate(1);
	
	// Create Manager Task (function name, arg, stack address, priority)
	OSTaskCreate(Manager, (void *)0, &TaskStk[0][TASK_STK_SIZE - 1], 5);
	
	// Start OS.
	OSStart();

    return 0;
}

/* 
=============== Function (Task) List ===============
*/
// Manager Task.
void Manager(void *data)
{
	printf("Manager Start.\n");

	// Create Train Task, Sender Task
	OSTaskCreate(Train, (void *)0, &TaskStk[1][TASK_STK_SIZE - 1], 1);
	OSTaskCreate(Train, (void *)0, &TaskStk[2][TASK_STK_SIZE - 1], 2);
	OSTaskCreate(Train, (void *)0, &TaskStk[3][TASK_STK_SIZE - 1], 3);
	OSTaskCreate(Train, (void *)0, &TaskStk[4][TASK_STK_SIZE - 1], 4);

	OSTaskCreate(Sender, (void *)0, &TaskStk[5][TASK_STK_SIZE - 1], 0);
	
	// Variables of Making Input
	int random_seat;
	int train_num;
	
	// Make Random Seed
	srand((unsigned int)time(NULL));
	
	// Operation of Manager
	while(1)
	{
		// Make Random Seat Val. [ 0~39 ]
		random_seat = rand() % 40;
		
		// (random seat)=>(Train num)
		// Seat 0~9 	=> Train 1
		// Seat 10~19 	=> Train 2
		// Seat 20~29 	=> Train 3
		// Seat 30~39 	=> Train 4
	
		// Decide Train Num.
		train_num = random_seat / 10 + 1;
		
		// Transfer to Seat Num Val. [0~9]
		random_seat = random_seat % 10;

		// Switch by Train Num.
		switch(train_num)
		{
			case 1: // Train 1
				OSQPost(msg_q[0], (void *)random_seat); // Post seat number to Msg Queue[0]
				OSTaskResume(1); // Resume Task (Priority 1 = Train 1)
				break;
				
			case 2: // Train 2
				OSQPost(msg_q[1], (void *)random_seat); // Post seat number to Msg Queue[1]
				OSTaskResume(2); // Resume Task (Priority 2 = Train 2)
				break;
				
			case 3: // Train 3
				OSQPost(msg_q[2], (void *)random_seat); // Post seat number to Msg Queue[2]
				OSTaskResume(3); // Resume Task (Priority 3 = Train 3)
				break;
				
			case 4: // Train 4
				OSQPost(msg_q[3], (void *)random_seat); // Post seat number to Msg Queue[3]
				OSTaskResume(4); // Resume Task (Priority 4 = Train 4)
				break;
		}
		
		OSTaskResume(0); // Resume Task (Priority 0 = Sender)
	}
	
	exit(0);
}

// Sender Task
void Sender(void *data)
{
	INT8U err;			// use to Sempend()
	int print_seat;		// use to get Data of Critical Section
	int cnt_locate = 0; // use to Graphic of Train
	
	time_t ct;
	struct tm tm;
	
	// Operation of Sender
	while(1)
	{
		OSTaskSuspend(0); // Suspend by itself
		
		OSSemPend(sem, 0, &err); // GET Semaphore
		print_seat = total_used_seat; // get Data of Critical Section
		OSSemPost(sem); // RETURN Semaphore
		
		////////// PRINT THE SCREEN //////////
		// clear screen
		Sleep(300);
		system("cls");
		
		// Variables of Information of Train Seat
		int n_train;
		int n_seat;
		int cnt_seat[4];
		
		// Print Seat Information of Each Train(1,2,3,4)
		for(n_train=0;n_train<4;n_train++)
		{
			cnt_seat[n_train] = 0; // reset count of seat
			
			printf("      Train Number : %d => ", n_train+1); // Print Train Number.
			for(n_seat=0;n_seat<10;n_seat++) // Check all seat, Count Used Seat.
			{
				if(b_seat[n_train][n_seat] == 0) // if Not Using.
					printf("O ");
				else // if Using.
				{
					printf("X ");
					cnt_seat[n_train]++;
				}
			}
			printf(" => %d / 10\n", cnt_seat[n_train]); // Print Count of Used Seat
		}
		
		// Print Total Number of Used Seat.
		printf("\n         [ The Number of Total Used Seat : %d / 40 ]", total_used_seat);
		
		ct = time(NULL);
		tm = *localtime(&ct);

		printf("\n\n             Current time: %d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		
		printf("\n\n\n\n                => => Send To Station => =>\n\n\n\n");
		
		// Variables of Train Graphic
		char loc_train[62];
		int itr;
		
		/////////// Make Train Location Graphic
		for(itr=0; itr<62; itr++)
			loc_train[itr] = ' ';
		loc_train[61] = '\0';
		
		if(cnt_locate == 55)
			cnt_locate = 0;
		
		loc_train[cnt_locate] = '[';
		loc_train[cnt_locate+1] = 'T';
		loc_train[cnt_locate+2] = 'r';
		loc_train[cnt_locate+3] = 'a';
		loc_train[cnt_locate+4] = 'i';
		loc_train[cnt_locate+5] = 'n';
		loc_train[cnt_locate+6] = ']';
		
		cnt_locate++;
		/////////// end of Making Train Location Graphic
		
		/////////// Print Subway Station Screen Graphic
		printf(" ===============================================================\n");
		printf(" |                                                             |\n");
		printf(" |            This Train For KwangWoon University.             |\n");
		printf(" |                                                             |\n");
		printf(" |  ---------       ---------       ---------       ---------  |\n");
		printf(" ||   %d/10    ==      %d/10      ==    %d/10     ==     %d/10    ||\n", cnt_seat[0], cnt_seat[1], cnt_seat[2], cnt_seat[3]); 
		printf(" |  ---------       ---------       ---------       ---------  |\n");
		printf(" |                                                             |\n");
		printf(" |                                                             |\n");
		printf(" |%s|\n", loc_train);
		printf(" |-----------O-----------------O------------------H------------|\n");
		printf(" |                                                             |\n");
		printf(" ===============================================================\n");
		/////////// end of Print Subway Station Screen Graphic
		
		printf("             Made by 2015722087 Kim Min Cheol\n");
	}
}

// Train Task
void Train(void *data)
{
	void * msg; // use to get Msg From Msg Queue
	
	INT8U err; // use to Sempend
	int num_seat; // use to Massage to Integer
	
	int my_prior = OSTCBCur->OSTCBPrio; // get my priority
	
	OSTaskSuspend(my_prior); // Suspend by itself

	// Operation of Train Task
	while(1)
	{
		// Get Massage From Msg Queue
		msg = OSQAccept(msg_q[my_prior-1]);

		if(msg != 0) // if Get Correct Msg
		{
			num_seat = (int*)msg; // transfer msg to integer
			
			if(b_seat[my_prior-1][num_seat] == 0) // if 0 (not use), change 1 (use)
			{
				b_seat[my_prior-1][num_seat] = 1;
				OSSemPend(sem, 0, &err); // get Semaphore
				total_used_seat++;
				OSSemPost(sem); // return Semaphore
			}
			else // if 1 (use), change 0 (not use)
			{
				b_seat[my_prior-1][num_seat] = 0;
				OSSemPend(sem, 0, &err); // get Semaphore
				total_used_seat--;
				OSSemPost(sem); // return Semaphore
			}
		}
		
		OSTaskSuspend(my_prior); // Suspend by itself
	}
}