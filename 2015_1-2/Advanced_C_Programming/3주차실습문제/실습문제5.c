// C 프로그래밍 3주차 실습문제5

#include <stdio.h>

void main()
{
	char *arr[5]={"apple","grape","banana","melon","orange"};
	int score[5]={0,};
	char ch;
	int i;

	for(i=0; i<5; i++)
	{
		printf("are you like %s <y/n>? ", arr[i]);
		scanf("%c", &ch);
		fflush(stdin); // ch 에 입력후 남아있는 엔터(버퍼) 제거

		if((ch!='y')&&(ch!='n')) // y 나 n을 입력한게 아니라면
		{
			while(1) // y나 n을 입력할때까지 반복.
			{
				printf("please type 'y' or 'n'\n");
				printf("are you like %s <y/n>? ", arr[i]);
				scanf("%c", &ch);
				fflush(stdin);
				
				if((ch=='y')||(ch=='n'))
					break;
			}

		}
		
		if(ch=='y') // y를 입력했다면 점수 입력
		{printf("point<1~5>: ");
		scanf("%d", &score[i]);
		fflush(stdin);

			while(1)
			{
				if((score[i]<1)||(score[i]>5)) // 입력한점수가 1~5가 아니라면 반복
					{printf("input error.<1~5>\n");
					printf("point<1~5>: ");
					scanf("%d", &score[i]);
					fflush(stdin);}
				else // 입력한점수가 1~5이면 while 문 종료
					break;


			}
		}
		else if(ch=='n')
			continue;
	}


	for(i=0; i<5; i++)
		if(score[i]!=0) printf("%s: %d\n", *(arr+i), score[i]); // 입력받은 점수들을 출력, 입력되지않았다면 출력 x


}