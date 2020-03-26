/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>

int sum(int num)
{
	if(num<=1){
		return 1; // 최종적으로 num값을 1씩빼주다가 1이 되었을때 1로 반환 => 함수반복 종료
	}
	else
		return num+sum(num-1);} //sum함수에 값 num+sum(num-1) 반환 = 반복
}

int main()
{
	int num;

	printf("1부터 n까지의 합 구하기\n");
	printf("n 입력 : ");
	scanf("%d", &num);
	printf("결과 : %d\n", sum(num)); // 함수 호출

    return 0;
}