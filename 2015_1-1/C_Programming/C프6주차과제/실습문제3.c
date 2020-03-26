/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int messi=2; //2단부터 시작
	int xabi;

    for(xabi=1; messi<=9; messi++) // 작은for에서 사비가 9까지 커지므로 다음단을 재실행하기위해서 9가된 사비를 1로 초기화; 9단까지하므로 메시는 9가 될때까지 반복; 2단후 3단후 4단... 하기위해서 1씩 더해줌
	{
	     printf("-------------------%d단\n", messi);

          for(xabi=1; xabi<=9; xabi++) // 메시는 큰for에서 1씩증가 = 단증가 ; 사비는 단x사비, 단x사비.. 이므로 1에서시작해서 9나올때까지 반복
		 {
		     printf("%d x %d = %d\n", messi, xabi, messi*xabi); // 메시 x 사비 
		 }
		 
     }

	return 0;
}