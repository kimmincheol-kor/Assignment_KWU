// C 프로그래밍 14주차 실습문제3

#include <stdio.h>

int main()
{
	char mvTitle[5][20]={0};
	char title[20]={0}; // 임시로 크기가 20인 배열 선언
	int mvScore[5]={0};
	int menu, i,j,k;

	printf("\n");
	printf("=============================\n");
	printf(">> 1. 영화 평점 등록\n");
	printf(">> 2. 목록 보기\n");
	printf(">> 3. 종료\n");
	printf("=============================\n");

	while(1)
	{
		printf(">> select: ");
		scanf("%d", &menu);
		getchar(); // 버퍼에 엔터가 남아있기때문에 getchar로 가져옴

		switch(menu)
		{
			case 1:
				if(mvTitle[4][0]!=0) // 5번째에 영화제목이 입력되었다면 더이상 추가 X
				{
					printf("더 이상 추가할 수 없습니다<최대 5개>\n"); // 예외처리 3
					break;
				}
				else
				{
				for(i=0; i<5; i++)
					{
						if(mvTitle[i][0]==0){ // 아직 입력되지 않았다면 실행
							printf("제목: ");
							for(k=0; k<20; k++)
							{
								title[k]=0; // title에 입력된 값없애기
							}
							gets(title); // title을 입력받음
							for(k=0; k<20; k++)
							{
								mvTitle[i][k]=title[k]; // title을 mvTitle로 복사
							}
							printf("평점<1~5>: ");
							scanf("%d", &mvScore[i]); // 평점 입력, 제목과 같은 순서에
							if(mvScore[i]>5){ // 예외처리2 평점이 5점을 넘으면 평점 재입력
								printf("평점<1~5>: ");
								scanf("%d", &mvScore[i]);}
							break;}
					}
					break;
				}
				
			case 2:
				printf("\n");
				printf("-----------------------------------\n");
				printf(" [영화]               [평점]\n");
				for(j=0; j<5; j++)
				{
					if(mvTitle[j][0]!=0){
					printf(" ");
					for(k=0; k<20; k++)
					{
						printf("%c", mvTitle[j][k]); // 영화 제목 출력
					}
					for(i=0; i<mvScore[j]; i++)
					{
						printf("■"); // 평점 만큼 네모 출력
					}
					printf("\n");
					}
				}
				printf("-----------------------------------\n");
				break;
			
			case 3:
				printf("프로그램 종료\n"); // 3을 입력하면 프로그램 종료
				break;
			
			default:
				printf("다시 입력하세요\n"); // 예외처리1
				break;
		}
		if(menu==3) // menu에 3이 입력되면 스위치문을 탈출 > 또 while문도 탈출 > 종료
			break;
	}

	return 0;
}