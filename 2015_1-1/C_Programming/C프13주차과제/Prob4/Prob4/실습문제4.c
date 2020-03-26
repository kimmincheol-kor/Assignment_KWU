// C 프로그래밍 13주차 실습문제

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void check(int *ran, int *ans); // check 함수 선언

int main()
{
	int i=3, j=0, k=0;
	int rannum[5]={0}; // 랜덤넘버 배열
	int answer[5]={0}; // 정답 배열


	srand((unsigned)time(NULL)); // 랜덤숫자 고름

	for(i=3; i>0; i--) // 시작 안내문구
	{
		printf("%d초 후 시작", i);
		Sleep(1000);
		system("cls");
	}

	for(j=0; j<5; j++)// 랜덤넘버 5개 뽑아서 rannum 배열에 저장.
	{
		rannum[j]=rand()%100+1;
	}
	
	for(j=0; j<5; j++) // 숫자 보여주기
	{
		printf(">> %d", rannum[j]);
		Sleep(1000);
		system("cls");
	}

	printf("정수 5개 순서대로 입력\n");

	check(rannum, answer);// 정답비교함수

	return 0;
}

void check(int *ran, int *ans) // 배열을 받음
{
	int a=0, sum=0;
	
	for(a=0; a<5; a++)
	{
		printf("입력: ");
		scanf("%d", &ans[a]); // 정답을 입력
		
		if(ran[a]==ans[a])
			sum+=1; // 맞췄으면 sum 값에 1을 더해줌
		else{ // 틀렸으면 틀렸다고안내 후 정답 안내
			printf("틀렸습니다\n정답: %d %d %d %d %d\n", ran[0], ran[1], ran[2], ran[3], ran[4]);
			break;
			}

	}

	if(sum==5) // 모두 정답이어서 sum값이 5가 되었으면 정답이라고 안내
		printf("모두 정답입니다\n");
}