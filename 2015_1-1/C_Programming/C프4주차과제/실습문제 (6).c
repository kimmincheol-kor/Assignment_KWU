/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int x,y,z;
	int sum; // 정수로 선언
	double avg; // 소수점 까지 선언
	
	printf("점수 : ");
	scanf("%d %d %d",&x,&y,&z); //점수 입력
	
	sum=x+y+z; // 총점 계산후 sum에 입력(정수) 
	avg=(double)sum/3; // 평균을 계산, double로출력(소수)
	
	printf("총점 : %d\n",sum); //총점출력
	printf("평균 : %.2f\n",avg);//평균을 소수둘째자리까지 출력

	return 0;
}