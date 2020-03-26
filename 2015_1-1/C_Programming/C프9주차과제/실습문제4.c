/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>

int main()
{
	int asd;
	
	printf("Input : ");
	scanf("%d", &asd); // asd 숫자 입력
	printf("Output : ");

	while(asd>0)
	{
		printf("%d", asd%10); // 10으로 나눈 나머지는 첫째자리 숫자
		asd/=10; // asd = asd/10 => 첫째자리숫자 제거 
	} // 첫째자리 숫자부터 출력. = 거꾸로 출력
	

	printf("\n");

	return 0;
}