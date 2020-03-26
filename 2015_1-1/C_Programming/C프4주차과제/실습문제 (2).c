/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	
	long long int x;
	long long int y;
	long long int z; //크기가 8바이트고 정수값만 출력하는 롱롱 
	
	printf("학번을 입력하세요 : ");
	scanf("%lld", &x); // x에 학번 입력
	
	y=x*2; // 학번x2
	z=x*x; // 학번 제곱
	
	printf("학번 x 2 = %lld\n",y); // 학번x2 출력 %lld 는 롱롱을 출력, 부호있는 10진수 정수를 출력할때 쓰인다.
	
	printf("학번을 제곱한 결과 = %lld\n",z); // 학번제곱값 출력

	return 0;
}