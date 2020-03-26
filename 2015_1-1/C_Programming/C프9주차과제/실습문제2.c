/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>


int setID() // setID 함수
{
	int id;
	printf("학번 입력 : ");
	scanf("%d", &id); //id값 입력
	return id; //id값 반환
}

void printfTimeTable(int mID)
{
	printf("\n============ 시간표 (학번 : %d) ============\n", mID);
	printf("\t%-20s%-12s%-12s\n", "교과목명", "강의시간", "강의실");
	printf("====================================================\n");
	printf("\t%-20s%-12s%-12s\n", "C프로그래밍", "월6수5", "연401");
	printf("\t%-20s%-12s%-12s\n", "시스템프로그래밍", "월12", "비514");
	printf("\n");

}


int main()
{
	int id=0, sel=0;
	printf("1. 학번 입력\n");
	printf("2. 시간표 확인\n");
	printf("3. 종료\n");

	while(1) // 무한루프
	{
		printf(">> select : ");
		scanf("%d", &sel);
		switch(sel)
		{
        case 1:
			id=setID(); // id값을 setID에서 반환한 값으로 대입
			continue;

		case 2:
			if(id==0){
				printf("학번을 먼저 입력하세요\n");
			continue;} // 학번이 입력되지않았으므로 학번먼저 입력

			printfTimeTable(id); // mID 에 id 대입

		case 3:
			break; //스위치문 탈출
		
		default:
			continue; // 다른값들은 다시 입력

		}

		if(sel==3)
			break; // sel이 3일때 while 문 탈출
	}

	return 0;
}