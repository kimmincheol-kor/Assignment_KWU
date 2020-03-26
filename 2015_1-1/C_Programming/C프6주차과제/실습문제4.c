/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int usa;
	int kor;

	printf("Input : ");
	scanf("%d", &usa);

	for(kor=1; usa>=1; usa--) 
	/*작은for에서 kor가 커지므로 다음줄에서 다시 별을 출력하기위해 다시 1로 초기화;
	usa는 별의개수를 의미한다 처음엔 입력한 숫자만큼, 다음은 1을뺀 별의개수, 마지막별의개수가 하나가되어야하므로 1보다크거나같으면 명령문실행.*/
	{
       
		for(kor=1; kor<=usa; kor++) // kor를 1로초기화시킨후 kor가 usa와 같아질때까지 kor가 1씩커지며 명령문실행 => usa만큼 별 출력
		{
		printf("*");
	    }
	
		printf("\n"); // 띄어쓰기

	}

	// 큰for는 새로운 줄을 반복. 작은 for는 별의 입력을 반복.

	return 0;
}