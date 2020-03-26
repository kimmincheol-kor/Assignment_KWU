/* C프로그래망 11주차 실습문제 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, ranNum, num=0;

	srand((unsigned)time(NULL)); // 입력된 값 마다 정해진 랜덤값이 있는데, time 값을 넣음으로써 계속해서 랜덤값이 바뀌므로 진짜랜덤값(?) 이된다.
	ranNum=rand()%10+1; // ranNum값은 1,2,3...9,10 중에서 결정된다, 10으로 나눈 나머지는 한자리 수(0~9)이며, 1을 더하면 1~10이 된다.

	do // 일단 실행
	{
		printf("Input <1~10>: ");
		scanf("%d", &num); //num값 입력

		if(num>ranNum)
			printf("random number는 %d보다 작습니다.\n", num);
		else if(num<ranNum)
			printf("random number는 %d보다 큽니다.\n", num);
		else if(num=ranNum)
			printf("random number는 %d입니다.\n", num);
	} while(num!=ranNum); // num이 ranNum 과 같으면 종료

		printf("\n");

		return 0;
}