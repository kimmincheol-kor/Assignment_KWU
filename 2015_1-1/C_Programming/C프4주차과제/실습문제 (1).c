/* C 프로그래밍
   4주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
    printf("char형의 크기 : %d바이트\n", sizeof(char)); // char자료형의크기출력
	
	printf("short형의 크기 : %d바이트\n", sizeof(short)); // short자료형의크기출력

	printf("int형의 크기 : %d바이트\n", sizeof(int)); // int자료형의크기출력
	
	printf("float형의 크기 : %d바이트\n", sizeof(float)); // float자료형의크기출력
	
	printf("double형의 크기 : %d바이트\n", sizeof(double)); // double자료형의크기출력
	
	printf("long형의 크기 : %d바이트\n", sizeof(long)); // long자료형의크기출력
	
	printf("long long형의 크기 : %d바이트\n", sizeof(long long)); // long long자료형의크기출력

	printf("long double형의 크기 : %d바이트\n", sizeof(long double)); // long double자료형의크기출력

	return 0;
}