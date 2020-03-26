/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>

int Sum(int mA, int mB);
double Average(int mA, int mB);
char Compare(int mA, int mB); // 함수 미리 선언

int main(void)
{
	int a, b;

	printf("정수 두 개 입력 : ");
	scanf("%d %d", &a, &b);
	printf(">> Sum : %d\n", Sum(a, b)); // Sum 함수 호출
	printf(">> Average : %.1f\n", Average(a, b)); // Average 함수 호출
	printf(">> Compare : %d %c %d\n", a, Compare(a, b), b); // Compare 함수 호출

	return 0;
}

int Sum(int mA, int mB) // 함수이름은 Sum
{
	return mA+mB; // mA+mB 값을 Sum을 호출한 영역으로 전달
} // sum 함수의 몸체

double Average(int mA, int mB)
{
	return ((double)mA+mB)/2; // 소수자리도 출력
}

char Compare(int mA, int mB)
{
	if((mA-mB)>0)
		return '>';
	if((mA-mB)==0) // 빼서 0 이면 같다는것
		return '=';
	if((mA-mB)<0)
		return '<';
}