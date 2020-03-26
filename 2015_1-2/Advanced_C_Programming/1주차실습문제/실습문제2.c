// C 프로그래밍 1주차 실습문제2

#include <stdio.h>

int main()
{
	int num;
	int i, j;

	printf("입력: ");
	scanf("%d", &num); // 높이를 num에 입력 받음

	for(i=0; i<num; i++) // 행
	{
		if(num%2!=0){ // 홀수!
			if(i<num/2+1){ // 첫줄~중간줄
		for(j=0; j<i; j++) // 첫번째 띄어쓰기
		{printf(" ");
			if(i==(num/2+1))
				break;}
		
		printf("*"); // 첫번째 별 입력
		
		if(num-2-(i*2)>0){ // ** 중간줄은 별 한개만 입력!!
		for(j=0; j<num-2-(i*2); j++)
		{printf(" ");} // 두번째 띄어쓰기
		printf("*");} // 두번째 별
		} // 상위탑 끝
			if(i>num/2){ // 아래쪽탑
			for(j=num-i; j>1; j--) // 첫번째 띄어쓰기.
			{printf(" ");}
			
			printf("*"); // 첫번째 별.

			for(j=2*i-num ;j>0; j--) // 두번째 띄어쓰기
			{printf(" ");}
		
			printf("*"); // 두번째 별
			
			
			} // 아래탑 끝

				} // 홀수 끝

		if(num%2==0){ // 짝수 !
			if(i<num/2){ //첫줄~중간
			for(j=i; j>0; j--)
			{printf(" ");} // 첫번째 띄어쓰기
			printf("*"); // 첫번째 별
			for(j=(num-2)-(2*i); j>0; j--) // 두번째 띄어쓰기
			{printf(" ");}
			printf("*"); // 두번째 별

			if(i==num/2)
				continue;

			} // 첫줄~중간 끝
			else if(num/2<i<num){ //중간~끝줄
				for(j=num-i; j>1; j--) //첫번째 띄어쓰기
				{printf(" ");}
				printf("*"); //첫번째 별

				for(j=(i*2)-num; j>0; j--) // 두번째 띄어쓰기
				{printf(" ");}
				printf("*"); // 두번째 별

			} // 중간~끝줄 끝
		} // 짝수 끝

		

		printf("\n");
	}
}